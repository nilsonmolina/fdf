/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:46:46 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/10 19:57:21 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		leading_ws(char const *str)
{
	int index;

	index = 0;
	while (IS_WS(str[index]))
		index++;
	return (index);
}

static int		trailing_ws(char const *str)
{
	int index;
	int length;

	length = ft_strlen(str) - 1;
	index = length;
	while (index > 0 && (IS_WS(str[index]) || str[index] == '\0'))
		index--;
	return (length - index);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		index;
	int		iterator;
	int		length;
	int		head;

	if (!s)
		return (NULL);
	head = leading_ws(s);
	length = ft_strlen(s) - head - trailing_ws(s);
	if (length < 0)
		return (ft_strcpy((char*)malloc(sizeof(char) + 1), ""));
	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (!str)
		return (NULL);
	index = 0;
	iterator = head;
	while (iterator < head + length)
		str[index++] = s[iterator++];
	str[index] = '\0';
	return (str);
}
