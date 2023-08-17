/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:29:29 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:29:30 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && x < len)
		{
			dest[x] = s[i];
			x++;
		}
		i++;
	}
	dest[x] = 0;
	return (dest);
}

void	ft_skip_space(char *s, int *i)
{
	while (s[*i] && s[*i] == 32)
		(*i)++;
}

void	ft_close_quote(char *s, int *i, char c)
{
	(*i)++;
	while (s[*i] && s[*i] != c)
		(*i)++;
	(*i)++;
}

static void	ft_sq(char *s, int *i, int *words)
{
	*words += (s[*i - 1] && s[*i - 1] != 32);
	ft_close_quote(s, i, 39);
	while (s[*i] && s[*i] != 32 && s[*i] != 34 && s[*i] != 39)
		(*i)++;
}

int	ft_countwords1(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s && s[i])
	{
		words += (s[i] != 32);
		while (s[i] && s[i] != 32)
		{
			if (s[i] == 34)
			{
				if (i > 0 && s[i - 1] && s[i - 1] != 32)
					words++;
				ft_close_quote(s, &i, 34);
			}
			else if (s[i] == 39)
				ft_sq(s, &i, &words);
			else
				i++;
		}
		ft_skip_space(s, &i);
	}
	return (words);
}
