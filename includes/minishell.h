/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:48:21 by juzheng           #+#    #+#             */
/*   Updated: 2023/06/21 14:48:22 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdbool.h>

extern int	g_exit;

typedef struct s_cmd
{
	char			**cmds;
	char			*cmd;
	struct s_cmd	*next;	
}				t_cmd;

typedef struct s_mini
{
	char			*input;
	char			**env;
	char			*prompt;
	char			**cmd;
	bool			hist;
	t_cmd			*cmd_list;
	t_list			*list;
	int				exit;
}				t_mini;

/*
** ENV
*/
void	ft_env(t_mini **mini);

/*
** BUILTINS
*/
bool	ft_builtin(t_mini **ms, t_cmd **cmd);
int	ft_echo(char **args);
int	ft_pwd(void);

/*
** EXEC
*/
void	cmd_builder(t_mini **ms);

/*
** FREE
*/
void	free_all(t_mini **ms);
void	free_cmd(t_cmd *cmd);

/*
**UTILS
*/
void	ft_skip_space(char *s, int *i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_countwords1(char *s);
/*
**SIGNAL
*/
void	sig_int(int code);

#endif
