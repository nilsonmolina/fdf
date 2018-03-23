/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:07:35 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/08 15:20:00 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = -1;
	if (src < dst)
		while ((int)(--len) >= 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
		while (++index < len)
			((char *)dst)[index] = ((char *)src)[index];
	return (dst);
}
