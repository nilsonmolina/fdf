/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:48:35 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/08 11:01:38 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char*)s)[index] == (unsigned char)c)
			return (&((unsigned char *)s)[index]);
		index++;
	}
	return (NULL);
}
