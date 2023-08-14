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

bool	ft_builtin(t_mini **ms, t_list *cmd)
{
	if (!cmd)
		return (false);
	else if (!ft_strncmp(cmd->head->content, "pwd", 4))
		ft_pwd(ms);
	else if (!ft_strncmp(cmd->head->content, "cd", 3))
		ft_cd(ms, cmd);
	else if (!ft_strncmp(cmd->head->content, "env", 4))
		ft_env(ms);
	/*else if (!ft_strncmp(cmd->head->content, "export", 6))
		ft_export(ms, cmd);
	else if (!ft_strncmp(cmd->head->content, "unset", 5))
		ft_unset(ms, cmd);
	else if (!ft_strncmp(cmd->head->content, "echo", 4))
		ft_echo(cmd);*/
	else
		return (false);
	return (true);
}