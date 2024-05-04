/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:25:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/04 16:53:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libr/libr.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_comm
{
	char			**args;
	int				index;
	struct	s_comm	*next;
}	t_comm;

# define INVALID_FORMAT "Usage: ./pipex <in> \"cmd1\" \"cmd2\" <out>\n"

int		is_bin(char **bin_dir, char *cmd);

char 	**get_paths(char **env);

void	free_darr(char **arr);

#endif
