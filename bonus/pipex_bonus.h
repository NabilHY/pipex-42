/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:25:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/12 18:39:04 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libr/libr.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_comm
{
	char			**args;
	char			*comm;
	char			*path;
	int				in;
	int				out;
	int				fd[2];
	int				pid;
	int				index;
	struct s_comm	*next;
}					t_comm;

typedef struct s_io
{
	int				in;
	int				out;
	char			**envp;
	int				prev_read_end;
	char			*in_file;
	char			*out_file;
}					t_io;

# define INVALID_FORMAT "Usage: ./pipex <in> \"cmd1\" \"cmd2\" <out>\n"

void				get_exec(char *av, t_comm *comm, char **envp);

t_comm				*ft_lstnew(void);

void				ft_lstadd_back(t_comm **lst, t_comm *cmd);

void				free_darr(char **arr);

t_comm				*append_comms_(char **av, int ac);

int					lst_count(t_comm **lst);

void				execute_pipes(t_comm *cl, int count, t_io *ios);

void				handle_error(void);

int					is_valid(char **av, int ac);

void				freell(t_comm **lst, int flag);

#endif
