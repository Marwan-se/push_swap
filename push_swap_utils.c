/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:22:40 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/15 02:46:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int data)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = data;
	l->next = NULL;
	return (l);
}

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst != NULL)
	{
		l++;
		lst = lst->next;
	}
	return (l);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		i = ft_lstlast(*lst);
		if (i)
		{
			i->next = new;
		}
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL && new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
