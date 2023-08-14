/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaibazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:21:06 by lgaibazz          #+#    #+#             */
/*   Updated: 2023/08/14 15:21:07 by lgaibazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ritorna 1 se il char argomento e' uno "spazio"
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

//ritorna 1 se il char argomento e' uno "spazio" o un meta-character (o NULL)
int	in_charset(char c)
{
	return (c == '\'' || c == '\"' || c == '<' || c == '>' || c == '|'
		|| c == '$' || ft_isspace(c) || c == '\0');
}

//controlla qual e' la lunghezza della parola attuale partendo dal suo primo carattere (puntato da str)
//subito dopo lo trasforma in un nuovo elemento con new_elem e lo aggiunge in fondo alla lista, con add_tail
int	get_word(t_list *tokens, char *str, enum e_state state)
{																
	int	i;

	i = 0;
	while (!in_charset(str[i]))
		i++;
	add_tail(tokens, new_elem(str, i, WORD, state));
	return (i);
}

//cerca una variabile nell'ENVIRONMENT, viene chiamata quando trova il carattere '$' mentre sta percorrendo line
int	get_env_var(t_list *tokens, char *str, enum e_state state)
{
	int	i;

	i = 1;
	if (str[i] == '?' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	else
		while (ft_isalphanum(str[i]) && str[i] != '\n' && str[i] != '\0')
			i++;
	add_tail(tokens, new_elem(str, i, ENV, state));
	return (i);
}

//cambia lo stato del token da GENERAL a IN_QUOTE (o IN_DQUOTE) o viceversa, a seconda di quale stato avesse prima che la funzione venisse chiamata
void	quotes_state(t_list *tokens, char *str, enum e_state *state, int flag)
{
	enum e_state	e_state;
	enum e_token	e_type;

	if (flag == 1)
	{
		e_state = IN_QUOTE;
		e_type = QOUTE;
	}
	else
	{
		e_state = IN_DQUOTE;
		e_type = DOUBLE_QUOTE;
	}
	if (*state == GENERAL)
	{
		add_tail(tokens, new_elem(str, 1, e_type, *state));
		*state = e_state;
	}
	else if (*state == e_state)
	{
		*state = GENERAL;
		add_tail(tokens, new_elem(str, 1, e_type, *state));
	}
	else
		add_tail(tokens, new_elem(str, 1, e_type, *state));
}

