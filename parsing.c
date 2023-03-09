/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:14:35 by msekhsou          #+#    #+#             */
/*   Updated: 2023/03/03 11:32:49 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dup_nbs(int ac, char **av)
{
    int i = 0;
    while (i < ac)
    {
        int j = i + 1;
        while (j < ac)
        {
            if (ft_strncmp(av[i], av[j], strlen(av[i])) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// int main()
// {
//     int i;
//     char *args[] = {"9", "9", NULL};
//     i = dup_nbs(2, args);
//     printf("%d\n", i);
// }