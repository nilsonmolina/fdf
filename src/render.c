/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/23 18:35:57 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_canvas *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);	
	c->img.img = mlx_new_image(c->mlx, WINDOW_WIDTH - OFF_X, WINDOW_HEIGHT - OFF_Y);	
}

// void draw_line(t_canvas *c, int x0, int y0, int x1, int y1) {
	
// 	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
// 	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
// 	int err = (dx>dy ? dx : -dy)/2, e2;
 
// 	for(;;){
// 		put_img_pixel(&c->img, x0, y0, 0xFFFFFF);
//     	if (x0==x1 && y0==y1) break;
//     	e2 = err;
//     	if (e2 >-dx) { err -= dy; x0 += sx; }
//     	if (e2 < dy) { err += dx; y0 += sy; }
// 	}
// }

void		put_img_map(t_canvas *c)
{
	int i;

	clear_img(c);
	i = 0;
	while (i < (c->map.rows * c->map.columns))
		put_img_vector(c, c->map.vectors[i++]);
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, OFF_X, OFF_Y);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "render_map");
}

void		put_img_vector(t_canvas *c, t_vector vector)
{
	int 		i;
	t_vector	v;

	v = vector;
	transform(c->map, &v);
	if (v.x > c->img.width - 1 || v.x < 1)
		return ;
	i = (v.x) + ((v.y) * c->img.width);
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
