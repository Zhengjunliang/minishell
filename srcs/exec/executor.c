/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:07:05 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/15 17:07:05 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_mini **ms, t_cmd *cmd)
{
	struct stat	info;

	if (!stat(cmd->cmds[0], &info) && (S_ISDIR(info.st_mode)))
	{
		g_exit = 126;
		printf("zsh: %s: Is a directory\n", cmd->cmds[0]);
		free_for_all2(ms);
		exit(g_exit);
	}
	//if ((cmd->out_fd != -1 || cmd->in_fd != -1))
	//	open_redir(cmd);
	//if (cmd->cmd && (*ms)->hist == false)
		//exec_here(ms, cmd);
	//else if (!cmd->cmd && (*ms)->hist)
		//custom_exec(ms, cmd);
	else if (cmd && (*ms)->hist)
	{
		execve(cmd->cmd, cmd->cmds, (*ms)->env);
		perror("zsh");
	}
	//close_redir(ms, cmd);
	free_for_all2(ms);
	exit(EXIT_FAILURE);
}
