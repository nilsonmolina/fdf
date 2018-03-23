/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:32:40 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/06 10:54:59 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int index;

	index = 0;
	while (s[index])
		index++;
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
