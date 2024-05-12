/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/12 18:42:54 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_file(t_io *ios, char **env)
{
	if (access(ios->in_file, F_OK) || access(ios->in_file, R_OK))
	{
		perror("In File");
		exit(EXIT_FAILURE);
	}
	else
	{
		ios->in = open(ios->in_file, O_RDONLY, 0644);
		if (ios->in == -1)
			return (0);
	}
	ios->out = open(ios->out_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (ios->out == -1)
		return (0);
	ios->prev_read_end = -1;
	ios->envp = env;
	return (1);
}

int	main(int ac, char *av[], char *env[])
{
	t_comm	*cl;
	t_comm	*node;
	t_io	ios;

	cl = NULL;
	if (ac == 5 && is_valid(av, ac))
	{
		ios.in_file = av[1];
		ios.out_file = av[ac - 1];
		if (is_file(&ios, env))
		{
			cl = append_comms_(av, ac);
			if (!cl)
				handle_error();
			node = cl;
			while (node)
			{
				get_exec(node->args[0], node, env);
				node = node->next;
			}
			execute_pipes(cl, lst_count(&cl), &ios);
			freell(&cl, 1);
		}
	}
	return (0);
}
