/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/02 18:40:01 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_mlx mlx;

	init(&mlx);

	mlx_string_put(mlx.mlx, mlx.window, 10, 10, 0xFFFFFF, "'1' - put_pixel");
	mlx_string_put(mlx.mlx, mlx.window, 10, 40, 0xFFFFFF, "'2' - put_image");
	
	mlx_key_hook(mlx.window, key_pressed, &mlx);
	mlx_mouse_hook(mlx.window, mouse_clicked, &mlx);
	mlx_loop(mlx.mlx);
}

void	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
	mlx->img.img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img.img_data = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx->img.img_width = WINDOW_WIDTH;
}