/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:43 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 20:45:33 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb)
{
	int	lenth ;

	lenth = 0;
	if (nb >= 0 && nb < 10)
	{
		lenth += ft_putchar(nb + 48);
	}
	else if (nb < 0)
	{
		lenth += ft_putchar('-');
		nb *= -1;
		lenth += ft_putnbr(nb);
	}
	else
	{
		lenth += ft_putnbr(nb / 10);
		lenth += ft_putnbr(nb % 10);
	}
	return (lenth);
}
