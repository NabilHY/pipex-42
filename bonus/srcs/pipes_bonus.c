/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:13:18 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/12 16:19:24 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	save_pipe(t_io *ios, int *fds)
{
	ios->prev_read_end = fds[0];
	close(fds[1]);
}

void	child_process(t_io *ios, t_comm *node, int type, int *fds)
{
	if (type == 0)
	{
		dup2(ios->in, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		execve(node->path, node->args, ios->envp);
	}
	else if (type == 1)
	{
		close(fds[1]);
		dup2(ios->prev_read_end, STDIN_FILENO);
		dup2(ios->out, STDOUT_FILENO);
		execve(node->path, node->args, ios->envp);
	}
	else if (type == 2)
	{
		dup2(ios->prev_read_end, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		execve(node->path, node->args, ios->envp);
	}
}

void	parent_process(t_comm *cl, int count, t_io *ios)
{
	int		i;
	int		fds[2];
	t_comm	*node;
	pid_t	ps;

	i = 0;
	node = cl;
	while (i < count)
	{
		pipe(fds);
		ps = fork();
		if (ps == 0)
		{
			if (i == 0)
				child_process(ios, node, 0, fds);
			else if (i == count - 1)
				child_process(ios, node, 1, fds);
			else
				child_process(ios, node, 2, fds);
		}
		else
			save_pipe(ios, fds);
		node = node->next;
		i++;
	}
}

void	execute_pipes(t_comm *cl, int count, t_io *ios)
{
	int		i;

	i = 0;
	parent_process(cl, count, ios);
	while (i < count)
	{
		wait(NULL);
		i++;
	}
}
