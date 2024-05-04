/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/04 13:17:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks()
{
	system("leaks pipex");
}

int	main(int ac, char *av[], char *env[])
{
	t_list	**cl;
	int	path_i;

	atexit(leaks);
	if (ac == 5 && !access(av[1], F_OK) && !access(av[1], F_OK))
	{
		cl = append_comms_(cl, av, ac, env);
	}
	else
		handle_error();
	return (0);
}
