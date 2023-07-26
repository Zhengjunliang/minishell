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

# define STDIN 0
# define STDOUT 1

# define SKIP 1
# define NOSKIP 0

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_mini
{
	t_token			*start;
	t_env			*env;
	t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				last;
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
int	env_init(t_mini *mini, char **env_array);
int	secret_env_init(t_mini *mini, char **env_array);

/*
** BUILTINS
*/
void	mini_exit(t_mini *mini, char **cmd);
int	is_builtin(char *cmd);
int	exec_builtin(char **args, t_mini *mini);
int	ft_echo(char **args);
int	ft_pwd(void);
int	ft_env(t_env *env);
int	ft_cd(char **args, t_env *env);
int	ft_export(char **args, t_env *env);

/*
** EXEC
*/
void	exec_cmd(t_mini *mini, t_token *token);

/*
** FD
*/
void	redir(t_mini *mini, t_token *token, int type);
void	ft_close(int fd);
void	reset_std(t_mini *mini);
void	close_fds(t_mini *mini);
void	reset_fds(t_mini *mini);

/*
** FREE
*/
void	free_token(t_token *start);
void	free_env(t_env *env);
void	free_tab(char **tab);

/*
**SIGNAL
*/
void	sig_init(void);
void	sig_int(int code);
void	sig_quit(int code);

extern t_sig g_sig;
#endif
