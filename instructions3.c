/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:06:54 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/15 02:07:33 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	int		len;
	t_list	*current;

	len = 0;
	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_list	*stack_bottom(t_list *stack)
{
	t_list	*current;

	current = stack;
	if (!stack)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int	find_max(t_list *top)
{
	int		max;
	t_list	*ptr;

	max = top->content;
	ptr = top;
	while (ptr != NULL)
	{
		if (ptr->content > max)
			max = ptr->content;
			ptr = ptr->next;
	}
	return (max);
}

int	find_min(t_list *top)
{
	int		min;
	t_list	*ptr;

	min = top->content;
	ptr = top;
	while (ptr != NULL)
	{
		if (ptr->content < min)
			min = ptr->content;
		ptr = ptr->next;
	}
	return (min);
}

void	push_lis_b(t_list **a, t_list **b, t_list **longlist)
{
	int	i;

	i = stack_len(*a);
	while (i)
	{
		if (find_var(longlist, (*a)->content))
			ft_rotate(a, "ra\n");
		else
			push_to(a, b, "pb\n");
		i--;
	}
	sort_b_to_a(a, b);
}
