/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:17:23 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/24 12:17:26 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_input(t_cmd *cmd)
{
	int	i;

	i = 0;
	g_exit = 0;
	if (ft_isdigit(cmd->cmds[1][i]) || cmd->cmds[1][i] == '=')
	{
		write(STDERR_FILENO, "Export: Not valid identifier\n", 30);
		return (g_exit = 1);
	}
	while (cmd->cmds[1][i] && cmd->cmds[1][i] != '=')
	{
		if (!ft_isdigit(cmd->cmds[1][i]) && !ft_isalpha(cmd->cmds[1][i]))
		{
			write(STDERR_FILENO, "Export: Not valid identifier\n", 30);
			return (g_exit = 1);
		}
		i++;
	}
	if (!cmd->cmds[1][i] || cmd->cmds[1][i] != '=')
		return (1);
	i++;
	if (!cmd->cmds[1][i])
		return (1);
	return (0);
}

void	ft_env(t_mini **mini)
{
	int	i;

	i = -1;
	while ((*mini)->env[++i])
		printf("%s\n", (*mini)->env[i]);
	g_exit = 0;
}

void	ft_export(t_mini **ms, t_cmd *cmd)
{
	char	**new_env;
	int		i;

	i = 0;
	if (cmd->cmds[1] && !check_input(cmd))
	{
		while ((*ms)->env[i])
			i++;
		new_env = ft_calloc(sizeof(char *), (i + 2));
		i = -1;
		while ((*ms)->env[++i])
			new_env[i] = (*ms)->env[i];
		new_env[i] = ft_strdup(cmd->cmds[1]);
		free((*ms)->env);
		(*ms)->env = new_env;
	}
	else if (!(cmd->cmds[1]))
	{
		i = -1;
		while ((*ms)->env[++i])
			printf("declare -x %s\n", (*ms)->env[i]);
	}
	g_exit = 0;
}

void	ft_unset(t_mini **ms, t_cmd *cmd)
{
	int		i;
	int		j;
	int		pos;

	i = -1;
	j = 0;
	if (!cmd->cmds[1])
		return ;
	while ((*ms)->env[++i])
		if (!ft_strncmp((*ms)->env[i], cmd->cmds[1], ft_strlen(cmd->cmds[1])))
			break ;
	pos = i;
	if (!(*ms)->env[i])
		return ;
	while ((*ms)->env[i])
		i++;
	(*ms)->new_env = ft_calloc(sizeof(char *), i);
	i = -1;
	while ((*ms)->env[++i])
		if (i != pos)
			(*ms)->new_env[j++] = (*ms)->env[i];
	free((*ms)->env[pos]);
	free((*ms)->env);
	(*ms)->env = (*ms)->new_env;
	g_exit = 0;
}
