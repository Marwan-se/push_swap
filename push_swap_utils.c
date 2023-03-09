/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:22:40 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/02 13:35:24 by msekhsou         ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
