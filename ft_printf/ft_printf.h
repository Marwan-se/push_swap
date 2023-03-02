/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:14 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 23:21:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<stdarg.h>
# include<unistd.h> 

int		ft_printf(const	char *str, ...);

int		ft_putchar(char c);
int		ft_puthexlow(unsigned long nb);
int		ft_puthexup(unsigned long nb);
int		ft_putnbr(long long nb);
int		ft_putnbr_u(unsigned long long nb);
int		ft_putstr(char *s);
int		ft_putadd(unsigned long long nb);

#endif