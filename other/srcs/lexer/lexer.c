/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaibazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:20:47 by lgaibazz          #+#    #+#             */
/*   Updated: 2023/08/14 15:20:48 by lgaibazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//stampa un singolo token. USATA SOLO PER TESTARE!
void	print_node(t_elem *node)
{
	int	i;

	i = 0;
	printf("content: ");
	while (i < node->len)
		putchar(node->content[i++]);
	printf(", len: %i", node->len);
	printf(", state: %i", node->state);
	printf(", token: %i\n", node->type);
}

//stampa tutta la lista. USATA SOLO PER TESTARE!
void	print_list(t_list *list)
{
	t_elem	*node;

	node = list->head;
	while (node)
	{
		print_node(node);
		node = node->next;
	}
}

//"tokenizza" i segni "< > << >>"
int	tokenize_redir(t_list *tokens, char *line, int i, enum e_state *state)
{
	int	j;

	j = i;
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			add_tail(tokens, new_elem(line + (i++), 2, HERE_DOC, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, REDIR_IN, *state));
		i++;
	}
	else if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			add_tail(tokens, new_elem(line + (i++), 2, DREDIR_OUT, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, REDIR_OUT, *state));
		i++;
	}
	return (i - j);
}

//viene chiamata a ogni carattere di line.  "tokenizza" la parte di line che ha caratteri dello stesso tipo
int	tokenize(t_list *tokens, char *line, int i, enum e_state *state)
{
	if (!in_charset(line[i]))
		i += get_word(tokens, line + i, *state);		//salta in avanti di tanti caratteri quanti sono quelli da cui e' composta la parola
	else if (line[i] == '\'')
		quotes_state(tokens, line + (i++), state, 1);
	else if (line[i] == '\"')
		quotes_state(tokens, line + (i++), state, 2);
	else if (line[i] == '$')							//se trova il carattere '$' controlla qual e' il carattere successivo
	{
		if (in_charset(line[i + 1]) || line[i + 1] == '=')			//se il carattere successivo e' un meta-character allora tratta il '$'...
		{															//...come una normale parola di lunghezza 1
			add_tail(tokens, new_elem(line + i, 1, WORD, *state));	// <---'
			i++;
		}
		else											//altrimenti sa che i prossimi caratteri saranno il nome di una variabile nell'ENVIRONMENT.
		i += get_env_var(tokens, line + i, *state);		//salta in avanti di tanti caratteri quanti sono quelli da cui e' composto il nome della variabile
	}
	else if (line[i] == '>' || line[i] == '<')
		i += tokenize_redir(tokens, line, i, state);
	else if (line[i] == '|')
		add_tail(tokens, new_elem(line + (i++), 1, PIPE_LINE, *state));
	else if (ft_isspace(line[i]))
		add_tail(tokens, new_elem(line + (i++), 1, WHITE_SPACE, *state));
	return (i);
}

//la funzione lexer effettiva, riceve in input la linea ritornata da readline e restituisce una lista che la rappresenti nel formato dei token
t_list	*lexer(char *line)
{
	int				i;
	t_list			*tokens;
	enum e_state	state;					//mantiene un certo stato finche' non trova delle virgolette

	i = 0;
	state = GENERAL;
	tokens = NULL;
	tokens = init_list(tokens);
	if (tokens)
	{
		while (line[i])
		{
			i = tokenize(tokens, line, i, &state);
		}
	}
	//free(line);
	return (tokens);
}
