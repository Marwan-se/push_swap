/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:43:34 by msekhsou          #+#    #+#             */
/*   Updated: 2023/04/15 15:54:22 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}				t_stack;

t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		is_empty(t_list *stack);
void	push(t_list **stk, int data);
int		pop(t_list **stk);
void	swap_f(t_list **a, char *str);
void	ss(t_list *a, t_list *b, char *str);
void	push_to(t_list **from, t_list **to, char *str);
void	ft_rotate(t_list **s, char *str);
void	rr(t_list **a, t_list **b, char *str);
void	ft_reverse_rotate(t_list **stack, char *str);
void	rrr(t_list **a, t_list **b, char *str);
int		find_max(t_list *top);
void	sort_3(t_list **stack);
void	sort_2(t_list **stack);
void	sort5(t_list **a, t_list **b);
int		find_min(t_list *top);
int		stack_len(t_list *stack);
t_list	*stack_bottom(t_list *stack);
int		ft_lis(t_list **stack, t_list **b, int index, int *arr);
int		find_lis(int *arr, int i, int top);
t_list	*final_list(int i, int *arr, int top);
void	push_lis_b(t_list **a, t_list **b, t_list **longlist);
int		find_var(t_list **long_list, int data);
size_t	ft_strlen(char *str);
int		dup_nbs(int ac, char **av);
int		check_for_char(int ac, char **av);
int		ft_isdigit(int c);
long	ft_atoi(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
size_t	space_number(char *arg);
int		arg_empty(char **arg);
char	**arguments(int ac, char **av);
int		best_nb(t_list *a, t_list *b, int nb, int next_nb);
int		get_p(t_list *a, t_list *b, int nb, int next_nb);
int		get_index(t_list **stack, int value);
int		get_min_index(int *arr, int size);
void	sort_b_to_a(t_list **a, t_list **b);
void	push_to_stack_a(t_list **a, t_list **b, int nb, int next_nb);
int		get_next_nb(t_list *a, int data, t_list *i, t_list *j);
int		get_at_index(t_list *list, int index);
int		stack_sorted(t_list *stack);
void	sort_args(t_list **a, t_list **b, int args);
int		*create_array(t_list **stack);
void	push_to_stack_a(t_list **a, t_list **b, int nb, int next_nb);
void	free_list(t_list *head);
void	push_rr(t_list**a, t_list **b, t_list **a_current, t_list **b_current);
void	psh_rrr(t_list**a, t_list **b, t_list **a_current, t_list **b_current);
void	push_rra(t_list**a, t_list	**a_current, int *next_nb);
void	push_rrb(t_list**b, t_list	**b_current, int *nb);
void	psh_norm(t_list **a, t_list **b, t_list **tmp);
void	free_for_norm(char **t, t_list *a, t_list *b);

#endif