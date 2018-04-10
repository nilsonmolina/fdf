/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/09 17:11:31 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// remove this before turning in
#include <stdio.h>
#include <sys/time.h>
struct timeval stop, start;
//

int		main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		write(1, "error\n", 6);
	
	return (0);
}

void	fdf(char *filename)
{
	t_mlx mlx;

	init_mlx(&mlx);
	mlx.map.filename = filename;

	mlx_string_put(mlx.mlx, mlx.window, 10, 10, 0xFFFFFF, filename);
	mlx_string_put(mlx.mlx, mlx.window, 10, 30, 0xAAAAAA, "'1' - put_pixel");
	mlx_string_put(mlx.mlx, mlx.window, 10, 50, 0xAAAAAA, "'2' - put_image");
	mlx_string_put(mlx.mlx, mlx.window, 10, 70, 0xAAAAAA, "'3' - benchmark_read");
	
	mlx_key_hook(mlx.window, key_pressed, &mlx);
	mlx_mouse_hook(mlx.window, mouse_clicked, &mlx);
	mlx_loop(mlx.mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "nmolina fdf");
	mlx->img.img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img.img_data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx->img.img_width = WINDOW_WIDTH;
}