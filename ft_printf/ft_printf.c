/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:46 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/13 16:44:33 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list *arg)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar(c);
	else if (c == 'c')
		len += ft_putchar(va_arg(*arg, int));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*arg, int));
	else if (c == 'u')
		len += ft_putnbr_u(va_arg(*arg, unsigned int));
	else if (c == 'X')
		len += ft_puthexup(va_arg(*arg, unsigned int));
	else if (c == 'x')
		len += ft_puthexlow(va_arg(*arg, unsigned int));
	else if (c == 'p')
		len += (ft_putstr("0x") + ft_puthexlow(\
			va_arg(*arg, unsigned long int)));
	else if (c == 's')
		len += ft_putstr(va_arg(*arg, char *));
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const	char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			count += ft_check(str[i + 1], &arg);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
