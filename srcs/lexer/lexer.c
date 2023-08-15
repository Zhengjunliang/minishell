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

//la funzione lexer effettiva, riceve in input la linea ritornata da readline e restituisce una lista che la rappresenti nel formato dei token
t_list	*lexer(char **line)
{
	t_list	*tokens;

	tokens = ft_createlist(line);
	if (!tokens)
		return (NULL);
	return (tokens);
}
