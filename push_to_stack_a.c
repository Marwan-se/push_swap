/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:28:28 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/15 02:45:17 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rr(t_list**a, t_list **b, t_list **a_current, t_list **b_current)
{
	rr(a, b, "rr\n");
	*a_current = (*a);
	*b_current = (*b);
}

void	psh_rrr(t_list**a, t_list **b, t_list **a_current, t_list **b_current)
{
	rrr(a, b, "rrr\n");
	*a_current = (*a);
	*b_current = (*b);
}

void	push_rra(t_list**a, t_list	**a_current, int *next_nb)
{
	if (get_index(a, *next_nb) <= (stack_len(*a) - (stack_len(*a)) / 2))
		ft_rotate(a, "ra\n");
	else
		ft_reverse_rotate(a, "rra\n");
		*a_current = *a;
}

void	push_rrb(t_list**b, t_list	**b_current, int *nb)
{
	if (get_index(b, *nb) <= (stack_len(*b) - (stack_len(*b)) / 2))
		ft_rotate(b, "rb\n");
	else
		ft_reverse_rotate(b, "rrb\n");
	*b_current = *b;
}

void	push_to_stack_a(t_list **a, t_list **b, int nb, int next_nb)
{
	int		p;
	t_list	**tmp;

	tmp = malloc(sizeof(t_list *) * 2);
	if (!tmp)
		return ;
	tmp[0] = (*a);
	tmp[1] = (*b);
	p = get_p(*a, *b, nb, next_nb);
	if (p == 1 || p == 2)
	{
		while ((tmp[0]->content != next_nb && tmp[1]->content != nb) \
		&& tmp[0]->content != next_nb)
		{
			if (p == 1)
				push_rr(a, b, &tmp[0], &tmp[1]);
			else if (p == 2)
				psh_rrr(a, b, &tmp[0], &tmp[1]);
		}
	}
	while (tmp[0]->content != next_nb)
		push_rra(a, &tmp[0], &next_nb);
	while (tmp[1]->content != nb)
		push_rrb(b, &tmp[1], &nb);
	psh_norm(a, b, tmp);
}
