/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:14:35 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/02 13:11:02 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_nbs(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi (av[i]) > 2147483647 || ft_atoi (av[i]) < -2147483648)
			return (1);
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_for_char(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

size_t	space_number(char *arg)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int	arg_empty(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (ft_strlen(arg[i]) == space_number(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**arguments(int ac, char **av)
{
	char	**table;
	char	*s;
	char	*arg;
	int		i;

	i = 1;
	s = (char *)malloc(1 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	if (arg_empty(av) == 0)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	while (i < ac)
	{
		arg = ft_strjoin(s, av[i++]);
		free (s);
		s = ft_strjoin(arg, " ");
		free(arg);
	}
	table = ft_split(s, ' ');
	free(s);
	return (table);
}
