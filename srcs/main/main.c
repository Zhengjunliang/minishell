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

void	init_mini(t_mini **mini, char **envp)
{
	g_exit = 0;
	*mini = ft_calloc(sizeof(t_mini), 1);
	(*mini)->prompt = ft_strjoin("\033[0;36m", "minishell");
	(*mini)->prompt = ft_strjoin2((*mini)->prompt, "$ \033[0;37m");
	set_env(mini, envp);
}

static int	is_valid_input(char *s)
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

int	check_exit(t_mini **mini)
{
	if (!(*mini)->input)
	{
		printf("exit\n");
		return (1);
	}
	if (!ft_strncmp((*mini)->input, "exit", 4))
	{
		if (!ft_strncmp((*mini)->input, "exit ", 5))
		{
			//ft_exit(mini);
			return (2);
		}
		else
		{
			printf("exit\n");
			return (1);
		}
		free((*mini)->input);
	}
	return (0);
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
	while (1)
	{
		signal(SIGINT, sig_int); // Control -C
		signal(SIGQUIT, SIG_IGN); // Control -"\"
		mini->hist = true;
		mini->input = readline(mini->prompt);
		mini->exit = check_exit(&mini);
		if (mini->exit == 1)
			break ;
		if (is_valid_input(mini->input))
			cmd_builder(&mini);
		if (ft_strlen(mini->input) != 0 && mini->hist == true)
			add_history(mini->input);
		free(mini->input);
	}
	rl_clear_history();
	free_all(&mini);
	exit (EXIT_SUCCESS);
}
