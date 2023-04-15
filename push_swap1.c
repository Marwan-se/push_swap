/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:38:22 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/13 12:28:38 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_number(t_list *a, t_list *b)
{
	int		*count;
	int		comp;
	int		next_nbr;
	int		i;
	t_list	*current;

	current = b;
	count = (int *)calloc(stack_len(b) + 1, sizeof(int));
	if (!count)
		exit(1);
	comp = 0;
	i = 0;
	while (current)
	{
		next_nbr = get_next_nb(a, current->content, NULL, NULL);
		count[i] = best_nb(a, b, current->content, next_nbr);
		if (count[i] <= count[comp])
			comp = i;
		current = current->next;
		i++;
	}
	free(count);
	return (get_at_index(b, comp));
}

void	sort_b_to_a(t_list **a, t_list **b)
{
	int	nb;
	int	next_nb;
	int	min;

	while (stack_len(*b) && *b != NULL)
	{
		nb = stack_number((*a), (*b));
		next_nb = get_next_nb((*a), nb, NULL, NULL);
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

// returns the index of the best push operation

int	best_nb(t_list *a, t_list *b, int nb, int next_nb)
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

// returns the minimum score of each possible push operation

int	get_p(t_list *a, t_list *b, int nb, int next_nb)
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

void	psh_norm(t_list **a, t_list **b, t_list **tmp)
{
	free(tmp);
	push_to(b, a, "pa\n");
}
