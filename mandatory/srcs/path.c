/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:54:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/03 16:20:24 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char 	**get_paths(char **env)
{
	char	**temp;
	char	**bin_dirs;
	char	*path_env;
	int		i;

	i = 0;
	path_env = NULL;
	bin_dirs = NULL;
	while (env && env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			path_env = env[i];
		i++;
	}
	if (path_env)
	{
		temp = ft_split(path_env, '=');
		bin_dirs = ft_split(temp[1], ':');
		free_darr(temp);
		temp = NULL;
	}
	return (bin_dirs);
}

/*Determine the exec path for a given comm, abs and rel paths*/
void	get_exec(char *av, t_comm *comm, char **envp)
{
	char **paths;
	int i;

	paths = get_paths(envp);
	if (av[0] == '.' && av[1] == '/' && !access(av, X_OK))
		comm->path = ft_strdup(av);
	else if (av[0] == '/' && !access(av, X_OK))
		comm->path = ft_strdup(av);
	else if (is_bin(paths, av) != -1)
		comm->path = ft_strjoin(paths[is_bin(paths, av)], av);
	else
		comm->path = NULL;
	if (paths)
		free_darr(paths);
	return ;
}

int	is_bin(char **bin_dir, char *cmd)
{
	int		i;
	char	*path;
	int		path_i;
	char 	*cmd_path;

	i = 0;
	cmd_path = NULL;
	path = NULL;
	path_i = -1;
	while (bin_dir[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		path = ft_strjoin(bin_dir[i], cmd_path);
		if (!access(path, X_OK))
			path_i = i;
		free(path);
		free(cmd_path);
		path = NULL;
		cmd_path = NULL;
		i++;
	}
	if (path_i == -1)
		handle_error();
	return (path_i);
}

/* Parses argument from command line string and stores them in the provided command structure*/
void	parce_arg(t_comm *cmd, char **av, char **envp, int i)
{
	char	**cmd_line;
	t_comm 	**comms;

	cmd_line = tokenize_(av);
	get_exec(cmd_line[0], cmd, envp);
	if (!cmd->path)
		handle_err();
}

t_comm	**append_comms(t_comm **comms, char **av, int ac, char **envp)
{
	int i;

	i = 2;
	while (i < ac - 1)
	{
		parce_arg(comms, av[i], envp, i);
		i++;
	}
}