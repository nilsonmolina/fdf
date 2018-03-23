/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:41:14 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/08 11:29:57 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long index;
	long number;
	long sign;

	index = 0;
	number = 0;
	sign = 1;
	while (IS_SPACE(str[index]))
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
		number = (number * 10) + (str[index++] - '0');
	return (number * sign);
}
