/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/22 19:30:34 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int key, t_canvas *c)
{
	printf("key code: %d\n", key);

	if (key == 53)
		exit(0);
	else if (key == 49)
		clear_img(c);
	else if (key == 18)
		put_img_map(c);
	else if (key == 19)
		print_map(c);
	else if (key == 13)
		rotate_x(c, -15);
	else if (key == 1)
		rotate_x(c, 15);
	else if (key == 126)
		c->map.move_y -= 10;
	else if (key == 125)
		c->map.move_y += 10;
	else if (key == 123)
		c->map.move_x -= 10;
	else if (key == 124)
		c->map.move_x += 10;
	else
		ft_putstr("accepted buttons: 'space' or 'esc' keys.\n");
	if ((123 <= key && key <= 126) || key == 13 || key == 1)
		put_img_map(c);
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_canvas *c)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(c->mlx, c->window);
	return (0);
}