/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/09 22:06:43 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks()
{
	system("leaks pipex");
}

void		print(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return ;
}

int		is_file(t_io *ios)
{
	if (access("in", F_OK) || access("in", R_OK))
	{
		perror("In: ");
		exit(EXIT_FAILURE);
	}
	else
	{
		ios->in = open("in", O_RDONLY, 0644);
		if (ios->in == -1)
			return (0);
	}
		ios->out = open("out", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (ios->out == -1)
			return (0);
		dprintf(2, "%d\n", ios->out);
	return (1);
}

int	main(int ac, char *av[], char *env[])
{
	t_comm	*cl;
	t_comm	*node;
	t_io	ios;

	cl = NULL;
	if (ac >= 5 && is_file(&ios))
	{
		cl = append_comms_(av, ac, env);
		node = cl;
		while (node)
		{
			get_exec(node->args[0], node, env);
			node = node->next;
		}
		execute_pipes(cl, lst_count(&cl), &ios);
	}
	return (0);
}
