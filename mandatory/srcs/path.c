/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:54:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/02 20:49:13 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_parce(t_comm *comm, char *str)
{
	int i;
	int start;
	int wc;
	int boo;

	i = 0;
	boo = 0;
	wc = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ' ' && !boo)
		{
			if (i != start)
			{
				str[i] = '\0';
				
			}
			start = i + 1;
		}
		else if (str[i] == '\'' && !boo)
		{
			if (i != start)
			{
				str[i] = '\0';
				append(ft_lstnew(ft_strdup(str[start])));
			}
			start = i + 1;
		}
		if (str[i] == '\'')
			boo = 1;
		i++;
	}
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

void	parce_arg(t_comm *arg, char *str, char **envp)
{
	char	**cmd_line;
	char	**paths;

	cmd_line = ft_split(str, ' ');
	paths = get_paths(envp);
	if (paths && is_bin(paths, cmd_line[0]) != -1)
	{
		arg->path = ft_strdup(paths[is_bin(paths, cmd_line[0])]);
		arg_split_(str);
	}
	free_darr(paths);
}