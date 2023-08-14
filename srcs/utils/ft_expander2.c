/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_number_size2(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len += 1;
	if (num == -2147483648)
		return (11);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa2(long int n)
{
	char			*str;
	long int		num;
	unsigned int	len;

	len = ft_number_size2(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

char	*exit_exp2(char *line, int stop)
{
	char	*new;
	char	*exit;
	int		y;
	int		i;
	int		x;

	y = -1;
	i = -1;
	exit = ft_itoa2(g_exit);
	new = ft_calloc(sizeof(char), ft_strlen(line) - 2
			+ ft_strlen(exit) + 1);
	while (++y < stop)
		new[++i] = line[y];
	x = -1;
	while (exit[++x])
		new[++i] = exit[x];
	while (line[y] && line[y] != ' ' && line[y] != 34 && line[y] != 39
		&& !ft_isalnum(line[y]))
		y++;
	if (line[y])
		while (line[y])
			new[++i] = line[y++];
	free(exit);
	return (new);
}

char	*exit_exp(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	if (ft_strchr(line, '$'))
	{
		while (line[++i])
		{
			if (line[i] == '$' && line[i + 1] == '?')
			{
				tmp = exit_exp2(line, i);
				free(line);
				return (tmp);
			}
		}
	}
	return (line);
}