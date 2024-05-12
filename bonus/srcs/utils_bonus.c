/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:12 by nhayoun           #+#    #+#             */
/*   Updated: 2024/05/12 16:19:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	only_whitespaces(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	is_valid(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_strlen(av[i]) == 0 || only_whitespaces(av[i]))
		{
			ft_putstr_fd("Error: Command not found\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
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

void	handle_error(void)
{
	perror("Error");
	exit(1);
}
