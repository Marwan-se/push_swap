/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:07:29 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/12 20:42:41 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long long nb)
{
	int	ret;

	ret = 0;
	ret += ft_putstr("0x");
	ret += ft_puthexlow(nb);
	return (ret);
}
