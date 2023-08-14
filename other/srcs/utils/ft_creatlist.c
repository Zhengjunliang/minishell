/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static t_list	*ft_tabtolist(char **tab)
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
}*/