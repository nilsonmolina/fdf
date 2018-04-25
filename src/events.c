/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 19:01:38 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int key, t_canvas *c)
{
	printf("key code: %d\n", key);

	if (key == 53)
		exit(0);
	else if (key == 49)
		init_map(c);
	else if (key == 18)
		put_img_map(c);
	else if (key == 13)
		rotate_axis(c, &c->map.rot_x, ROT_DEGREES);
	else if (key == 1)
		rotate_axis(c, &c->map.rot_x, -ROT_DEGREES);
	else if (key == 0)
		rotate_axis(c, &c->map.rot_y, -ROT_DEGREES);
	else if (key == 2)
		rotate_axis(c, &c->map.rot_y, ROT_DEGREES);
	else if (key == 126)
		move_map(c, &c->map.move_y, -MOVE_PIXELS);
	else if (key == 125)
		move_map(c, &c->map.move_y, MOVE_PIXELS);
	else if (key == 123)
		move_map(c, &c->map.move_x, -MOVE_PIXELS);
	else if (key == 124)
		move_map(c, &c->map.move_x, MOVE_PIXELS);
	else if (key == 12)
		adjust_scale(c, &c->map.scale, -1);
	else if (key == 14)
		adjust_scale(c, &c->map.scale, 1);
	else if (key == 6)
		adjust_scale(c, &c->map.z_height, -1);
	else if (key == 7)
		adjust_scale(c, &c->map.z_height, 1);
	else
		ft_putstr("accepted buttons: 'space' or 'esc' keys.\n");
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_canvas *c)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(c->mlx, c->window);
	return (0);
}