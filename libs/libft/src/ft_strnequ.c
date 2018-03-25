/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:00:57 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:50:13 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;
	size_t	count;

	if (!(s1 && s2))
		return (0);
	index = 0;
	count = 0;
	while (s1[index] && index < n)
	{
		if (s1[index] == s2[index])
			count++;
		index++;
	}
	return (count == index);
}
