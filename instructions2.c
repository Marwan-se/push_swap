/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:01:41 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/02 03:00:09 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*t2;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	t2 = tmp->next;
	tmp->next = NULL;
	t2->next = *stack;
	*stack = t2;
	if (!str)
		return ;
	ft_printf("%s", str);
}

void	rrr(t_list **a, t_list **b, char *str)
{
	ft_reverse_rotate(a, NULL);
	ft_reverse_rotate(b, NULL);
	if (!str)
		return ;
	ft_printf("%s", str);
}

void	sort_2(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		swap_f(stack, "sa\n");
}

void	sort_3(t_list **stack)
{
	int	max;

	max = find_max(*stack);
	if ((*stack)->content == max)
	{
		ft_rotate(stack, "ra\n");
		if ((*stack)->content > (*stack)->next->content)
			swap_f(stack, "sa\n");
	}
	else if ((*stack)->next->content == max)
	{
		ft_reverse_rotate((stack), "rra\n");
		if ((*stack)->content > (*stack)->next->content)
			swap_f(stack, "sa\n");
	}
	else if ((*stack)->content > (*stack)->next->content)
		swap_f(stack, "sa\n");
}

void	sort5(t_list **a, t_list **b)
{
	int	min;

	while (stack_len(*a) > 3)
	{
		min = find_min(*a);
		if ((*a)->content == min)
			push_to(a, b, "pb\n");
		else if ((*a)->next->content == min)
		{
			swap_f(a, "sa\n");
			push_to(a, b, "pb\n");
		}
		else if (stack_bottom(*a)->content == min)
		{
			ft_reverse_rotate(a, "rra\n");
			push_to(a, b, "pb\n");
		}
		else
			ft_rotate(a, "ra\n");
	}
	sort_3(a);
	while (stack_len(*b) > 0)
		push_to(b, a, "pa\n");
}
