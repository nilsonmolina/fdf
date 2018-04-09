/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/08 16:17:28 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// remove this before turning in
#include <stdio.h>
//

void 	    put_pixel_square(t_mlx *mlx)
{
	int x;
	int y;

	mlx_clear_window(mlx->mlx, mlx->window);	
	
	y = 50;
	while (y < 250)
	{
		x = 50;
		while (x < 250)
		{
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
    mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_pixel");	
}

void	    put_image_square(t_mlx *mlx)
{
	int x;
	int y;

	mlx_clear_window(mlx->mlx, mlx->window);

	y = 50;
	while (y < 250) 
	{
		x = 50;
		while (x < 250)
		{
			put_img_pixel(&mlx->img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_image");
}

void        put_img_pixel(t_img *img, int x, int y, int color)
{
	int i;

    i = x + (y * img->img_width); 
    img->img_data[i] = color;
}

void        put_img_vector(t_img *img, t_vector vector)
{
	int i;

    i = vector.x + (vector.y * img->img_width); 
    img->img_data[i] = vector.color;
}