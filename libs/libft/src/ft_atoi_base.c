/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:20:05 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/02 15:23:26 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     test_base(const char c)
{
    int nb;

    if (c >= '0' && c <= '9')
        nb = c - '0';
    else if (c >= 'a' && c <= 'z')
        nb = c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        nb = c - 'A' + 10;
    else
        nb = -1;
        
    return (nb);
}

int     ft_atoi_base(const char *str, int base)
{
    int i;
    int sign;
    int nb;
    int current;

    i = 0;
    nb = 0;
    while (IS_SPACE(str[i]))
        i++;
    sign = (str[i] == '-' ? -1 : 1);
    if (str[i] == '-' || str[i] == '+')
        i++;
    current = test_base(str[i]);
    while (current >= 0 && current < base)
    {
        nb = nb * base + current;
        i++;
        current = test_base(str[i]);
    }

    return (sign * nb);
}
