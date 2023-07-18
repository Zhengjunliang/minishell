/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:25:17 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/18 16:25:19 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*next_run(t_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	/*while (token)
	{
		token = token->next;
	}*/
	return (token);
}
