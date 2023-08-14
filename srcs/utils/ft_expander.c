/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expander(char *line)
{
	t_exp	*exp;
	//int		ktm;

	//ktm = 0;
	exp = ft_calloc(sizeof(t_exp), 1);
	line = exit_exp(line);
	/*if (strchr(line, '$') && !strchr(line, ' '))
	{
		exp->trim = ft_strtrim(line, "$\"");
		if (getenv(exp->trim))
			line = free_and_replace(line, ft_strdup(getenv(exp->trim)));
		else if (strchr(line, '\"') && strchr(line, '$') && strchr(line, '\''))
		{
			ktm = apex_exp(&exp, line);
			line = free_and_replace(line, exp->cmds[0]);
			free(exp->cmds);
		}
		free(exp->trim);
	}
	else if (strchr(line, '$') && strchr(line, ' '))
		line = multi_exp(&exp, line);
	if ((strchr(line, '\'') && ktm) || (strchr(line, '$') && strchr(line, ' ')))
		line = add_dapex(line, ft_strtrim(line, "\""));*/
	free(exp);
	return (line);
}