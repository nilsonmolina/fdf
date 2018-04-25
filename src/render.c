/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 23:36:30 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_canvas *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);
	c->img.img = mlx_new_image(c->mlx, WIN_WIDTH - OFF_X, WIN_HEIGHT - OFF_Y);
}

void	draw_line(t_canvas *c, t_vector curr, t_vector next)
{
	t_line	l;

	l.dx = abs(next.x - curr.x);
	l.sx = curr.x < next.x ? 1 : -1;
	l.dy = abs(next.y - curr.y);
	l.sy = curr.y < next.y ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	next.z > curr.z ? curr.color += next.color : 0;
	while (1)
	{
		put_img_vector(c, curr);
		if (curr.x == next.x && curr.y == next.y)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			curr.x += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			curr.y += l.sy;
		}
	}
}

void	put_img_map(t_canvas *c)
{
	int			i;
	t_vector	v;
	t_vector	down;

	clear_img(c);
	i = 0;
	while (i < (c->map.rows * c->map.columns))
	{
		v = c->map.vectors[i];
		transform(c->map, &v);
		if (i < (c->map.rows * c->map.columns) - c->map.columns)
		{
			down = c->map.vectors[i + c->map.columns];
			transform(c->map, &down);
			draw_line(c, v, down);
			put_img_vector(c, down);
		}
		if (i > 0 && i % c->map.columns != 0)
			draw_line(c, v, c->map.previous);
		put_img_vector(c, v);
		c->map.previous = v;
		i++;
	}
	mlx_put_image_to_window(c->mlx, c->window, c->img.img, OFF_X, OFF_Y);
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, c->filename);
}

void	put_img_vector(t_canvas *c, t_vector v)
{
	int	i;

	if (v.x > c->img.width - 1 || v.x < 1)
		return ;
	i = (v.x) + ((v.y) * c->img.width);
	if (i > (c->img.width * c->img.height) || i < 0)
		return ;
	c->img.data[i] = v.color;
}
