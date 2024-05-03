/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/03 16:01:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks()
{
	system("leaks pipex");
}

int	main(int ac, char *av[], char *env[])
{
	//int	in;
	//int out;
	//int fds[2];
	t_comm *comms;
	int	path_i;

	atexit(leaks);
	if (ac == 5 && !access(av[1], F_OK) && !access(av[1], F_OK))
	{
		comms = append_comms_(&comms, av, ac, env);
	}
	else
		handle_error();
	return (0);
}
