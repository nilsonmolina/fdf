/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/10 00:41:04 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	    put_pixel_square(t_canvas *canvas)
{
	int x;
	int y;

	mlx_clear_window(canvas->mlx, canvas->window);	
	
	y = 50;
	while (y < 250)
	{
		x = 50;
		while (x < 250)
		{
			mlx_pixel_put(canvas->mlx, canvas->window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
    mlx_string_put(canvas->mlx, canvas->window, 10, 10, 0xFFFFFF, "put_pixel");	
}

void	    put_image_square(t_canvas *canvas)
{
	int x;
	int y;

	mlx_clear_window(canvas->mlx, canvas->window);

	y = 50;
	while (y < 250) 
	{
		x = 50;
		while (x < 250)
		{
			put_img_pixel(&canvas->img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->img.img, 0, 0);
	mlx_string_put(canvas->mlx, canvas->window, 10, 10, 0xFFFFFF, "put_image");
}

void        put_img_pixel(t_img *img, int x, int y, int color)
{
	int i;

    i = x + (y * img->width); 
    img->data[i] = color;
}

void        put_img_vector(t_img *img, t_vector vector)
{
	int i;

    i = vector.x + (vector.y * img->width); 
    img->data[i] = vector.color;
}