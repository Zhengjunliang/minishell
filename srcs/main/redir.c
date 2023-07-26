/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:15:35 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/26 16:15:36 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	redir(t_mini *mini, t_token *token, int type)
{
	ft_close(mini->fdout);
	if (type == TRUNC)
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (mini->fdout == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		mini->ret = 1;
		return ;
	}
	dup2(mini->fdout, STDOUT);
}
