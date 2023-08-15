/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:35:45 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/14 18:35:45 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_redir(t_cmd *cmd)
{
	if (ft_strncmp(cmd->cmds[0], "cd", 3))
	{
		if (cmd->out_fd != -1)
		{
			close(STDOUT_FILENO);
			dup2(cmd->out_fd, STDOUT_FILENO);
			close(cmd->out_fd);
		}
		if (cmd->in_fd != -1)
		{
			close(STDIN_FILENO);
			dup2(cmd->in_fd, STDIN_FILENO);
			close(cmd->in_fd);
		}
	}
}

void	close_redir(t_mini **ms, t_cmd *cmd)
{
	if (ft_strncmp(cmd->cmds[0], "cd", 3))
	{
		if (cmd->out_fd != -1)
			dup2((*ms)->stdout_fd, STDOUT_FILENO);
		if (cmd->in_fd != -1)
			dup2((*ms)->stdin_fd, STDIN_FILENO);
	}
}
