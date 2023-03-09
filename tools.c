/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:30:55 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/02 12:55:17 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isEmpty(t_list *stack)
{
    return !stack;
}

void	push(t_list **stk, int data)
{
    t_list* stackNode = ft_lstnew(data);
    stackNode->next = *stk;
    *stk = stackNode;
}

int pop(t_list** stk)
{
    if (isEmpty(*stk))
        return INT_MIN;
    t_list* temp = *stk;
    *stk = (*stk)->next;
    int popped = temp->content;
    free(temp);
    return popped;
}