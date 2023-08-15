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

static t_list	*ft_tabtolist(char **tab)
{
	int		i;
	t_list	*lst;

	i = 0;
	while (tab[i])
		i++;
	lst = ft_lstnew(tab[--i]);
	if (!lst)
		return (NULL);
	while (--i >= 0)
	{
		ft_lstadd_front(&lst, ft_lstnew(tab[i]));
		if (!lst)
			return (NULL);
	}
	return (lst);
}

t_list	*ft_createlist(char **tab)
{
	t_list	*lst;

	lst = ft_tabtolist(tab);
	if (!lst)
		return (NULL);
	if (tab)
		free(tab);
	return (lst);
}
/*
//"tokenizza" i segni "< > << >>"
int	tokenize_redir(t_list *tokens, char *line, int i, char *state)
{
	int	j;

	j = i;
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			add_tail(tokens, new_elem(line + (i++), 2, 2, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, 5, *state));
		i++;
	}
	else if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			add_tail(tokens, new_elem(line + (i++), 2, 6, *state));
		else
			add_tail(tokens, new_elem(line + (i), 1, 7, *state));
		i++;
	}
	return (i - j);
}

//viene chiamata a ogni carattere di line.  "tokenizza" la parte di line che ha caratteri dello stesso tipo
int	tokenize(t_list *tokens, char *line, int i, char *state)
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
			add_tail(tokens, new_elem(line + i, 1, -1, state));	// <---'
			i++;
		}
		else											//altrimenti sa che i prossimi caratteri saranno il nome di una variabile nell'ENVIRONMENT.
		i += get_env_var(tokens, line + i, *state);		//salta in avanti di tanti caratteri quanti sono quelli da cui e' composto il nome della variabile
	}
	else if (line[i] == '>' || line[i] == '<')
		i += tokenize_redir(tokens, line, i, state);
	else if (line[i] == '|')
		add_tail(tokens, new_elem(line + (i++), 1, 3, *state));
	else if (ft_isspace(line[i]))
		add_tail(tokens, new_elem(line + (i++), 1, 2, *state));
	return (i);
}*/

//la funzione lexer effettiva, riceve in input la linea ritornata da readline e restituisce una lista che la rappresenti nel formato dei token
t_list	*lexer(char **line)
{
	t_list	*tokens;

	tokens = ft_createlist(line);
	if (!tokens)
		return (NULL);
	return (tokens);
}
