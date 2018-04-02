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

#include "fdf.h"
#include <stdio.h> // remove this before turning in

void 	draw(t_mlx *mlx)
{
	int x;
	int y;
	
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xBBFFFFFF, "Hello World!");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xBBFFFFFF);
			x++;
		}
		y++;
	}
}

int		key_pressed(int keycode, t_mlx *mlx)
{
	printf("key code: %d\n", keycode);
	if (keycode == 49)
		mlx_clear_window(mlx->mlx, mlx->window);
	else if (keycode == 53)
		exit(0);
	else
		ft_putstr("accepted buttons: 'space' or 'esc' keys.\n");
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_mlx *mlx)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(mlx->mlx, mlx->window);
	draw(mlx);
	return (0);
}

int		main(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");

	draw(&mlx);
	
	mlx_key_hook(mlx.window, key_pressed, &mlx);
	mlx_mouse_hook(mlx.window, mouse_clicked, &mlx);
	mlx_loop(mlx.mlx);
}

// int		main(void)
// {
// 	t_mlx *mlx;

// 	mlx = ft_memalloc(sizeof(t_mlx));
// 	mlx->mlx = mlx_init();
// 	mlx->window = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");

// 	draw(mlx);
	
// 	mlx_key_hook(mlx->window, key_pressed, mlx);
// 	mlx_mouse_hook(mlx->window, mouse_clicked, mlx);
// 	mlx_loop(mlx->mlx);
// }
