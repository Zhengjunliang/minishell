/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:43:16 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/18 15:43:20 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_mini **ms)
{
	int	i;

	i = -1;
	while ((*ms)->env[++i])
		free((*ms)->env[i]);
	i = -1;
	while ((*ms)->path[++i])
		free((*ms)->path[i]);
	free((*ms)->path);
	free((*ms)->prompt);
	free((*ms)->input);
	free((*ms)->env);
	free(*ms);
}

void	free_for_all2(t_mini **ms)
{
	int	i;

	i = -1;
	while ((*ms)->env[++i])
		free((*ms)->env[i]);
	i = -1;
	while ((*ms)->path[++i])
		free((*ms)->path[i]);
	free((*ms)->path);
	free((*ms)->prompt);
	free((*ms)->input);
	free((*ms)->env);
	free_cmd((*ms)->cmd_list);
	free(*ms);
}

void	free_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp;

	while (cmd)
	{
		if (cmd->cmd != NULL)
			free(cmd->cmd);
		i = -1;
		while (cmd->cmds[++i])
			free(cmd->cmds[i]);
		free(cmd->cmds);
		tmp = cmd->next;
		free(cmd);
		cmd = tmp;
	}
}

char	*free_and_replace(char	*line, char	*dup)
{
	free(line);
	return (dup);
}
