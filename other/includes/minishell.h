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

enum e_token			//lista dei possibili valori assegnabili ad un elemento della lista. Descrive la natura di un token (se e' una parola, un gruppo di spazi, un meta-character, ecc...)
{
	WORD = -1,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QOUTE = '\'',
	DOUBLE_QUOTE = '\"',
	ESCAPE = '\\',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
	_NULL = '0',
};

enum e_state			//lista dei possibili stati di un token
{
	IN_DQUOTE,			//compreso tra virgolette doppie   (""). Escluse le virgolette a cui sta facendo riferimento
	IN_QUOTE,			//compreso tra virgolette singole  (''). Escluse le virgolette a cui sta facendo riferimento
	GENERAL,			//fuori dalle virgolette. LE VIRGOLETTE VERE E PROPRIE HANNO QUESTO STATO, per cui iniziamo sempre a leggere con GENERAL settato come standard 
};

typedef struct s_elem		//tipo di variabile per un singolo elemento della lista, rappresenta un token
{
	char			*content;		//putnatore al primo carattere del token
	int				len;		//lunghezza del token
	enum e_token	type;				//guarda definizione piu' in alto!
	enum e_state	state;				//guarda definizione piu' in alto!
	struct s_elem		*next;			//puntatore all'elemento successivo
	struct s_elem			*prev;			//puntatore all'elemento precedente
}	t_elem;

typedef struct s_list		//tipo di variabile per l'intera lista (verra' restituito dalla funzione lexer), rappresenta la linea di comando ricevuta con readline ma adattata per il parsing
{
	t_elem	*head;			//il primo elemento della lista
	t_elem	*tail;			//l'ultimo elemento della lista
	int		size;		//lunghezza della lista (da quanti token e' composta)
}	t_list;

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
** LEXER
*/
t_list			*lexer(char *line);
void			print_list(t_list *list);				// <----DA RIMUOVERE FINITO IL PROGETTO!!! Serve solo per i test manuali!!!!!!!!!
int				tokenize(t_list *tokens, char *line, int i,
					enum e_state *state);
int				tokenize_redir(t_list *tokens, char *line, int i,
					enum e_state *state);
int				is_empty(t_list *list);
t_list			*init_list(t_list *list);
t_elem			*new_elem(char *content, int len,
					enum e_token type, enum e_state state);
void			add_tail(t_list *list, t_elem *new);
void			free_list(t_list *list);
int				ft_isspace(char c);
int				in_charset(char c);
int				get_word(t_list *tokens, char *str, enum e_state state);
int				get_env_var(t_list *tokens, char *str, enum e_state state);
void			quotes_state(t_list *tokens, char *str,
					enum e_state *state, int flag);

/*
** ENV
*/
void	ft_env(t_mini **mini);
void	ft_export(t_mini **ms, t_cmd *cmd);
void	ft_unset(t_mini **ms, t_cmd *cmd);

/*
** BUILTINS
*/
bool	ft_builtin(t_mini **ms, t_list *cmd);
void	ft_echo(t_list *cmd);
void	ft_pwd(t_mini **ms);
void	ft_cd(t_mini **ms, t_list *cmd);
int	ft_exit(t_mini **mini);
t_cmd	*create_cmdlst(t_list	*lst, t_mini *ms);
/*
** EXEC
*/
void	cmd_builder(t_mini **ms);
void	exec_cmd(t_mini **ms, t_list *list);

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
char	*exit_exp(char *line);
/*
**SIGNAL
*/
void	sig_int(int code);
void	ft_perrex(char *s);

#endif
