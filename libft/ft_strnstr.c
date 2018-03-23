/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:30:55 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/06 19:32:21 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t next;
	size_t little_length;

	i = 0;
	little_length = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (little[little_length] && little_length <= len)
		little_length++;
	while (big[i] && i <= len)
	{
		next = 0;
		while (big[i + next] == little[next] && little[next] && i + next < len)
			next++;
		if (next == little_length)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
