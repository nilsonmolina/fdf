/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/17 17:17:38 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel_square(t_canvas *c)
{
	int x;
	int y;

	mlx_clear_window(c->mlx, c->window);
	y = 50;
	while (y < 250)
	{
		x = 50;
		while (x < 250)
		{
			mlx_pixel_put(c->mlx, c->window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "put_pixel");
}

void		put_image_square(t_canvas *c)
{
	int x;
	int y;

	mlx_clear_window(c->mlx, c->window);
	mlx_destroy_image(c->mlx, c->img.img);
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	y = 50;
	while (y < 250)
	{
		x = 50;
		while (x < 250)
		{
			put_img_pixel(&c->img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, 0, 0);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "put_image");
}

void		put_image_map(t_canvas *c)
{
	int i;

	mlx_destroy_image(c->mlx, c->img.img);
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	i = 0;
	while (i < (c->map.rows * c->map.columns))
	{
		put_img_vector(&c->img, c->map.vectors[i]);
		printf("x: %2d | y: %2d | color: %d\n", c->map.vectors[i].x, c->map.vectors[i].y, c->map.vectors[i].color);
		i++;
	}
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, 0, 0);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "render_map");
}

void	put_img_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + (y * img->width);
	img->data[i] = color;
}

void		put_img_vector(t_img *img, t_vector vector)
{
	int i;

	i = (vector.x + 50) + ((vector.y + 50) * img->width);
	img->data[i] = vector.color;
}
