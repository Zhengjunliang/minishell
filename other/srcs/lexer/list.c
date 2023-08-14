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

//ritorna 1 se una lista e' vuota (se il primo elemento e' NULL), altrimenti ritorna 0
int	is_empty(t_list *list)
{
	return (list->head == NULL);
}

//inizializza una nuova lista e ritorna un puntatore ad essa
t_list	*init_list(t_list *list)
{
	list = ft_calloc(sizeof(t_list), 1);
	if (!list)
		return (NULL);
	return (list);
}

//crea un nuovo token
t_elem	*new_elem(char *content, int len, enum e_token type, enum e_state state)
{
	t_elem	*elem;
	char	*cont;

	elem = ft_calloc(sizeof(t_elem), 1);
	if (!elem)
		return (NULL);
	cont = ft_strndup(content, len);
	if (!cont)
		return (NULL);
	elem->content = cont;
	elem->len = len;
	elem->type = type;
	elem->state = state;
	return (elem);
}

//aggiunge il token new in fondo alla lista. Viene usata mettendo la funzione new_elem al posto di new
void	add_tail(t_list *list, t_elem *new)
{
	if (is_empty(list))
		list->head = new;
	else
	{
		list->tail->next = new;
		new->prev = list->tail;
	}
	list->tail = new;
	list->size++;
}

//freea tutti gli elementi della lista e infine la lista stessa
void	free_list(t_list *list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp)
	{
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
	free(list);
}


