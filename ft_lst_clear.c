/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:46:47 by msekhsou          #+#    #+#             */
/*   Updated: 2023/02/28 22:02:09 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*yes;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		yes = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = yes;
	}
	*lst = NULL;
}

void	show(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
			printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

// static void	delt(void *data)
// {
// 	free (data);
// }
