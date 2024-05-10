/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:39:03 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/09 20:41:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int			ft_lstindex(t_comm *lst, int index)
{
	int	i;
	t_comm	*node;

	node = lst;
	i = 0;
	if (!lst)
		return 0;
	while (node && i < index)
	{
		node = node->next;
		i++;
	}
	return (i);
}

t_comm		*ft_lstnew(void)
{
	t_comm	*comm;

	comm = (t_comm *)malloc(sizeof(t_comm));
	if (!comm)
		return (NULL);
	comm->args = NULL;
	comm->comm = NULL;
	comm->next = NULL;
	comm->path = NULL;
	return (comm);
}

void	ft_lstadd_back(t_comm **lst, t_comm *cmd)
{
	t_comm	*last;

	if (!lst || !cmd)
		return ;
	if (!*lst)
	{
		*lst = cmd;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = cmd;
}

int		lst_count(t_comm **lst)
{
	int		count;
	t_comm	*node;

	count = 0;
	node = *lst;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

void freell(t_comm **lst)
{
	t_comm *node;
	t_comm *temp;

	if (!lst)
		return;
	node = *lst;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->args);
		free(temp->comm);
		free(temp->path);
		free(temp);
	}
	*lst = NULL;
}