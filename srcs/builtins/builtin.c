/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:44:53 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/22 16:44:54 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_builtin(t_mini **ms, t_cmd *cmd)
{
	if (!cmd->cmds[0])
		return (false);
	else if (!ft_strncmp(cmd->cmds[0], "pwd", 4))
		ft_pwd();
	//else if (!ft_strncmp(cmd->cmds[0], "clear", 6))
		//ft_clear();
	//else if (!ft_strncmp(cmd->cmds[0], "cd", 3))
		//ft_cd(ms, cmd);
	else if (!ft_strncmp(cmd->cmds[0], "env", 4))
		ft_env(ms);
	//else if (!ft_strncmp(cmd->cmds[0], "export", 6))
		//ft_export(ms, cmd);
	//else if (!ft_strncmp(cmd->cmds[0], "unset", 5))
		//ft_unset(ms, cmd);
	//else if (!ft_strncmp(cmd->cmds[0], "echo", 4))
		//ft_echo(cmd);
	else
		return (false);
	return (true);
}