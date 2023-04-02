/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:36 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/02 02:31:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_args(t_list **a, t_list **b, int args)
{
	if (args == 2)
		sort_2(a);
	else if (args == 3)
		sort_3(a);
	else if (args == 5)
		sort5(a, b);
	else
		ft_lis(a, b, 0, 0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**t;
	int		args;

	a = NULL;
	b = NULL;
	t = arguments(ac, av);
	ac = 0;
	while (t[ac] != NULL)
		ac++;
	if (ac < 1 || dup_nbs(ac, t) || !check_for_char(ac, t))
		return (ft_printf("Error\n"));
	ac = 0;
	while (t[ac])
		ac++;
	args = ac;
	ac = ac - 1;
	while (ac >= 0)
	{
		push(&a, ft_atoi(t[ac]));
		ac--;
	}
	if (!stack_sorted(a))
		sort_args(&a, &b, args);
}
