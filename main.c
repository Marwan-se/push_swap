/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:36 by msekhsou          #+#    #+#             */
/*   Updated: 2023/02/28 22:24:30 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void push_to(t_list **from,t_list **to)
// {
// 	int data = pop(from);
// 	push(to,data);
// }

// void swap_f(t_list **s)
// {
// 	int data1 =pop(s);
// 	int data2 = pop(s);
// 	push(s,data1);
// 	push(s,data2);
// }

// void ft_rotate(t_list **s)
// {
// 	int data = pop(s);
// 	t_list *new = ft_lstnew(data);
// 	ft_lstadd_back(s,new);
// }

// void ft_reverse_rotate(t_list **s)
// {
// 	t_list *tmp;
// 	t_list *t2;
// 	tmp = *s;

// 	while(tmp->next->next)
// 		tmp = tmp->next;
// 	t2 = tmp->next;
// 	tmp->next = NULL;
// 	t2->next = *s;
// 	*s = t2;
// }

int main(int ac,char **av)
{
	t_list *a = NULL;
	// t_list *b = NULL;

	int i;
	i = 1;
	while(i < ac)
		push(&a,atoi(av[i++]));
	if(ac == 4)
	{
		
		swap_f(&a);
		
		ft_reverse_rotate(&a);
	}
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
	while(a)
	{
		printf("%d\n",a->content);
		a = a->next;
	}
	//  printf("///////////////////\n");
	// while(b)
	// {
	// 	printf("%d\n",b->content);
	// 	b = b->next;
	// }
}