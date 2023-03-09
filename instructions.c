/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:33:32 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/09 15:55:28 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_f(t_list **s)
{
	puts("sa");
	int data1 =pop(s);
	int data2 = pop(s);
	push(s,data1);
	push(s,data2);
}

void	ss(t_list	*a,t_list *b)
{
	puts("ss");
	swap_f(&a);
	swap_f(&b);
}

void push_to(t_list **from,t_list **to)
{
	puts("push");
	int data = pop(from);
	push(to,data);
}

void ft_rotate(t_list **s)
{
	puts("ra");
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
	puts("rra");
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

void sort_3(t_list **stack)
{
	int max = find_max(*stack);
	
	if((*stack)->content == max)
	{
		ft_rotate(stack);
		if((*stack)->content > (*stack)->next->content)
			swap_f(stack);
	}
	else if((*stack)->next->content == max)
	{
		ft_reverse_rotate((stack));
		if((*stack)->content > (*stack)->next->content)
			swap_f(stack);
	}
	else 
		if ((*stack)->content > (*stack)->next->content)
			swap_f(stack);
}

void	sort_2(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
			swap_f(stack);
}

int	stack_len(t_list *stack)
{
	if (!stack)
		return (0);
	int	len = 0;
	t_list	*current = stack;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_list	*stack_bottom(t_list *stack)
{
	if (!stack)
		return (NULL);
	t_list	*current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	sort5(t_list **a, t_list **b)
{
	int	min;

	while (stack_len(*a) > 3)
	{
		min = find_min(*a);
		if ((*a)->content == min) 
		{
			push_to(a,b);
		}
		else if ((*a)->next->content == min)
		{
			swap_f(a);
			push_to(a,b);
		}
		else if (stack_bottom(*a)->content == min)
		{
			ft_reverse_rotate(a);
			push_to(a,b);
		}
		else
			ft_rotate(a);
	}

	sort_3(a);
	while (stack_len(*b) > 0)
		push_to(b,a);

}
