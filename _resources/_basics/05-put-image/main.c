/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/01 21:01:21 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <sys/time.h>
struct timeval stop, start;

void 	put_pixel_square(t_mlx *mlx)
{
	int x;
	int y;

	mlx_clear_window(mlx->mlx, mlx->window);	
	
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
		mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_pixel");	
}

void	put_image_square(t_mlx *mlx)
{
	t_img square;
	int i = 0;
	int x = 0;
	int y = 0;

	mlx_clear_window(mlx->mlx, mlx->window);

	square.img = mlx_new_image(mlx->mlx, 100, 100);
	square.img_data = mlx_get_data_addr(square.img, &square.bpp, &square.stride, &square.endian);
	square.bpp /= 8;

	while (y < 100) 
	{
		while (x < 100)
		{
			i = (x * 4) + (y * square.stride);
			square.img_data[i++] = (char)255; // blue
			square.img_data[i++] = (char)255; // green
			square.img_data[i++] = (char)255; // red
			x++;
		}
		y++;
		x = 0;
	}

	mlx_put_image_to_window(mlx->mlx, mlx->window, square.img, 50, 50);
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_image");
}

int		key_pressed(int keycode, t_mlx *mlx)
{
	printf("key code: %d\n", keycode);
	// timing function speed.
	gettimeofday(&start, NULL);

	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		put_pixel_square(mlx);
	else if (keycode == 19)
		put_image_square(mlx);
	else
		ft_putstr("accepted buttons: 'space' or 'esc' keys.\n");

	// timing function speed.
	gettimeofday(&stop, NULL);
	printf("took %d\n", stop.tv_usec - start.tv_usec);
	
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_mlx *mlx)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		mlx_clear_window(mlx->mlx, mlx->window);
	return (0);
}

int		main(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");

	mlx_string_put(mlx.mlx, mlx.window, 10, 10, 0xFFFFFF, "'1' - put_pixel");
	mlx_string_put(mlx.mlx, mlx.window, 10, 40, 0xFFFFFF, "'2' - put_image");
	
	mlx_key_hook(mlx.window, key_pressed, &mlx);
	mlx_mouse_hook(mlx.window, mouse_clicked, &mlx);
	mlx_loop(mlx.mlx);
}