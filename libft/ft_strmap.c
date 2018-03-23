/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:22:04 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/09 16:37:37 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			new[index] = f(s[index]);
			index++;
		}
		new[index] = '\0';
	}
	return (new);
}
