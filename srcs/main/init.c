/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:40:47 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/16 15:40:48 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_mini **mini, char **envp)
{
	int	i;

	i = -1;
	(*mini)->path = ft_split(getenv("PATH"), ':');
	while ((*mini)->path[++i])
		(*mini)->path[i] = ft_strjoin2((*mini)->path[i], "/");
	i = 0;
	while (envp[i])
		i++;
	(*mini)->env = ft_calloc(sizeof(char *), (i + 1));
	i = -1;
	while (envp[++i])
		(*mini)->env[i] = ft_strdup(envp[i]);
}

void	init(t_mini **mini, char **envp)
{
	g_exit = 0;
	*mini = ft_calloc(sizeof(t_mini), 1);
	(*mini)->prompt = ft_strjoin("\033[0;36m", "minishell");
	(*mini)->prompt = ft_strjoin2((*mini)->prompt, "$ \033[0;37m");
	(*mini)->stdin_fd = dup(STDIN_FILENO);
	(*mini)->stdout_fd = dup(STDOUT_FILENO);
	set_env(mini, envp);
}