/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:27 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/23 18:30:42 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        transform(t_map map, t_vector *v)
{
    float theta;
    
	// scale
    v->x *= map.scale;
	v->y *= map.scale;
	v->z *= map.z_height;
	// rotate
	theta = set_theta(map.rot_x);
	v->y = v->y * cos(theta) - v->z * sin(theta);
	theta = set_theta(map.rot_y);
	v->x = v->x * cos(theta) + v->z * sin(theta);
	// move
	v->x += map.move_x;
    v->y += map.move_y;
}

void		set_scale(t_canvas *c)
{
	int scaleX;
	int scaleY;

	scaleX = (c->img.width - 200) / c->map.columns;
	scaleY = (c->img.height - 200) / c->map.rows;
	if (scaleX < scaleY)
		c->map.scale = scaleX / 1.2;
	else
		c->map.scale = scaleY / 1.2;
	if (c->map.scale == 0)
		c->map.scale = 1;
	c->map.z_height = c->map.scale / 2;
	printf("%d", c->map.scale);
}

float	set_theta(int degrees)
{
	float radians;

	if (degrees == 0)
		return (0);
	radians = degrees * (M_PI / 180);
	return (radians);
}