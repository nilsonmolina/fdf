/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:59:10 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/06 10:30:25 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int index;
	int next;
	int little_length;

	index = 0;
	little_length = 0;
	if (little[index] == '\0')
		return ((char *)big);
	while (little[little_length])
		little_length++;
	while (big[index])
	{
		next = 0;
		while (big[index + next] == little[next] && little[next])
			next++;
		if (next == little_length)
			return ((char *)(big + index));
		index++;
	}
	return (0);
}
