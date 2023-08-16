/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:56:23 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/14 18:56:27 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_addone(char *s, int size)
{
	char	*new;

	if (!s || !(*s) || size < 0)
		return (NULL);
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = s[size];
	if (s)
		free(s);
	return (new);
}

static void	*ft_free(char *buf)
{
	if (buf)
		free(buf);
	return (NULL);
}

char	*gnl(int fd)
{
	int		i;
	char	*buf;
	int		rd;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	i = 0;
	buf = malloc(1);
	if (!buf)
		return (NULL);
	while (1)
	{
		if (g_exit == 130)
			return (ft_free(buf));
		rd = read(fd, &buf[i], 1);
		if (rd <= 0 || buf[i] == '\n')
			break ;
		buf = ft_addone(buf, i + 1);
		i++;
	}
	if (rd <= 0)
		return (ft_free(buf));
	buf = ft_addone(buf, i + 1);
	return (buf);
}

char	*ft_strjoin3(char *s1, char *s2, int flag)
{
	char	*str;
	int		len;
	int		i;
	int		x;

	i = 0;
	x = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[x])
		str[i++] = s2[x++];
	str[i] = '\0';
	if (flag == 0)
		free (s1);
	else if (flag == 1)
		free (s2);
	return (str);
}
