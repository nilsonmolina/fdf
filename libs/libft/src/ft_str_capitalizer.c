/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:11:39 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/14 19:08:40 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == ' ')
			str[i] = ft_toupper(str[i]);
		else
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
