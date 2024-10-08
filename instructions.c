/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:33:32 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/25 19:44:25 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_f(t_list **s, char *str)
{
	int	data1;
	int	data2;

	data1 = pop(s);
	data2 = pop(s);
	push(s, data1);
	push(s, data2);
	if (!str)
		return ;
	ft_printf("%s", str);
}

void	ss(t_list *a, t_list *b, char *str)
{
	swap_f(&a, NULL);
	swap_f(&b, NULL);
	if (!str)
		return ;
	ft_printf("%s", str);
}

void	push_to(t_list **from, t_list **to, char *str)
{
	int	data;

	data = pop(from);
	push(to, data);
	if (!str)
		return ;
	ft_printf("%s", str);
}

void	ft_rotate(t_list **s, char *str)
{
	int		data;
	t_list	*new;

	data = pop(s);
	new = ft_lstnew(data);
	ft_lstadd_back(s, new);
	if (!str)
		return ;
	ft_printf(str);
}

void	rr(t_list **a, t_list **b, char *str)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	if (!str)
		return ;
	ft_printf("%s", str);
}
