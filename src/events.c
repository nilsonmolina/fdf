/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 22:11:37 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int key, t_canvas *c)
{
	(key == 53) ? exit(0) : 0;
	(key == 49) ? init_map(c) : 0;
	(key == 18) ? put_img_map(c) : 0;
	(key == 13) ? rotate_axis(c, &c->map.rot_x, ROT_DEGREES) : 0;
	(key == 1) ? rotate_axis(c, &c->map.rot_x, -ROT_DEGREES) : 0;
	(key == 0) ? rotate_axis(c, &c->map.rot_y, -ROT_DEGREES) : 0;
	(key == 2) ? rotate_axis(c, &c->map.rot_y, ROT_DEGREES) : 0;
	(key == 126) ? move_map(c, &c->map.move_y, -MOVE_PIXELS) : 0;
	(key == 125) ? move_map(c, &c->map.move_y, MOVE_PIXELS) : 0;
	(key == 123) ? move_map(c, &c->map.move_x, -MOVE_PIXELS) : 0;
	(key == 124) ? move_map(c, &c->map.move_x, MOVE_PIXELS) : 0;
	(key == 12) ? adjust_scale(c, &c->map.scale, -1) : 0;
	(key == 14) ? adjust_scale(c, &c->map.scale, 1) : 0;
	(key == 6) ? adjust_scale(c, &c->map.z_height, -1) : 0;
	(key == 7) ? adjust_scale(c, &c->map.z_height, 1) : 0;
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_canvas *c)
{
	button = 0;
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(c->mlx, c->window);
	return (0);
}
