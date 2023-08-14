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

t_list	*ft_subsplit(char **tab)
{
	t_list	*args;

	args = ft_createlist(tab);
	if (!args)
		return (NULL);
	return (args);
}