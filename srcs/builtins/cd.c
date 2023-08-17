/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:38:41 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/24 12:38:45 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_mini **ms, t_cmd *cmd)
{
	if ((*ms)->pipe == 0)
	{
		if (!cmd->cmds[1])
		{
			g_exit = 0;
			chdir(getenv("HOME"));
		}
		else if (cmd->cmds[2])
		{
			g_exit = 1;
			write(STDERR_FILENO, "cd : Too many arguments\n", 25);
		}
		else if (chdir(cmd->cmds[1]) != 0)
		{
			g_exit = 1;
			return (perror("cd"));
		}
		else
			g_exit = 0;
	}
}
