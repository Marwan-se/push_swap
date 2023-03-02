/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:33:32 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/01 02:15:59 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_f(t_list **s)
{
	int data1 =pop(s);
	int data2 = pop(s);
	push(s,data1);
	push(s,data2);
}

void	ss(t_list	*a,t_list *b)
{
	swap_f(&a);
	swap_f(&b);
}

void push_to(t_list **from,t_list **to)
{
	int data = pop(from);
	push(to,data);
}

void ft_rotate(t_list **s)
{
	int data = pop(s);
	t_list *new = ft_lstnew(data);
	ft_lstadd_back(s,new);
}

void rr(t_list *a,t_list *b)
{
	ft_rotate(&a);
	ft_rotate(&b);
}

void ft_reverse_rotate(t_list **stack)
{
	t_list *tmp;
	t_list *t2;
	tmp = *stack;

	while(tmp->next->next)
		tmp = tmp->next;
	t2 = tmp->next;
	tmp->next = NULL;
	t2->next = *stack;
	*stack = t2;
}

void rrr(t_list *a,t_list *b)
{
	ft_reverse_rotate(&a);
	ft_reverse_rotate(&b);
}
