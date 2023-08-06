/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:51:43 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/22 16:51:44 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (cmd->cmds[i])
	{
		while (cmd->cmds[++i])
		{
			if (!ft_strncmp(cmd->cmds[1], "-n", 2))
			{
				flag = 1;
				i++;
			}
			if (cmd->cmds[i + 1])
				printf("%s ", cmd->cmds[i]);
			else
				printf("%s", cmd->cmds[i]);
		}
		if (flag == 0)
			printf("\n");
	}
	g_exit = 0;
}
