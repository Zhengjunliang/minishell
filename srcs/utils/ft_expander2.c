/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exit_exp(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	if (ft_strchr(line, '$'))
	{
		while (line[++i])
		{
			if (line[i] == '$' && line[i + 1] == '?')
			{
				tmp = exit_exp2(line, i);
				free(line);
				return (tmp);
			}
		}
	}
	return (line);
}