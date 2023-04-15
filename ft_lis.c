/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:33:00 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/15 02:07:02 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(t_list **stack)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	tmp = *stack;
	arr = malloc(sizeof(int) * stack_len(*stack));
	i = 0;
	while (tmp != NULL)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	ft_lis2(int *max, int *max_list, int *index, int *i)
{
	if (*max < *max_list)
	{
		*max = *max_list;
		*index = *i;
	}
}

int	ft_lis(t_list **stack, t_list **b, int index, int *arr)
{
	int		*max_list;
	int		k;
	int		i;
	int		max;
	t_list	*lis;

	arr = create_array(stack);
	max_list = malloc(sizeof(int) * stack_len(*stack));
	i = -1;
	k = 0;
	while (++i < stack_len(*stack))
	{
		k = find_lis(arr, i, stack_len(*stack));
		max_list[i] = k;
		k = 0;
	}
	i = -1;
	index = 0;
	max = max_list[0];
	while (++i < stack_len(*stack))
		ft_lis2(&max, &max_list[i], &index, &i);
	lis = final_list(index, arr, stack_len(*stack));
	free(max_list);
	return (free(arr), push_lis_b(stack, b, &lis), free_list(lis), 0);
}

t_list	*final_list(int i, int *arr, int top)
{
	int		j;
	int		reminder;
	t_list	*stack;

	reminder = i;
	j = i + 1;
	push(&stack, arr[i]);
	if (j == top)
		j = 0;
	while (j != reminder)
	{
		if (arr[j] > arr[i])
		{
			push(&stack, arr[j]);
			i = j;
			j++;
		}
		else
			j++;
		if (j == top)
			j = 0;
	}
	return (stack);
}

int	find_lis(int *arr, int i, int top)
{
	int		j;
	int		k;
	int		reminder;

	reminder = i;
	k = 0;
	j = i + 1;
	if (j == top)
		j = 0;
	while (j != reminder)
	{
		if (arr[j] > arr[i])
		{
			k++;
			i = j;
			j++;
		}
		else
			j++;
		if (j == top)
			j = 0;
	}
	return (k);
}
