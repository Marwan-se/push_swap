/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:36 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/26 19:41:18 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**t;

	a = NULL;
	b = NULL;
	t = arguments(ac, av);
	ac = 0;
	while (t[ac] != NULL)
		ac++;
	if (dup_nbs(ac, t) || !check_for_char(ac, t))
	{
		ft_printf("Error\n");
		return (1);
	}
	ac = 0;
	while (t[ac])
		ac++;
	ac = ac - 1;
	while (ac >= 0)
	{
		push(&a, ft_atoi(t[ac]));
		ac--;
	}
	ft_LIS(&a, &b);
}
