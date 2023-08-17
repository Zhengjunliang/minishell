/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:34:05 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/16 14:34:05 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!to_find || !to_find[0])
		return ((char *)str);
	if (!to_find || !str)
		return (NULL);
	while (str[i] && i < len)
	{
		x = 0;
		while (i + x < len && str[i + x] == to_find[x] && to_find[x]
			&& str[i + x])
		{
			x++;
			if (to_find[x] == '\0' )
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
