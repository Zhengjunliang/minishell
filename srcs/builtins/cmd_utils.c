/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:12 by juzheng           #+#    #+#             */
/*   Updated: 2023/08/17 13:48:13 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	*str;
	int		i;

	i = 0;
	if (lst)
		str = (char *)(lst->content);
	while (lst && ft_strncmp(str, "|", ft_sl(str))
		&& ft_strncmp(str, "<", ft_sl(str))
		&& ft_strncmp(str, ">", ft_sl(str))
		&& ft_strncmp(str, ">>", ft_sl(str)))
	{
		i++;
		lst = lst->next;
		if (lst)
			str = (char *)(lst->content);
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
	cmdn->in_fd = -1;
	cmdn->out_fd = -1;
	cmdn->next = NULL;
	return (cmdn);
}

void	init_cmdlst(t_cmd **cmdlst, t_cmd **head, t_list **lst, t_mini *ms)
{
	*cmdlst = NULL;
	if (!(content_is(*lst, "|") || content_is(*lst, "<")
			|| content_is(*lst, "<<") || content_is(*lst, ">")
			|| content_is(*lst, ">>")))
		*cmdlst = ft_cmdnew(lst, ms->path);
	*head = *cmdlst;
}
