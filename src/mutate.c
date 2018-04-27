/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:19:40 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 01:18:27 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_axis(t_canvas *c, int *axis, int degrees)
{
	int d;

	d = *axis + degrees;
	if (d >= 360)
		*axis = 0;
	else if (d <= 0)
		*axis = 355;
	else
		*axis = d;
	put_img_map(c);
}

void	adjust_scale(t_canvas *c, int direction)
{
	int s;

	s = c->map.scale;
	if (direction > 0)
	{
		s++;
		if (s * c->map.rows > WIN_HEIGHT * 5)
			s--;
		if (s * c->map.columns > WIN_WIDTH * 5)
			s--;
	}
	else
		s--;
	if (s < 1)
		s = 1;
	if (c->map.scale != s)
	{
		c->map.scale = s;
		put_img_map(c);
	}
}

void	move_map(t_canvas *c, int *axis, int pixels)
{
	*axis += pixels;
	put_img_map(c);
}

void	adjust_height(t_canvas *c, float direction)
{
	c->map.z_height += direction;
	put_img_map(c);
}
