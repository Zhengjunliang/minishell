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
int	g_exit;

void	set_env(t_mini **mini, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	(*mini)->env = ft_calloc(sizeof(char *), (i + 1));
	i = -1;
	while (envp[i++])
		(*mini)->env[i] = ft_strdup(envp[i]);
}

void	init_mini(t_mini **mini, char **envp)
{
	g_exit = 0;
	(*mini)->exit = 0;
	*mini = ft_calloc(sizeof(t_mini), 1);
	//(*mini)->prompt = ft_strjoin("\033[0;36m", getenv("USER"));
	//(*mini)->prompt = ft_strjoin2((*mini)->prompt, "@minishell: \033[0;37m");
	set_env(mini, envp);
}

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

int main(int ac, char **av, char **envp)
{
	t_mini	*mini;

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	init_mini(&mini, envp);
	while (mini->exit == 0)
	{
		sig_init();
		//mini->input = readline(mini->prompt);
		parse(mini);
		if (mini->start != NULL)
			minishell(mini);
		free_token(mini->start);
		free(mini->input);
	}
	exit (EXIT_SUCCESS);
}
