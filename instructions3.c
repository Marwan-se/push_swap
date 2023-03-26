/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:06:54 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/25 19:59:55 by msekhsou         ###   ########.fr       */
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
