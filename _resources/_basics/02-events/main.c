/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/14 19:36:17 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include <stdio.h>
int		key_pressed(int keycode, void *param)
{
	printf("key code: %d\t- param: %p\n", keycode, param);
	return (0);
}

int		mouse_clicked(int button, int x, int y) // can also accept void *param as an argument - see key_pressed
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	return (0);
}

int		main(void)
{
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x11FFFFFF); // color: 0x(Alpha)(Red)(Green)(Blue)
			x++;
		}
		y++;
	}
	mlx_key_hook(win, key_pressed, (void *)13);
	mlx_mouse_hook(win, mouse_clicked, (void *)0);
	mlx_loop(mlx);
}
