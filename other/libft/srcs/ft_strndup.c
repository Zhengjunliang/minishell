/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaibazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:57:19 by lgaibazz          #+#    #+#             */
/*   Updated: 2023/08/14 15:57:20 by lgaibazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(s1))
		return (NULL);
	while (s1[i] != '\0')
		i++;
	if (len <= i)
	{
		dst = malloc(sizeof(char) * (len + 1));
		if (!dst)
			return (NULL);
	}
	else
	{
		dst = malloc(sizeof(char) * (i + 1));
		if (!dst)
			return (NULL);
	}
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
