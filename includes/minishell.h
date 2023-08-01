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

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define SKIP 1
# define NOSKIP 0

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_mini
{
	t_token			*start;
	char			*input;
	char			**env;
	char			*prompt;
	int				ret;
	int				exit;
}				t_mini;

typedef struct s_sig
{
	int			sigint;
	int			sigquit;
	int			exit_status;
	pid_t		pid;
}				t_sig;

/*
** PARSING	
*/
void	parse(t_mini *mini);
int		quotes(char *line, int index);
t_token	*get_tokens(char *line);

t_token	*next_sep(t_token *token, int skip);
t_token	*prev_sep(t_token *token, int skip);
t_token	*next_run(t_token *token, int skip);
int	is_sep(char *line, int i);
int	ignore_sep(char *line, int i);

void	type_arg(t_token *token, int separator);
int	is_type(t_token *token, int type);

/*
** ENV
*/
void	ft_env(t_mini **mini);

/*
** BUILTINS
*/
void	mini_exit(t_mini *mini, char **cmd);
int	is_builtin(char *cmd);
int	exec_builtin(char **args, t_mini *mini);
int	ft_echo(char **args);
int	ft_pwd(void);

/*
** EXEC
*/
void	exec_cmd(t_mini *mini, t_token *token);

/*
** FREE
*/
void	free_token(t_token *start);
void	free_tab(char **tab);

/*
**SIGNAL
*/
void	sig_init(void);
void	sig_int(int code);
void	sig_quit(int code);

extern t_sig g_sig;
extern int	g_exit;
#endif
