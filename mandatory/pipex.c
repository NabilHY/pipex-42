/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/11 20:55:00 by nhayoun          ###   ########.fr       */
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
	if (access(ios->in_file, F_OK) || access(ios->in_file, R_OK))
	{
		perror("File");
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
	return (1);
}

int	main(int ac, char *av[], char *env[])
{
	t_comm	*cl;
	t_comm	*node;
	t_io	ios;

	cl = NULL;
	atexit(leaks);
	if (ac >= 5 && is_valid(av, ac))
	{
		ios.in_file = av[1];
		ios.out_file = av[ac-1];
		if (is_file(&ios))
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
		}
		freell(&cl, 1);
	}
	return (0);
}
