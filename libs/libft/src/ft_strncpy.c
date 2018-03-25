/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:24:58 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/05 18:45:22 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < ft_strlen(src) && index < len)
	{
		if (src[index] == '\0')
			dst[index] = '\0';
		else
			dst[index] = src[index];
		index++;
	}
	while (index < len)
		dst[index++] = '\0';
	return (dst);
}
