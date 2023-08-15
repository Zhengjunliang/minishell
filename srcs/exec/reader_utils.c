/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:35:25 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/14 18:35:26 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freejoin(char **origin, char **line)
{
	char	*tmp;

	if (!(*origin) || !(*line) || !line || !origin)
		return ;
	tmp = *origin;
	*origin = ft_strjoin(*origin, *line);
	if (tmp)
		free(tmp);
	if (*line)
		free(*line);
}

void	ft_addnl(char **origin)
{
	char	*tmp;
	char	*nl;

	nl = malloc(2);
	if (!nl)
		return ;
	nl[0] = '\n';
	nl[1] = '\0';
	tmp = *origin;
	*origin = ft_strjoin(*origin, nl);
	free(tmp);
	free(nl);
}

void	ft_promptpipe(char **origin)
{
	char	*line;
	char	*tmp;

	g_exit = 0;
	write(1, "pipe> ", 6);
	line = gnl(0);
	if (line && *line)
	{
		tmp = *origin;
		*origin = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
}

void	ft_count_quotes(char *s, int *dc, int *sc)
{
	*dc = 0;
	*sc = 0;
	if (!s || !(*s))
		return ;
	while (*s)
	{
		if (*s == '\'')
			(*sc)++;
		else if (*s == '\"')
			(*dc)++;
		s++;
	}
}

void	ft_search_last_n_scale(char **origin, char c)
{
	int		lstx;
	int		i;
	char	*tmp;

	lstx = -1;
	i = 0;
	if (!origin || !(*origin))
		return ;
	while (origin[0][i])
	{
		if (origin[0][i] == c)
			lstx = i;
		i++;
	}
	if (lstx > -1)
	{
		i = lstx - 1;
		while (origin[0][++i])
			origin[0][i] = origin[0][i + 1];
		tmp = ft_strdup(*origin);
		free(*origin);
		*origin = tmp;
	}
}
