/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:54:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/01 16:56:49 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	handle_error(void)
{
	perror("Error");
	exit(1);
}

void	free_darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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