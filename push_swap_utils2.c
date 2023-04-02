/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:33:16 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/29 13:05:23 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(char *str)
{
	long	x;
	int		sign;
	long	res;

	x = 0;
	res = 0;
	sign = 1;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] != '\0' && str[x] >= '0' && str[x] <= '9')
	{
		res *= 10;
		res += str[x] - 48;
		x++;
	}
	return (res * sign);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pointer;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	pointer = (char *)malloc(sizeof(char) * len);
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, s1, len);
	ft_strlcat(pointer, s2, len);
	return (pointer);
}
