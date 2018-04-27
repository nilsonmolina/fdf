/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 02:15:55 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_canvas *c)
{
	mlx_clear_window(c->mlx, c->window);
	ft_bzero(c->img.data, sizeof(int) * c->img.width * c->img.height);
}

void	put_strings(void *mlx, void *w, t_canvas *c)
{
	char *str;

	mlx_string_put(mlx, w, 10, 10, WHITE, "File:");
	mlx_string_put(mlx, w, 70, 10, WHITE, c->filename);
	if (c->mode == 1)
		mlx_string_put(mlx, w, 20, 30, GREEN, "Mode: 'put_image'");
	else
		mlx_string_put(mlx, w, 20, 30, RED, "Mode: 'put_pixel'");
	if (c->color_on == 1)
		mlx_string_put(mlx, w, 20, 50, GREEN, "Color: 'dynamic'");
	else
		mlx_string_put(mlx, w, 20, 50, RED, "Color: 'static'");
	mlx_string_put(mlx, w, 20, 70, GREY, "Scale:");
	mlx_string_put(mlx, w, 120, 70, GREY, str = ft_itoa(c->map.scale));
	free(str);
	mlx_string_put(mlx, w, 20, 90, GREY, "Height:");
	mlx_string_put(mlx, w, 120, 90, GREY, str = ft_itoa(c->map.z_height * 10));
	free(str);
	mlx_string_put(mlx, w, 20, 110, GREY, "Rot_X:");
	mlx_string_put(mlx, w, 120, 110, GREY, str = ft_itoa(c->map.rot_y));
	free(str);
	mlx_string_put(mlx, w, 20, 130, GREY, "Rot_Y:");
	mlx_string_put(mlx, w, 120, 130, GREY, str = ft_itoa(c->map.rot_x));
	free(str);
}

void	draw_line(t_canvas *c, t_vector start, t_vector end)
{
	t_line	l;

	l.dx = abs(end.x - start.x);
	l.sx = start.x < end.x ? 1 : -1;
	l.dy = abs(end.y - start.y);
	l.sy = start.y < end.y ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		put_img_vector(c, start);
		if (start.x == end.x && start.y == end.y)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			start.x += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			start.y += l.sy;
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
		prepare(*c, &v);
		if (i < (c->map.rows * c->map.columns) - c->map.columns)
		{
			down = c->map.vectors[i + c->map.columns];
			prepare(*c, &down);
			draw_line(c, v, down);
			put_img_vector(c, down);
		}
		(i > 0 && i % c->map.columns != 0) ? draw_line(c, c->map.prev, v) : 0;
		put_img_vector(c, v);
		c->map.prev = v;
		i++;
	}
	if (c->mode == 1)
		mlx_put_image_to_window(c->mlx, c->window, c->img.img, OFF_X, OFF_Y);
	put_strings(c->mlx, c->window, c);
}

void	put_img_vector(t_canvas *c, t_vector v)
{
	int	i;

	if (c->mode == 1)
	{
		if (v.x > c->img.width - 1 || v.x < 1)
			return ;
		i = (v.x) + ((v.y) * c->img.width);
		if (i > (c->img.width * c->img.height) || i < 0)
			return ;
		c->img.data[i] = v.color;
	}
	else
		mlx_pixel_put(c->mlx, c->window, v.x, v.y, v.color);
}
