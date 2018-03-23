/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:21:39 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/05 21:34:31 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int length;

	index = 0;
	length = 0;
	while (s1[length])
		length++;
	while (s2[index])
	{
		s1[length + index] = s2[index];
		index++;
	}
	s1[length + index] = '\0';
	return (s1);
}
