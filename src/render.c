/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/18 16:57:05 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_canvas *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);	
}

void		put_image_map(t_canvas *c)
{
	int i;

	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);	
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	i = 0;
	while (i < (c->map.rows * c->map.columns))
		put_img_vector(&c->img, c->map.vectors[i++]);
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, 0, 0);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "render_map");
}

void		put_img_vector(t_img *img, t_vector vector)
{
	int i;

	i = (vector.x) + ((vector.y) * img->width);
	i *= 1;
	if (i > (WINDOW_HEIGHT * WINDOW_WIDTH))
		return ;
	img->data[i] = vector.color;
}
