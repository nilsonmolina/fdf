/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:59:24 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/09 12:29:45 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		index;

	str = (char *)malloc(sizeof(char) * size + 1);
	index = 0;
	if (!str)
		return (NULL);
	while (str[index])
		str[index++] = '\0';
	return (str);
}
