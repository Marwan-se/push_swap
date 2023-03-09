/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:43:34 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/09 17:34:14 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP

# define PUSH_SWAP

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				t_list;

typedef struct Stack
{
    struct s_list	*top;
}	t_stack;


t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		isEmpty(t_list *stack);
void	push(t_list **stk, int data);
int		pop(t_list** stk);
void	swap_f(t_list **a);
void	ss(t_list	*a,t_list *b);
void	push_to(t_list **from,t_list **to);
void	ft_rotate(t_list **s);
void	rr(t_list *a,t_list *b);
void	ft_reverse_rotate(t_list **stack);
void	rrr(t_list *a,t_list *b);
int		find_max(t_list *top);
void	sort_3(t_list **stack);
int		dup_nbs(int argc, char **argv);
void	sort_2(t_list **stack);
void	sort5(t_list **a, t_list **b);
int		find_min(t_list *top);
int		stack_len(t_list *stack);
t_list	*stack_bottom(t_list *stack);
void ft_LIS(t_list **stack);
int find_lis(int *arr,int i,int top);
t_list *final_list(int i,int *arr,int top);

#endif