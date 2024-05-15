/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:23:09 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/15 11:10:28 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_io *ios, char **av)
{
	char	*buf;
	char	*joined;

	joined = ft_strjoin(av[2], "\n");
	ios->in = open("here_doc", O_TRUNC | O_CREAT | O_RDWR, 0644);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		buf = get_next_line(0);
		if (!buf || !ft_strncmp(buf, joined, ft_strlen(av[2])))
			break ;
		ft_putstr_fd(buf, ios->in);
		free(buf);
	}
	close(ios->in);
	ios->in = open("here_doc", O_RDONLY, 0644);
	if (joined && buf)
	{
		free(buf);
		free(joined);
	}
}

int	is_file(t_io *ios, char **env, char **av, t_doc *doc)
{
	if (!ft_strncmp(av[1], "here_doc", 8)
		&& ft_strlen(av[1]) == 8)
	{
		doc->delimiter = av[2];
		here_doc(ios, av);
		ios->here_doc = 1;
	}
	else if (access(ios->in_file, F_OK) || access(ios->in_file, R_OK))
	{
		perror("In File");
		exit(EXIT_FAILURE);
	}
	else
	{
		ios->in = open(ios->in_file, O_RDONLY, 0644);
		ios->here_doc = 0;
		if (ios->in == -1)
			return (0);
	}
	ios->out = open(ios->out_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (ios->out == -1)
		return (0);
	ios->prev_read_end = -1;
	ios->envp = env;
	return (1);
}

void	start_exec(t_io *ios, char **av, int ac, char **env)
{
	t_comm	*node;
	t_comm	*cl;

	cl = append_comms_(av, ac, ios->here_doc);
	if (!cl)
		handle_error();
	node = cl;
	while (node)
	{
		get_exec(node->args[0], node, env);
		node = node->next;
	}
	execute_pipes(cl, lst_count(&cl), ios);
	freell(&cl, 1);
}

int	main(int ac, char *av[], char *env[])
{
	t_comm	*cl;
	t_io	ios;
	t_doc	doc;

	cl = NULL;
	if (ac >= 5 && is_valid(av, ac))
	{
		ios.in_file = av[1];
		ios.out_file = av[ac - 1];
		if (is_file(&ios, env, av, &doc))
			start_exec(&ios, av, ac, env);
	}
	else
	{
		ft_putstr_fd(INVALID_FORMAT, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
