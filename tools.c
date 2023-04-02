/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:30:55 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/28 20:15:41 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *stack)
{
	return (!stack);
}

void	push(t_list **stk, int data)
{
	t_list	*stack_node;

	stack_node = ft_lstnew(data);
	stack_node->next = *stk;
	*stk = stack_node;
}

int	pop(t_list **stk)
{
	t_list	*temp;
	int		popped;

	if (is_empty(*stk))
		return (INT_MIN);
	temp = *stk;
	*stk = (*stk)->next;
	popped = temp->content;
	free(temp);
	return (popped);
}

int	stack_sorted(t_list *stack)
{
	int	prevs;

	prevs = INT_MIN;
	while (stack != NULL)
	{
		if (stack->content < prevs)
			return (0);
		prevs = stack->content;
		stack = stack->next;
	}
	return (1);
}

int	find_var(t_list **long_list, int data)
{
	t_list	*tmp;

	tmp = *long_list;
	while (tmp)
	{
		if (data == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
