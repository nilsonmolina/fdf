/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:27 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 15:20:51 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		prepare(t_canvas c, t_vector *v)
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
	int	z;

	z = v->z * (map->z_height * map->scale);
	max_z = map->scale * map->max_z;
	if (z >= max_z * 1.5)
		v->color = RED;
	else if (z >= max_z)
		v->color = 0xFF9922;
	else if (max_z * 0.8 <= z && z < max_z)
		v->color = 0x999922;
	else if (max_z * 0.6 <= z && z < max_z * 0.8)
		v->color = GREEN;
	else if (max_z * 0.4 <= z && z < max_z * 0.6)
		v->color = 0x229999;
	else if (max_z * 0.2 <= z && z < max_z * 0.4)
		v->color = BLUE;
	else if (0 < z && z < max_z * 0.2)
		v->color = 0x222299;
	else if (z == 0)
		v->color = WHITE;
	else
		v->color = DGREY;
}
