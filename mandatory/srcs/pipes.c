/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:13:18 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/10 21:17:35 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_pipes(t_comm *cl, int count, t_io *ios)
{
	int		i;
	int		fd[2];
	t_comm	*node;
	int		prev_read_end;
	pid_t	ps;

	i = 0;
	node = cl;
	while (i < count)
	{
		pipe(fd);
		ps = fork();
		if (ps == 0) // children
		{
			if (i == 0)
			{
				dup2(ios->in, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				execve(node->path, node->args, NULL);
			}
			else if (i == count - 1)
			{
				close(fd[1]);
				dup2(prev_read_end, STDIN_FILENO);
				dup2(ios->out, STDOUT_FILENO);
				execve(node->path, node->args, NULL);
			}
			else
			{
				dup2(prev_read_end, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				execve(node->path, node->args, NULL);
			}
		}
		else // parent
		{
			prev_read_end = fd[0];
			close(fd[1]);
		}
		node = node->next;
		i++;
	}
	i = 0;
	while (i < count)
	{
		wait(NULL);
		i++;
	}
}