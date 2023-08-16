/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:37:11 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 15:37:12 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		st;
	int		end;

	i = 0;
	st = 0;
	end = ft_strlen((char *) s1);
	if (end == -1)
		return (NULL);
	while (ft_check(s1[st], set) == 1)
		st++;
	while (end > st && ft_check(s1[end - 1], set) == 1)
		end--;
	str = ft_calloc(sizeof(char), (end - st + 1));
	if (!str)
		return (NULL);
	while (st < end)
	{
		str[i] = s1[st];
		i++;
		st++;
	}
	str[i] = '\0';
	return (str);
}
