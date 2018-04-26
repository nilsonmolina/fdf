/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:19:40 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/25 16:54:00 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_axis(t_canvas *c, int *axis, int degrees)
{
	int d;

	d = *axis + degrees;
	if (d >= 360)
		*axis = 0 + (d - 360);
	else if (d <= 0)
		*axis = 360 - (0 - d);
	else
		*axis = d;
	put_img_map(c);
}

void	adjust_scale(t_canvas *c, int direction)
{
	double s;

	direction > 0 ? (s = c->map.scale *= 1.2) : (s = c->map.scale /= 1.2);
	if (s < 1 && direction > 0)
		s = 1;
	if (s == c->map.scale && direction > 0)
		s++;
	if (s * c->map.rows > WIN_HEIGHT * 4)
		s = (WIN_HEIGHT * 4) / c->map.rows;
	else if (s * c->map.columns > WIN_WIDTH * 4)
		s = (WIN_WIDTH * 4) / c->map.columns;
	if (s < 1)
		s = 1;
	c->map.scale = s;
	put_img_map(c);
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
