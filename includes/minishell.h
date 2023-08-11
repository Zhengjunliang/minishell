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

typedef struct s_exp {
	char	**cmds;
	char	*var;
	char	*ret;
	char	*trim;
}				t_exp;

typedef struct s_mini
{
	char			*input;
	char			**env;
	char			**new_env;
	char		*pwd;
	char		**path;
	char			*prompt;
	char			**cmd;
	bool			hist;
	int				pipe;
	t_cmd			*cmd_list;
	t_list			*list;
	int				exit;
}				t_mini;

/*
** ENV
*/
void	ft_env(t_mini **mini);
void	ft_export(t_mini **ms, t_cmd *cmd);
void	ft_unset(t_mini **ms, t_cmd *cmd);

/*
** BUILTINS
*/
bool	ft_builtin(t_mini **ms, t_cmd *cmd);
void	ft_echo(t_cmd *cmd);
void	ft_pwd(t_mini **ms);
void	ft_cd(t_mini **ms, t_cmd *cmd);
int	ft_exit(t_mini **mini);
t_cmd	*create_cmdlst(t_list	*lst, t_mini *ms);
/*
** EXEC
*/
void	cmd_builder(t_mini **ms);
void	exec_cmd(t_mini **ms, t_cmd *cmd_list);

/*
** FREE
*/
void	free_all(t_mini **ms);
void	free_cmd(t_cmd *cmd);

/*
**UTILS
*/
void	ft_skip_space(char *s, int *i);
char	**ft_split1(char *s);
void	ft_close_quote(char *s, int *i, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_countwords1(char *s);
t_list	*ft_subsplit(char **tab);
t_list	*ft_createlist(char **tab);
void	ft_trimlist(t_list	*lst);
char	*ft_expander(char *line);
/*
**SIGNAL
*/
void	sig_int(int code);
void	ft_perrex(char *s);

#endif
