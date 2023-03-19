/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:03 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/19 16:15:43 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_LIS(t_list **stack,t_list **b)
{
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
    while(i < stack_len(*stack))
    {
        k  = find_lis(arr,i,stack_len(*stack));
        max_list[i] = k;
        i++;
        k = 0;
    }
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
   tmp = lis;
    while (tmp)
    {
        printf("%d ,", tmp->content);
        tmp = tmp->next;
    }
    
    push_lis_b(stack,b,lis);
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

int find_var(t_list **long_list,int data)
{
    t_list *tmp = *long_list;
    while(tmp)
    {
        if(data == tmp->content)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
void    push_lis_b(t_list **a,t_list **b,t_list *longlist)
{
    int i = stack_len(*a);
    while(i)
    {
        if(find_var(&longlist,(*a)->content))
            ft_rotate(a, "ra\n");
        else
            push_to(a,b, "pb\n");
        i--;
    }
    push_lis_a(a,b);
}

void    push_lis_a(t_list **a, t_list **b)
{
    puts("b t a");
	while (stack_len(*b))
	{
        int data = (*b)->content;
        t_list *i = (*a);
        t_list *j = (*a)->next;
        t_list *tmp = i;
        int next_one = find_min(*a);//min
        int len = stack_len(*a);
        while(len--)
        {
            if(data > i->content && data < j->content)
            {
                next_one = j->content;
                break;
            }
            j = j->next;
            i = i->next;
            if(i == NULL)
            {
                i = tmp;
            }
            if(j == NULL)
            {
                j = tmp;
            }
        }
        tmp = (*a);
        len = stack_len(*a);
        int index = 0;
        while(len--)
        {
            if(tmp->content == next_one)
                break;
            tmp = tmp->next;
            index++;
        }
        // printf("{%d}\n",index);
        
        /// we have j;
        /// we need to move j int the top of a
        
        while((*a)->content != next_one)
        {
            if(index <= stack_len(*a)/2)
                ft_rotate(a, "ra\n");
            else
                ft_reverse_rotate(a,"rra\n");
        }
        push_to(b,a, "pa\n");
        int min = find_min(*a);
        while((*a)->content != min)
        {
            ft_rotate(a, "ra\n");
        }
	}
	
}