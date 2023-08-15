/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sl(const char *s)
{
	int	i;

	if (!s || !(*s))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	content_is(t_list *lst, const char *s)
{
	if (!(ft_strncmp((char *)((lst)->content), s,
			ft_sl((char *)((lst)->content)))))
		return (1);
	else
		return (0);
}

void	lst_freecont_n_skip(t_list **lst)
{
	free((*lst)->content);
	*lst = (*lst)->next;
}