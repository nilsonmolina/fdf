/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:29:25 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:48:56 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;
	int		iterator;

	if (!(s1 && s2))
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!str)
		return (NULL);
	index = 0;
	iterator = 0;
	while (s1[iterator])
		str[index++] = s1[iterator++];
	iterator = 0;
	while (s2[iterator])
		str[index++] = s2[iterator++];
	str[index] = '\0';
	return (str);
}
