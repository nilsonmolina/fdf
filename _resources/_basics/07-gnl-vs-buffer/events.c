/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:50 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/09 22:30:17 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// remove this before turning in
#include <stdio.h>
#include <sys/time.h>
struct timeval stop, start;
//

int		key_pressed(int keycode, t_canvas *canvas)
{
	printf("key code: %d\n", keycode);
	// timing function speed.
	gettimeofday(&start, NULL);

	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		put_pixel_square(canvas);
	else if (keycode == 19)
		put_image_square(canvas);
	else if (keycode == 20)
		set_map(canvas);
	else if (keycode == 21)
		set_map2(canvas);
	else
		ft_putstr("accepted buttons: 'space' or 'esc' keys.\n");

	// timing function speed.
	gettimeofday(&stop, NULL);
	printf("took %d\n", stop.tv_usec - start.tv_usec);
	
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_canvas *canvas)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(canvas->mlx, canvas->window);
	return (0);
}