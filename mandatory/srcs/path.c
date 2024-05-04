/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:54:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/04 16:50:57 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_list	**ft_tokens(char *arg, char *str)
{
	t_list	**tokens;
	int		quotes;
	char	*start;
	int		i;

	i = 0;
	quotes = 0;
	start = str;
	while (str[i])
	{
		
		i++;
	}
	return (tokens);
}

t_list	*tokenize_(t_list **lst)
{
	t_list	*tok;

	
}


t_list	**append_comms_(t_list **cl, char **av, int ac, char **envp)
{
	int i;

	i = 2;
	while (i < ac - 1)
	{
		ft_lstadd_back(cl, tokenize_());
		i++;
	}
}