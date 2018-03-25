/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:08:18 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:57:45 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	index;

	if (!s)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (len + 1));
	index = 0;
	if (new)
	{
		while (index < len)
			new[index++] = s[start++];
		new[index] = '\0';
		return (new);
	}
	return (NULL);
}
