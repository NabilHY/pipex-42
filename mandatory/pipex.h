/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:25:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/01 16:57:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libr/libr.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct t_comm
{
	char *path;
	char **argv;
	char **envp;
	int flag;
}	s_comm;

# define INVALID_FORMAT "Usage: ./pipex <in> \"cmd1\" \"cmd2\" <out>\n"

int		is_bin(char **bin_dir, char *cmd);

char 	**get_paths(char **env);

void	utils(void);

void	free_darr(char **arr);

#endif
