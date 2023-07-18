/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:19:30 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/14 17:19:31 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Controllare se le "/' sono complete */
int	quote_check(t_mini *mini, char **line)
{
	if (quotes(*line, 2147483647))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", 2);
		ft_memdel(*line);
		mini->ret = 2;
		mini->start = NULL;
		return (1);
	}
	return (0);
}

void	parse(t_mini *mini)
{
	char	*line;
	t_token	*token;

	mini->ret ? ft_putstr_fd("🤬 ", 2) : ft_putstr_fd("😎 ", 2); // ret = 0 se commandi giusti altrimente vuol fire non giusto
	ft_putstr_fd("\033[0;36m\033[1mminishell ▸ \033[0m", 2);
	/*lexer il commando e memorizzare in line*/
	if (get_next_line(0, &line) == -2 && (mini->exit = 1))
		ft_putendl_fd("exit", 2);
	if (quote_check(mini, &line))
		return ;
	mini->start = get_tokens(line); // Suddivido i commandi in varie word e li memorizzo in token
	ft_memdel(line);
	token = mini->start;
	while (token)
	{
		token = token->next;
	}
}
