/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_dapex(char	*line, char	*trim)
{
	free(line);
	trim = ft_strjoin3("\"", trim, 1);
	trim = ft_strjoin3(trim, "\"", 0);
	return (trim);
}

int	ft_sl(const char *s)
{
	int	i;

	if (!s || !(*s))
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	content_is(t_list *lst, const char *s)
{
	if (!(ft_strncmp((char *)((lst)->content), s,
			ft_sl((char *)((lst)->content)))))
		return (1);
	else
		return (0);
}

static int	ft_wordlen(char *s)
{
	int	len;

	if (!s || !(*s))
		return (0);
	len = 0;
	while (s[len] && s[len] != 32)
	{
		if (s[len] == 34)
			ft_close_quote(s, &len, 34);
		else if (s[len] == 39)
		{
			ft_close_quote(s, &len, 39);
			while (s[len] && s[len] != 32 && s[len] != 34 && s[len] != 39)
				len++;
		}
		else
			len++;
	}
	return (len);
}

char	**ft_split1(char *s)
{
	char	**matrix;
	int		wc;
	int		n;
	int		i;

	wc = ft_countwords1(s);
	matrix = (char **)malloc((wc + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!s || !(*s))
		matrix[0] = NULL;
	n = 0;
	i = 0;
	while (n < wc)
	{
		ft_skip_space(s, &i);
		matrix[n] = ft_substr(s, i, ft_wordlen(&s[i]));
		if (!matrix[n])
			return (NULL);
		i += ft_wordlen(&s[i]);
		n++;
	}
	matrix[n] = NULL;
	return (matrix);
}
