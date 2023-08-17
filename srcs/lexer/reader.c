/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:35:00 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/14 18:35:01 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_endread(char *c, char **line, char **origin)
{
	int	a;

	if (!line || !(*line))
		return (1);
	if (*c == '\'' || *c == '\"')
	{
		if (ft_chr(*line, *c))
		{
			a = 1;
			ft_search_last_n_scale(line, *c);
			ft_freejoin(origin, line);
		}
		else
			a = 0;
	}
	else if (!(ft_strncmp(c, *line, ft_sl(c)))
		&& (ft_sl(c) == (ft_sl(*line) - 1)))
	{
		a = 1;
		if (*line)
			free(*line);
	}
	else
		a = 0;
	return (a);
}

void	ft_reader(t_mini **ms, char **origin, char *prompt, char *c)
{
	char	*line;

	g_exit = 0;
	if (!ft_strncmp(c, "\'", ft_strlen(c)) || !ft_strncmp(c, "\"", ft_strlen(c)))
		ft_search_last_n_scale(origin, c[0]);
	while (g_exit != 130)
	{
		write(1, prompt, ft_strlen(prompt));
		line = gnl(0);
		if (line && *line)
		{
			if (ft_endread(c, &line, origin))
				break ;
			if (!ft_strncmp("heredoc> ", prompt, ft_sl(prompt)))
				ft_putinhdoc_n_free(ms, line);
			else
				ft_freejoin(origin, &line);
		}
		else
			break ;
	}
}

static void	ft_search_first(t_mini **ms, char **origin)
{
	int	i;

	i = 0;
	while (*origin[i])
	{
		if (*origin[i] == '\'')
		{
			ft_reader(ms, origin, "quote> ", "\'");
			break ;
		}
		else if (*origin[i] == '\"')
		{
			ft_reader(ms, origin, "dquote> ", "\"");
			break ;
		}
		i++;
	}
}

static int	handle_quotes(t_mini **ms, int dc, int sc, char **origin)
{
	if ((dc && dc % 2) || (sc && sc % 2))
		ft_addnl(origin);
	if (dc && dc % 2 != 0 && !(sc % 2))
		ft_reader(ms, origin, "dquote> ", "\"");
	else if (sc && sc % 2 != 0 && !(dc % 2))
		ft_reader(ms, origin, "quote> ", "\'");
	else if (dc && sc && (sc % 2) && (dc % 2))
		ft_search_first(ms, origin);
	else
		return (0);
	return (1);
}

void	read_input(char **origin, t_mini **ms)
{
	int		dc;
	int		sc;
	char	*sep;

	ft_count_quotes(*origin, &dc, &sc);
	if (handle_quotes(ms, dc, sc, origin))
		return ;
	else if (ft_strnstr(*origin, "<<", ft_sl(*origin))
		&& !is_in_quotes(*origin, "<<"))
	{
		sc = ft_strnstr(*origin, "<<", ft_strlen(*origin)) - *origin;
		if (ft_lts(&(origin[0][sc + 2 + ft_splen(&(origin[0][sc + 2]))])))
			sep = ft_substr(*origin, sc + 2 + ft_splen(&(origin[0][sc + 2])),
					ft_lts(&(origin[0][sc + 2
							+ ft_splen(&(origin[0][sc + 2]))])));
		else
			sep = NULL;
		ft_heredoc(ms, origin, sep, sc);
		(*ms)->hist = false;
	}
	else if (origin[0][ft_strlen(*origin) - 1] == '|')
		ft_promptpipe(origin);
}
