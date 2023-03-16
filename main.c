/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:36 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/16 16:22:11 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac,char **av)
{
	t_list *a = NULL;
	t_list *b = NULL;

	// int i;
	// i = ac - 1;
	// while(i > 0)
	// 	push(&a, ft_atoi(av[i--]));
	
	char **t = arguments(ac,av);
	ac = 0;
	while(t[ac] != NULL)
	{
		ac++;
	}
	if (dup_nbs(ac, t) || !check_for_char(ac, t))
	{
        ft_printf("Error\n");
        return (1);
    }
	ac = 0;
	while(t[ac] != NULL)
	{
		push(&a,ft_atoi(t[ac]));
		ac++;
	}
	ft_LIS(&a,&b);
	while(a)
	{
		printf("%d\n",a->content);
		a = a->next;
	}
}
    // sort_3(&a);
	// swap_f(&a);Y
	// swap_f(&a);

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
	// puts("sssssssssssssss\n");
	// while(b)
	// {
	// 	printf("%d\n",b->content);
	// 	b = b->next;
	// }

