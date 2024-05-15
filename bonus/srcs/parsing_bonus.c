/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:30 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/15 22:29:44 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	update_trackers(int *quotes, int *start, int *i)
{
	*quotes = 1;
	*start = *i + 1;
}

int	append_(int *start, char *str, t_comm **tokens, int i)
{
	t_comm	*new;

	if (*start != i)
	{
		str[i] = '\0';
		new = ft_lstnew();
		new->comm = ft_strtrim((str + *start), " ");
		if (ft_strlen(new->comm) && !only_whitespaces(new->comm))
			ft_lstadd_back(tokens, new);
		else
			freell(&new, 0);
		*start = i + 1;
	}
	return (0);
}

t_comm	*ft_tokens(char *args)
{
	t_comm	*tokens;
	int		quotes;
	int		start;
	int		i;

	quotes = 0;
	i = 0;
	start = 0;
	tokens = NULL;
	while (args[i])
	{
		if (!quotes && args[i] == ' ')
			append_(&start, args, &tokens, i);
		else if (quotes && args[i] == '\'')
			quotes = append_(&start, args, &tokens, i);
		else if (!quotes && args[i] == '\'')
		{
			if (args[i - 1] && args[i - 1] != ' ')
				append_(&start, args, &tokens, i);
			update_trackers(&quotes, &start, &i);
		}
		i++;
	}
	return (append_(&start, args, &tokens, i), tokens);
}

char	**tokenize_(char *av)
{
	t_comm	*tokens;
	int		counts[2];
	char	**args;
	t_comm	*node;

	args = NULL;
	counts[0] = 0;
	counts[1] = 0;
	tokens = ft_tokens(av);
	counts[0] = lst_count(&tokens);
	args = (char **)malloc(sizeof(char *) * (counts[0] + 1));
	node = tokens;
	while (node && counts[0])
	{
		args[counts[1]] = ft_strdup(node->comm);
		node = node->next;
		counts[1]++;
	}
	args[counts[1]] = NULL;
	freell(&tokens, 0);
	return (args);
}

t_comm	*append_comms_(char **av, int ac, int here_doc)
{
	int		i;
	int		j;
	t_comm	*cl;
	t_comm	*new;

	if (here_doc)
		i = 3;
	else
		i = 2;
	j = 0;
	cl = NULL;
	while (i < ac - 1)
	{
		new = ft_lstnew();
		new->args = tokenize_(av[i]);
		new->index = j;
		ft_lstadd_back(&cl, new);
		i++;
		j++;
	}
	return (cl);
}
