/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:27:57 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/15 16:42:29 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char *str, char delimiter)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != delimiter)
			count++;
		else if (str[i] != delimiter && str[i - 1] == delimiter)
			count++;
		i++;
	}
	return (count);
}
