/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:52:37 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/24 14:52:38 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_int(int code)
{
	(void)code;
	
	ft_putstr_fd("\b\b  ", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\033[0;36m\033[1mminishell $ \033[0m", 2);
}
