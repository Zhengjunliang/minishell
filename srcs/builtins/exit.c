/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:39:16 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/18 16:39:17 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_mini **mini)
{
	if (!(*mini)->input)
	{
		printf("exit\n");
		return (1);
	}
	if (!ft_strncmp((*mini)->input, "exit", 4))
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}
