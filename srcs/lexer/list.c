/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaibazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:21:15 by lgaibazz          #+#    #+#             */
/*   Updated: 2023/08/14 15:21:16 by lgaibazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_freelist(t_list **lst)
{
	t_list	*nxt;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		free((*lst));
		*lst = nxt;
	}
	free(*lst);
}

void	ft_freelistcont(t_list *lst)
{
	t_list	*nxt;

	if (!lst)
		return ;
	while (lst)
	{
		nxt = lst->next;
		if (lst->content != NULL)
			free(lst->content);
		lst = nxt;
	}
	free(lst);
}

void	clc_freelist(t_cmd *head, t_list **lsthead)
{
	if (!head)
		ft_freelistcont(*lsthead);
	ft_freelist(lsthead);
}
