/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:08 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expander(char *line)
{
	t_exp	*exp;
	
	
	exp = ft_calloc(sizeof(t_exp), 1);
	line = exit_exp(line);
	
	free(exp);
	return (line);
}