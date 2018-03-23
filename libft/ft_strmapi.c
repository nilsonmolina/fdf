/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:37:45 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:48:20 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		index;

	if (!(s && f))
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (ft_strlen(s) + 1));
	index = 0;
	if (new)
	{
		while (s[index])
		{
			new[index] = f(index, s[index]);
			index++;
		}
		new[index] = '\0';
	}
	return (new);
}
