/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:54:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/12 16:19:24 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	is_bin(char **bin_dir, char *cmd)
{
	int		i;
	char	*path;
	int		path_i;
	char	*cmd_path;

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

char	**get_paths(char **env)
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

void	get_exec(char *av, t_comm *comm, char **envp)
{
	char	**paths;
	char	*temp;

	paths = get_paths(envp);
	if (av[0] == '.' && av[1] == '/' && !access(av, X_OK))
		comm->path = ft_strdup(av);
	else if (av[0] == '/' && !access(av, X_OK))
		comm->path = ft_strdup(av);
	else if (is_bin(paths, av) != -1)
	{
		comm->path = ft_strjoin("/", av);
		temp = comm->path;
		comm->path = ft_strjoin(paths[is_bin(paths, av)], comm->path);
		free(temp);
	}
	else
		comm->path = NULL;
	if (paths)
		free_darr(paths);
	return ;
}
