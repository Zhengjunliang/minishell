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
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef HERED
#  define HERED "Src/.obj/.heredoc"
# endif

extern int	g_exit;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_cmd
{
	char			**cmds;
	char			*cmd;
	int				in_fd;
	int				out_fd;
	struct s_cmd	*next;	
}		t_cmd;

typedef struct s_exp {
	char	**cmds;
	char	*var;
	char	*ret;
	char	*trim;
}		t_exp;

typedef struct s_mini
{
	char	*input;
	char	**env;
	char	**new_env;
	char	*pwd;
	char	**path;
	char	*prompt;
	char	**cmd;
	pid_t	pid;
	bool	hist;
	int		fd;
	int		stdin_fd;
	int		stdout_fd;
	int		pipe;
	t_cmd	*cmd_list;
	t_list	*list;
	int		exit;
}		t_mini;

/*
** INIT
*/
void	init(t_mini **mini, char **envp);

/*
** ENV
*/
void	ft_env(t_mini **mini);
void	ft_export(t_mini **ms, t_cmd *cmd);
void	ft_unset(t_mini **ms, t_cmd *cmd);

/*
** LEXER
*/
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*lexer(char **line);
void	clc_freelist(t_cmd *head, t_list **lsthead);
/*
** BUILTINS
*/
bool	ft_builtin(t_mini **ms, t_cmd *cmd);
void	ft_echo(t_cmd *cmd);
void	ft_pwd(t_mini **ms);
void	ft_cd(t_mini **ms, t_cmd *cmd);
int		ft_exit(t_mini **mini);
t_cmd	*create_cmdlst(t_list	*lst, t_mini *ms);
void	open_redir(t_cmd *cmd);
void	close_redir(t_mini **ms, t_cmd *cmd);

t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmd_addback(t_cmd **cmd, t_cmd *new);
t_cmd	*ft_cmdnew(t_list **lst, char **path);
void	init_cmdlst(t_cmd **cmdlst, t_cmd **head, t_list **lst, t_mini *ms);

/*
** READER
*/
void	read_input(char **origin, t_mini **ms);
void	ft_count_quotes(char *s, int *dc, int *sc);
int		ft_sl(const char *s);
int		is_in_quotes(char *origin, char *ob);
int		ft_lts(char *s);
int		ft_splen(char *s);
void	ft_heredoc(t_mini **ms, char **origin, char *sep, int till_sep);
void	ft_promptpipe(char **origin);
void	ft_addnl(char **origin);
char	*ft_getenv(t_mini **ms, char *line);
void	ft_reader(t_mini **ms, char **origin, char *prompt, char *c);
/*
** EXEC
*/
void	parse(t_mini **ms);
void	exec_cmd(t_mini **ms, t_cmd *cmd_list);
void	ft_search_last_n_scale(char **origin, char c);
void	ft_freejoin(char **origin, char **line);
char	*gnl(int fd);
void	executor(t_mini **ms, t_cmd *cmd);

/*
** FREE
*/
void	free_all(t_mini **ms);
void	free_for_all2(t_mini **ms);
void	free_cmd(t_cmd *cmd);
char	*free_and_replace(char	*line, char	*dup);

/*
**UTILS
*/
void	ft_skip_space(char *s, int *i);
char	**ft_split1(char *s);
void	ft_close_quote(char *s, int *i, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_countwords1(char *s);
void	ft_trimlist(t_list	*lst);
char	*ft_expander(t_mini **ms, char *line);
char	*exit_exp(char *line);
int		content_is(t_list *lst, const char *s);
void	lst_freecont_n_skip(t_list **lst);
char	*ft_strjoin3(char *s1, char *s2, int flag);
char	*add_dapex(char	*line, char	*trim);
void	ft_putinhdoc_n_free(t_mini **ms, char *line);

/*
**SIGNAL
*/
void	sig_int(int code);
void	ft_perrex(char *s);
void	prnt_ctrl(int sig);

#endif
