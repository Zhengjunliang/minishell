/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:44:53 by juzheng           #+#    #+#             */
/*   Updated: 2023/07/22 16:44:54 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	ft_freelist(t_list **lst)
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

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (cmd)
	{
		while (cmd->next)
			cmd = cmd->next;
	}
	return (cmd);
}

void	ft_cmd_addback(t_cmd **cmd, t_cmd *new)
{
	if (cmd)
	{
		if (*cmd)
			ft_cmdlast(*cmd)->next = new;
		else
			*cmd = new;
	}
}

static int	ft_cmdslen(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	*path_search(char **path, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (path[++i] && ft_strncmp(cmd, ".", 1))
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

t_cmd	*ft_cmdnew(t_list **lst, char **path)
{
	t_cmd	*cmdn;
	int		len;
	int		i;

	cmdn = malloc(sizeof(t_cmd));
	if (!cmdn)
		return (NULL);
	len = ft_cmdslen(*lst);
	cmdn->cmds = malloc(sizeof(char *) * (len + 1));
	if (!(cmdn->cmds))
		return (NULL);
	(cmdn->cmds)[len] = NULL;
	i = -1;
	while (++i < len)
	{
		(cmdn->cmds)[i] = (char *)((*lst)->content);
		*lst = (*lst)->next;
	}
	cmdn->cmd = path_search(path, (cmdn->cmds)[0]);
	cmdn->next = NULL;
	return (cmdn);
}

void	init_cmdlst(t_cmd **cmdlst, t_cmd **head, t_list **lst, t_mini *ms)
{
	*cmdlst = NULL;*/
	/*if (!(content_is(*lst, "|") || content_is(*lst, "<")
			|| content_is(*lst, "<<") || content_is(*lst, ">")
			|| content_is(*lst, ">>")))*/
	/**cmdlst = ft_cmdnew(lst, ms->path);
	*head = *cmdlst;
}

t_cmd	*create_cmdlst(t_list	*lst, t_mini *ms)
{
	t_list	*lsthead;
	t_cmd	*head;
	t_cmd	*cmdlst;

	lsthead = lst;
	init_cmdlst(&cmdlst, &head, &lst, ms);
	while (lst && cmdlst)
	{
		ft_cmd_addback(&cmdlst, ft_cmdnew(&lst, ms->path));
		cmdlst = ft_cmdlast(cmdlst);
	}
	clc_freelist(head, &lsthead);
	return (head);
}
*/