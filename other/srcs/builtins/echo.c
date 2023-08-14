/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:51:43 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/22 16:51:44 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_list *cmd)
{
	int	flag;
	int	i;
	t_elem node;

	node = cmd->head;
	flag = 0;
	i = 0;
	if (node)
	{
		while (node)
		{
			if (!ft_strncmp(node->content, "-n", 2))
			{
				flag = 1;
				i++;
			}
			if (node)
				printf("%s ", node->content);
			else
				printf("%s", node->content);
			node = node->next;
		}
		if (flag == 0)
			printf("\n");
	}
	g_exit = 0;
}
