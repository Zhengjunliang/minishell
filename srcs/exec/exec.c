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

void	cmd_builder(t_mini **ms)
{
	int		i;

	ft_readifyouneed(&((*ms)->input), ms);
	(*ms)->cmd = ft_split1((*ms)->input);
	i = -1;
	while ((*ms)->cmd[++i])
		(*ms)->cmd[i] = ft_expander((*ms)->cmd[i]);
	(*ms)->list = lexer((*ms)->cmd);
	ft_trimlist((*ms)->list);  //cancellato i quotes ''""
	(*ms)->cmd_list = create_cmdlst((*ms)->list, *ms);
	if ((*ms)->cmd_list == NULL && (*ms)->hist)
		perror("Wrong syntax");
	if (g_exit == 1234)
		g_exit = 1;
	else
		exec_cmd(ms, (*ms)->cmd_list);
	free_cmd((*ms)->cmd_list);
	return ;
}

void	exec_cmd(t_mini **ms, t_cmd *cmd_list)
{
	if (!cmd_list)
		return ;
	if (ft_builtin(ms, cmd_list) == false)
		printf("Hello");
	(*ms)->pipe = 0;
}