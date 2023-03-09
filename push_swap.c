/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:03 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/09 17:33:59 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_list	**stack_a;
// 	t_list	**stack_b;

// 	if (ac > 1)
// 	{
// 		stack_a = malloc(sizeof(t_list));
// 		if (!stack_a)
// 			return (0);
// 		stack_b = malloc(sizeof(t_list));
// 		if (!stack_b)
// 			return (0);
// 		*stack_a = 0;
// 		*stack_b = 0;
		
// 	}
// 	return (0);
// }
void ft_LIS(t_list **stack)
{
    // 1 find thi Longest Increasing Subsequence and put it in array
    int *arr = malloc(sizeof(int) * stack_len(*stack));
    t_list *tmp = *stack;
    int i = 0;
    while (tmp != NULL)
    {
        arr[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    int *max_list = malloc(sizeof(int) * stack_len(*stack));
    i = 0;
    int k = 0;
    while(i <  stack_len(*stack))
    {
        // printf("i = %d\n",i);
        k  = find_lis(arr,i,stack_len(*stack));
        max_list[i] = k;
        i++;
        k = 0;
    }
    //find the max in max_list
    i = 0;
    int index = 0;
    int max = max_list[0];
    while(i < stack_len(*stack) )
    {
        if(max < max_list[i])
        {
            max = max_list[i];
            index = i;
        }
        i++;
    }
    t_list *lis = final_list(index,arr,stack_len(*stack));
    while(lis)
    {
        printf("{%d}\n",lis->content);
        lis=lis->next;
    }
}

t_list *final_list(int i,int *arr,int top)
{
    int j;
    t_list *stack;
    int reminder = i;

    j = i+1;
    push(&stack,arr[i]);
    if(j == top)
        j = 0;
    while(j != reminder)
    {
        if(arr[j] > arr[i])
        {
            push(&stack,arr[j]);
            i = j;
            j++;
        }
        else
            j++;
        if(j == top)
            j = 0;
    }
    return (stack);
}
int find_lis(int *arr,int i,int top)
{
    int j;
    int k = 0;
    int reminder = i;

    j = i+1;
    if(j == top)
        j = 0;
    
    while(j != reminder)
    {
        if(arr[j] > arr[i])
        {
            k++;
            i = j;
            j++;
        }
        else
            j++;
        if(j == top)
            j = 0;
    }
    return (k);
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