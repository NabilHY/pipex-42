/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/01 16:56:26 by nhayoun          ###   ########.fr       */
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
	char **bin_dirs;
	int	path_i;
	atexit(leaks);

	(void)av;
	if (ac == 2)
	{
		bin_dirs = get_paths(env);
		path_i = is_bin(bin_dirs, av[1]);
		if (path_i == -1)
			perror("Error:");
		else
			printf("%s\n", bin_dirs[path_i]);
		if (bin_dirs)
			free_darr(bin_dirs);
	}
	return (0);
}
