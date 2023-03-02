/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:40 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 23:19:05 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned long nb)
{
	char	*up;
	int		len;

	len = 0;
	up = "0123456789ABCDEF";
	if (nb >= 0 && nb < 16)
		len += ft_putchar(up[nb % 16]);
	else
	{
		len += ft_puthexup(nb / 16);
		len += ft_putchar(up[nb % 16]);
	}
	return (len);
}
