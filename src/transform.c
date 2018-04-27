/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:27 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/26 19:22:03 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		transform(t_canvas c, t_vector *v)
{
	float	theta;
	int		x;
	int		y;
	int		z;

	x = v->x * c.map.scale;
	y = v->y * c.map.scale;
	z = v->z * (c.map.z_height * c.map.scale);
	c.color_on == 1 ? set_color(v, &c.map) : 0;
	theta = set_theta(c.map.rot_y);
	v->x = x * cos(theta) - z * sin(theta);
	v->z = z * cos(theta) + x * sin(theta);
	theta = set_theta(c.map.rot_x);
	v->y = y * cos(theta) - z * sin(theta);
	v->z = z * cos(theta) + y * sin(theta);
	v->x += c.map.move_x;
	v->y += c.map.move_y;
	v->x += c.map.center_x;
	v->y += c.map.center_y;
}

void		set_scale(t_canvas *c)
{
	int sx;
	int sy;

	c->map.scale = 0;
	sx = (c->img.width - 200) / c->map.columns;
	sy = (c->img.height - 200) / c->map.rows;
	if (sx < sy)
		c->map.scale = sx / 2;
	else
		c->map.scale = sy / 2;
	c->map.scale == 0 ? c->map.scale = 1 : 0;
}

float		set_theta(int degrees)
{
	float radians;

	if (degrees == 0)
		return (0);
	radians = degrees * (M_PI / 180);
	return (radians);
}

void		set_color(t_vector *v, t_map *map)
{
	int	max_z;

	max_z = map->scale * map->max_z;
	if (v->z == 0)
		v->color = 0xFFFFFF;
	else if (max_z <= v->z)
		v->color = 0xFF44FF;
	else if (max_z / 5 < v->z && v->z < max_z / 3)
		v->color = 0xAA4444;
	else if (max_z / 3 < v->z && v->z < max_z / 2)
		v->color = 0x44FF44;
	else if (max_z / 2 < v->z && v->z < max_z)
		v->color = 0x4444FF;
	else if (v->z < 0)
		v->color = 0xFF0000;
	else
		v->color = 0x444444;
}
