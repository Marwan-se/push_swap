/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:36 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/09 16:32:06 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac,char **av)
{
	t_list *a = NULL;
	// t_list *b = NULL;

	int i;
	i = 1;
	while(i < ac)
		push(&a,atoi(av[i++]));
	// if(ac == 4)
	// {
		
	// 	swap_f(&a);
		
	// 	ft_reverse_rotate(&a);
	// }
    // sort_2(&a);
	ft_LIS(&a);
	// swap_f(&a);
	// swap_f(&a);

	// // push(&b,980);
	// push(&b,1);
	// t_list *tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n",tmp->content);
	// 	tmp = tmp->next;
	// }
	// //swap_f(&a);
	// ft_rotate(&a);
	// // push_to(&b,&a);
	// while(a)
	// {
	// 	printf("%d\n",a->content);
	// 	a = a->next;
	// }
	
}

// int	main(int ac, char **av)
// {
	
// }