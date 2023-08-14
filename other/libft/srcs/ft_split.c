/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:19:30 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/24 15:19:33 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_words_alloc(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), (end - start + 1));
	if (!str)
		return (NULL);
	while (end > start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		words;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	words = ft_words_count(s, c);
	str = ft_calloc(sizeof(char *) * (words + 1), 1);
	if (!str)
		return (NULL);
	while (words != 0)
	{
		start += (s[start] == c);
		if ((s[end] != c && s[end + 1] == c) || s[end + 1] == '\0')
		{
			str[i++] = ft_words_alloc(s, start, ++end);
			words--;
			start = end;
		}
		end++;
	}
	return (str);
}