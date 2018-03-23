/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:40:27 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/07 21:12:10 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	while ((s1[index] && s2[index]) && s1[index] == s2[index] && index < n - 1)
		index++;
	if (n)
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
