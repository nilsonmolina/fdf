/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:36:58 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/05 17:09:42 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		index;

	dup = (char*)malloc(sizeof(*dup) * (ft_strlen(s1) + 1));
	index = 0;
	if (dup)
	{
		while (s1[index])
		{
			dup[index] = s1[index];
			index++;
		}
		dup[index] = '\0';
	}
	return (dup);
}
