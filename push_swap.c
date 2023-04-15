/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:03 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/12 15:37:04 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the index of the minimum value in the stack

int	get_index(t_list **stack, int value)
{
	t_list	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		if (current->content == value)
			return (index);
		current = current->next;
		index++;
	}
	return (index);
}

// find the next number in the stack that is
//  greater than the current top value of the stack

int	get_next_nb(t_list *a, int data, t_list *i, t_list *j)
{
	t_list	*tmp;
	int		next_one;
	int		len;

	i = (a);
	j = (a)->next;
	tmp = i;
	next_one = find_min(a);
	len = stack_len(a);
	while (len--)
	{
		if (data > i->content && data < j->content)
		{
			next_one = j->content;
			break ;
		}
		j = j->next;
		i = i->next;
		if (i == NULL)
			i = tmp;
		if (j == NULL)
			j = tmp;
	}
	return (next_one);
}

// to get the content of the node at the top of the stack

int	get_at_index(t_list *list, int index)
{
	t_list	*current_node;
	int		i;

	if (index < 0 || index >= stack_len(list))
		exit(1);
	current_node = list;
	i = 0;
	while (i < index)
	{
		current_node = current_node->next;
		i++;
	}
	return (current_node->content);
}

int	get_min_index(int *arr, int size)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	min = arr[index];
	i = 0;
	while (i < size)
	{
		if (arr[i] <= min)
		{
			index = i;
			min = arr[index];
		}
		i++;
	}
	return (index);
}
