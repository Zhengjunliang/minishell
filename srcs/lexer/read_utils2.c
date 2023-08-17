/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:03:55 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/17 14:03:56 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*ft_sp(char *s)
{
	int	i;

	if (!s | !(*s))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != 32)
		i++;
	while (s[i] == 32)
		i++;
	if (s[i])
		return (&s[i]);
	return (NULL);
}

int	ft_lts(char *s)
{
	int	i;

	if (!s || !(*s))
		return (0);
	i = 0;
	while (s[i] && s[i] != 32)
		i++;
	return (i);
}

int	ft_splen(char *s)
{
	int	i;

	if (!s || !(*s))
		return (0);
	i = 0;
	while (s[i] && s[i] == 32)
		i++;
	return (i);
}

void	ft_heredoc(char **origin, char *sep, int till_sep)
{
	char	*start;
	char	*end;

	if (!sep || !(*sep))
		return ((void)(printf("heredoc: wrog syntax\n")));
	start = ft_substr(*origin, 0, till_sep + 2);
	end = ft_sp(*origin + till_sep + 2 + ft_strlen(sep));
	if (end)
		end = ft_strdup(ft_sp(*origin + till_sep + 2 + ft_strlen(sep)));
	ft_reader(&start, "heredoc> ", sep);
	free(*origin);
	if (end)
	{
		*origin = end;
		end = ft_strjoin(" ", end);
		free(*origin);
		*origin = ft_strjoin(start, end);
		free(end);
		free(start);
	}
	else
		*origin = start;
	free(sep);
}
