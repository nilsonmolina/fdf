/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/22 19:31:46 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_canvas *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);	
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH - OFF_X, WINDOW_HEIGHT - OFF_Y);	
}

void		put_img_map(t_canvas *c)
{
	int i;

	clear_img(c);
	set_scale(c);
	// set_center(c);

	i = 0;
	while (i < (c->map.rows * c->map.columns))
		put_img_vector(c, c->map.vectors[i++]);
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, 100, 100);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "render_map");
}

void		put_img_vector(t_canvas *c, t_vector vector)
{
	int 		i;
	t_vector	v;

	v = vector;
	transform(c->map, &v);
	i = (v.x) + ((v.y) * c->img.width);
	i *= 1;
	if (i > (c->img.width * c->img.height) || i < 0)
		return ;
	c->img.data[i] = v.color;
}

/*
	DONE: x = x * scaling factor;
	DONE: y = y * scaling factor;
	DONE: z = z * scaling factor;

	Rotation:
	rotation_x:
	theta = convert_degrees_to_radian(degrees_x)
	y = formula
	z = formala

	rotate_y:
	theta = convert_degrees_to_radian(degrees_y)
	x = formula
	z = formula
	rotate_z
	theta = convert_degrees_to_radian(degrees_z)
	y = formual
	x = formula

	Center:

	x = WIDTH/2
	y = Height/2 somesnit like that

	vector.x = x
	vector.y = y
*/
