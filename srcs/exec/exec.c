/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:12:27 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/18 16:12:28 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_tab(t_token *start)
{
	t_token	*token;
	char	**tab;
	int		i;

	if (!start)
		return (NULL);
	token = start->next;
	i = 2;
	while (token)
	{
		token = token->next;
		i++;
	}
	if (!(tab = malloc(sizeof(char *) * 1)))
		return (NULL);
	token = start->next;
	tab[0] = start->str;
	i = 1;
	while (token)
	{
		tab[i++] = token->str;
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}

void	exec_cmd(t_mini *mini, t_token *token)
{
	char	**cmd;
	int		i;

	mini->ret = 1;
	cmd = cmd_tab(token);
	i = 0;
	while (cmd && cmd[i])
	{
		ft_putendl_fd(cmd[i], 2);
		i++;
	}
	if (cmd && ft_strcmp(cmd[0], "exit") == 0)
		mini_exit(mini, cmd);
}
