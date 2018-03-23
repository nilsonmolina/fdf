/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:21:39 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/05 21:16:51 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t length;

	index = 0;
	length = 0;
	while (s1[length])
		length++;
	while (s2[index] && index < n)
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
