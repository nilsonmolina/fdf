/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/17 23:08:53 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int keycode, t_canvas *c)
{
	printf("key code: %d\n", keycode);

	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		put_pixel_square(c);
	else if (keycode == 19)
		put_image_square(c);
	else if (keycode == 20)
		put_image_map(c);
	else if (keycode == 21)
		print_map(c);
		
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