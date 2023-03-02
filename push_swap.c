/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:03 by msekhsou          #+#    #+#             */
/*   Updated: 2023/02/17 05:49:51 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac > 1)
	{
		stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		*stack_a = 0;
		*stack_b = 0;
		
	}
	return (0);
}