/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:46:40 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/09 16:56:59 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int index;
	int count;

	if (!(s1 && s2))
		return (0);
	index = 0;
	count = 0;
	while (s1[index])
	{
		if (s1[index] == s2[index])
			count++;
		index++;
	}
	return (count == index && ft_strlen(s1) == ft_strlen(s2));
}
