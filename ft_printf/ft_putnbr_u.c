/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:37:17 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 23:21:08 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned long long nb)
{
	int	lenth;

	lenth = 0;
	if (nb >= 0 && nb < 10)
	{
		lenth += ft_putchar(nb + 48);
	}
	else
	{
		lenth += ft_putnbr_u(nb / 10);
		lenth += ft_putnbr_u(nb % 10);
	}
	return (lenth);
}
