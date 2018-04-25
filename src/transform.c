/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:27 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 22:10:50 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		transform(t_map map, t_vector *v)
{
	float theta;

	v->x *= map.scale;
	v->y *= map.scale;
	v->z *= map.z_height;
	theta = set_theta(map.rot_x);
	v->y = v->y * cos(theta) - v->z * sin(theta);
	theta = set_theta(map.rot_y);
	v->x = v->x * cos(theta) + v->z * sin(theta);
	v->x += map.move_x;
	v->y += map.move_y;
	v->x += map.center_x;
	v->y += map.center_y;
}

void		set_scale(t_canvas *c)
{
	int scale_x;
	int scale_y;

	scale_x = (c->img.width - 200) / c->map.columns;
	scale_y = (c->img.height - 200) / c->map.rows;
	if (scale_x < scale_y)
		c->map.scale = scale_x / 1.2;
	else
		c->map.scale = scale_y / 1.2;
	if (c->map.scale == 0)
		c->map.scale = 1;
	c->map.z_height = c->map.scale / 2;
	c->map.min_scale = c->map.scale / 2;
}

float		set_theta(int degrees)
{
	float radians;

	if (degrees == 0)
		return (0);
	radians = degrees * (M_PI / 180);
	return (radians);
}

void		set_color(t_vector *v)
{
	if (v->z == 0)
		v->color = 0xFFFFFF;
	else if (v->z < 5)
		v->color = 0xFF8C00;
	else
		v->color = 0xFF00FF;
}
