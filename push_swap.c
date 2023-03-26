/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:03 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/26 19:45:26 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index(t_list **stack, int value)
{
    t_list *current = *stack;
    int index = 0;
    while (current != NULL)
    {
        if (current->content == value)
            return index;
        current = current->next;
        index++;
    }
    return index;
}

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
//    tmp = lis;
//     while (tmp)
//     {
//         printf("%d ,", tmp->content);
//         tmp = tmp->next;
//     }
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
    sort_b_to_a(a,b);
}

void    push_lis_a(t_list **a, t_list **b)
{
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

int get_next_nb(t_list *a, int nb) {
        int data = nb;
        t_list *i = (a);
        t_list *j = (a)->next;
        t_list *tmp = i;
        int next_one = find_min(a);//min
        int len = stack_len(a);
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
    return next_one;
}

int get_at_index(t_list *list, int index)
{
    // Make sure the index is within bounds
    if (index < 0 || index >= stack_len(list))
        exit(1);

    // Traverse the list to the desired node
    t_list *current_node = list;
    int i = 0;
    while (i < index)
    {
        current_node = current_node->next;
        i++;
    }
    return current_node->content;
}

static int stack_number(t_list *a, t_list *b)
{
        int *count;
    int comp;
    int next_nbr;
    int i;
    t_list  *current = b;
    count = (int *)calloc(stack_len(b) + 1, sizeof(int));
    if (!count)
        exit(1);
    comp = 0;
    i = 0;
    while (current)
    {
        next_nbr = get_next_nb(a, current->content);
        count[i] = best_nb(a, b, current->content, next_nbr);
        if (count[i] <= count[comp])
            comp = i;
        
        current = current->next;
        i++;
    }
    return (get_at_index(b, comp));
}

void push_to_stack_a(t_list**a, t_list **b, int nb, int next_nb)
{
    int p;
    t_list  *a_current = (*a);
    t_list  *b_current = (*b);
    p = get_p(*a, *b, nb, next_nb);
    if (p == 1)
    {
        while (a_current->content != next_nb && b_current->content != nb)
        {
            if(a_current->content == next_nb)
                break;
            rr(a,b,"rr\n");
        a_current = (*a);
        b_current = (*b);
        }
    }
    else if (p == 2)
    {
        while (a_current->content != next_nb &&  b_current->content != nb)
        {
            if(a_current->content == next_nb)
                break;
            rrr(a,b,"rrr\n");
            a_current = (*a);
            b_current = (*b);
        }
    }
    while (a_current->content != next_nb)
    {
        if (get_index(a, next_nb) <= (stack_len(*a) - (stack_len(*a)) / 2))
            ft_rotate(a, "ra\n");
        else
            ft_reverse_rotate(a, "rra\n");
        a_current = *a;
    }
    while (b_current->content != nb)
    {
        if (get_index(b, nb) <= (stack_len(*b) - (stack_len(*b)) / 2))
            ft_rotate(b, "rb\n");
        else
            ft_reverse_rotate(b, "rrb\n");
        b_current = *b;
    }
    push_to(b, a, "pa\n");
}

void sort_b_to_a(t_list **a, t_list **b)
{
    int nb;
    int next_nb;
    int min;
    while (stack_len(*b) && *b != NULL)
    {
        nb = stack_number((*a), (*b));
        next_nb = get_next_nb((*a), nb);
        push_to_stack_a(a, b, nb, next_nb);
    }
    min = find_min((*a));
    while ((*a)->content != min)
    {
        if (get_index((a), min) <= (stack_len(*a)) / 2)
            ft_rotate(a, "ra\n");
        else
            ft_reverse_rotate((a), "rra\n");
    }
}

int best_nb(t_list *a, t_list *b, int nb, int next_nb)
{
    int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(&b, nb);
	next_nb_index = get_index(&a, next_nb);
	if (index >= stack_len(b) / 2)
		arr[0] = stack_len(b) - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= stack_len(a) / 2)
		arr[0] += stack_len(a) - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (stack_len(b) - index > stack_len(a) - next_nb_index)
		arr[2] = stack_len(b) - index;
	else
		arr[2] = stack_len(a) - next_nb_index;
	return (arr[get_min_index(arr, 3)]);
}

int get_p(t_list *a, t_list *b, int nb, int next_nb)
{
    int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(&b, nb);
	next_nb_index = get_index(&a, next_nb);
	if (index >= stack_len(b) / 2)
		arr[0] = stack_len(b) - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= stack_len(a) / 2)
		arr[0] += stack_len(a) - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (stack_len(b) - index > stack_len(a) - next_nb_index)
		arr[2] = stack_len(b) - index;
	else
		arr[2] = stack_len(a) - next_nb_index;
    return (get_min_index(arr, 3));
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
