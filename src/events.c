/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 01:05:54 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_up(int key, t_canvas *c)
{
	key == 53 ? exit(0) : 0;
	key == 49 ? init_map(c) : 0;
	key == 257 ? c->shft = 0 : 0;
	key == 48 ? c->mode *= -1 : 0;
	key == 8 ? c->color_on *= -1 : 0;
	if (key == 48 || key == 8)
		put_img_map(c);
	return (0);
}

int		key_hold(int key, t_canvas *c)
{
	t_map	*m;

	m = &c->map;
	key == 12 ? adjust_scale(c, -1) : 0;
	key == 14 ? adjust_scale(c, 1) : 0;
	key == 6 ? adjust_height(c, -0.1) : 0;
	key == 7 ? adjust_height(c, 0.1) : 0;
	key == 13 ? rotate_axis(c, &m->rot_x, ROT_DEGREES) : 0;
	key == 1 ? rotate_axis(c, &m->rot_x, -ROT_DEGREES) : 0;
	key == 0 ? rotate_axis(c, &m->rot_y, -ROT_DEGREES) : 0;
	key == 2 ? rotate_axis(c, &m->rot_y, ROT_DEGREES) : 0;
	key == 257 ? c->shft = 1 : 0;
	key == 126 && c->shft == 0 ? move_map(c, &m->move_y, -MV_PIXELS) : 0;
	key == 125 && c->shft == 0 ? move_map(c, &m->move_y, MV_PIXELS) : 0;
	key == 123 && c->shft == 0 ? move_map(c, &m->move_x, -MV_PIXELS) : 0;
	key == 124 && c->shft == 0 ? move_map(c, &m->move_x, MV_PIXELS) : 0;
	key == 126 && c->shft == 1 ? move_map(c, &m->move_y, -MV_PIXELS * 5) : 0;
	key == 125 && c->shft == 1 ? move_map(c, &m->move_y, MV_PIXELS * 5) : 0;
	key == 123 && c->shft == 1 ? move_map(c, &m->move_x, -MV_PIXELS * 5) : 0;
	key == 124 && c->shft == 1 ? move_map(c, &m->move_x, MV_PIXELS * 5) : 0;
	return (0);
}
