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

t_sig	g_sig;

void	redir_and_exec(t_mini *mini, t_token *token)
{
	//t_token	*prev;
	//t_token	*next;

	//prev = prev_sep(token, NOSKIP);
	//next = next_sep(token, NOSKIP);


	exec_cmd(mini, token);
}

void	minishell(t_mini *mini)
{
	t_token	*token;
	int		status;

	token = next_run(mini->start, NOSKIP);
	while (mini->exit == 0 && token)
	{
		//mini->last = 1;
		redir_and_exec(mini, token);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		token = next_run(token, SKIP);
	}
}

int main(int ac, char **av, char **env)
{
	t_mini	mini;

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	mini.exit = 0;
	mini.ret = 0;
	env_init(&mini, env);
	while (mini.exit == 0)
	{
		sig_init();
		parse(&mini);
		if (mini.start != NULL)
			minishell(&mini);
		free_token(mini.start);
	}
	free_env(mini.env);
	return (mini.ret);
}
