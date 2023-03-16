/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:06:54 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/13 20:46:14 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list  *stack_bottom(t_list *stack)
{
	if (!stack)
		return (NULL);
	t_list	*current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

int find_max(t_list *top)
{
    int max;
	max = top->content;
    t_list *ptr = top;
    while (ptr != NULL)
    {
        if (ptr->content > max)
            max = ptr->content;
        ptr = ptr->next;
    }
    return max;
}

int find_min(t_list *top)
{
    int min = top->content;
    t_list *ptr = top;
    while (ptr != NULL)
    {
        if (ptr->content < min)
            min = ptr->content;
        ptr = ptr->next;
    }
    return min;
}
