/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:31:34 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/05 21:38:31 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len++;
	if (size == len)
		return (size + ft_strlen(src));
	while (src[i])
	{
		if (i < (size - len - 1))
			dst[len + i] = src[i];
		else
			break ;
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
