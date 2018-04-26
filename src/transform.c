/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:27 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/26 13:52:20 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		transform(t_canvas c, t_vector *v)
{
	float 	theta;
	int		x;
	int		y;
	int		z;

	x = v->x * c.map.scale;
	y = v->y * c.map.scale;
	z = v->z * (c.map.z_height * c.map.scale);
	c.color_on == 1 ? set_color(v, c.map) : 0;		
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

	sx = (c->img.width - 200) / c->map.columns;
	sy = (c->img.height - 200) / c->map.rows;
	(sx < sy) ? (c->map.scale = sx / 2) : (c->map.scale = sy / 2);
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

void		set_color(t_vector *v, t_map map)
{
	map.max_z *= map.scale;
	if (v->z == 0)
		v->color = 0xFFFFFF;
	else if (map.max_z <= v->z)
		v->color = 0xFF44FF;
	else if (map.max_z / 5 < v->z && v->z < map.max_z / 3)
		v->color = 0xAA4444;
	else if(map.max_z / 3 < v->z && v->z < map.max_z / 2)
		v->color = 0x44FF44;
	else if(map.max_z / 2 < v->z && v->z < map.max_z)
		v->color = 0x4444FF;
	else if (v->z < 0)
		v->color = 0xFF0000;
	else
		v->color = 0x444444;
}
