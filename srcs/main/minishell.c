/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:49:28 by juzheng           #+#    #+#             */
/*   Updated: 2023/06/21 14:49:29 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_and_exec(t_mini *mini, t_token *token)
{
	exec_cmd(mini, token);

}

void	minishell(t_mini *mini)
{
	t_token	*token;
	int		status;

	status = 0;
	token = next_run(mini->start, 0);
	while ((mini->exit == 0 && token) && status == 0)
	{
		redir_and_exec(mini, token);
		status = 1;
	}
}

int main(int ac, char **av, char **env)
{
	t_mini	mini;

	(void)ac;
	(void)av;
	mini.exit = 0;
	mini.ret = 0;
	env_init(&mini, env);
	while (mini.exit == 0)
	{
		parse(&mini);
		if (mini.start != NULL)
			minishell(&mini);
		free_token(mini.start);
	}
	free_env(mini.env);
	return (mini.ret);
}
