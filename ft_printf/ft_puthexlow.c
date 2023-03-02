/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:37 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 22:57:24 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(unsigned long nb)
{
	char	*x;
	int		len;

	len = 0;
	x = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		len += ft_putchar(x[nb % 16]);
	else
	{
		len += ft_puthexlow(nb / 16);
		len += ft_putchar(x[nb % 16]);
	}
	return (len);
}
