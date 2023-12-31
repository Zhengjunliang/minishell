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

int	g_exit;

static int	check_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] > 33 && s[i] != 127)
			return (1);
	}
	return (0);
}

void	minishell_loop(t_mini *mini)
{
	if (check_input(mini->input))
		parse(&mini);
	if (ft_strlen(mini->input) != 0 && mini->hist == true)
		add_history(mini->input);
	free(mini->input);
}

int	main(int ac, char **av, char **envp)
{
	t_mini	*mini;

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	init(&mini, envp);
	while (1)
	{
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
		mini->hist = true;
		mini->input = readline(mini->prompt);
		mini->exit = ft_exit(&mini);
		if (mini->exit == 1)
			break ;
		minishell_loop(mini);
	}
	rl_clear_history();
	free_all(&mini);
	exit (EXIT_SUCCESS);
}
