/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:54 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/26 13:40:46 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_canvas *c)
{
	mlx_destroy_image(c->mlx, c->img.img);
	mlx_clear_window(c->mlx, c->window);
	c->img.img = mlx_new_image(c->mlx, WIN_WIDTH - OFF_X, WIN_HEIGHT - OFF_Y);
}

void	put_strings(t_canvas *c)
{
	char *str;
	
	mlx_string_put(c->mlx, c->window, 10, 10, 0xFFFFFF, "File:");
	mlx_string_put(c->mlx, c->window, 70, 10, 0xFFFFFF, c->filename);	
	if (c->mode == 1)		
		mlx_string_put(c->mlx, c->window, 20, 30, 0x22FF22, "Mode: 'put_image'");
	else
		mlx_string_put(c->mlx, c->window, 20, 30, 0xFF2222, "Mode: 'put_pixel'");
	if (c->color_on == 1)		
		mlx_string_put(c->mlx, c->window, 20, 50, 0x22FF22, "Color: 'dynamic'");
	else
		mlx_string_put(c->mlx, c->window, 20, 50, 0xFF2222, "Color: 'static'");
	mlx_string_put(c->mlx, c->window, 20, 70, 0xAAAAAA, "Scale:");
	mlx_string_put(c->mlx, c->window, 120, 70, 0xAAAAAA, str = ft_itoa(c->map.scale));
	free(str);		
	mlx_string_put(c->mlx, c->window, 20, 90, 0xAAAAAA, "Height:");
	mlx_string_put(c->mlx, c->window, 120, 90, 0xAAAAAA, str = ft_itoa(c->map.z_height * 10));
	free(str);	
	mlx_string_put(c->mlx, c->window, 20, 110, 0xAAAAAA, "Rot_X:");
	mlx_string_put(c->mlx, c->window, 120, 110, 0xAAAAAA, str = ft_itoa(c->map.rot_y));
	free(str);	
	mlx_string_put(c->mlx, c->window, 20, 130, 0xAAAAAA, "Rot_Y:");
	mlx_string_put(c->mlx, c->window, 120, 130, 0xAAAAAA, str = ft_itoa(c->map.rot_x));
	free(str);
}

void	draw_line(t_canvas *c, t_vector curr, t_vector next)
{
	t_line	l;

	l.dx = abs(next.x - curr.x);
	l.sx = curr.x < next.x ? 1 : -1;
	l.dy = abs(next.y - curr.y);
	l.sy = curr.y < next.y ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
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
		transform(*c, &v);
		if (i < (c->map.rows * c->map.columns) - c->map.columns)
		{
			down = c->map.vectors[i + c->map.columns];
			transform(*c, &down);
			draw_line(c, v, down);
			put_img_vector(c, down);
		}
		if (i > 0 && i % c->map.columns != 0)
			draw_line(c, v, c->map.previous);
		put_img_vector(c, v);
		c->map.previous = v;
		i++;
	}
	if (c->mode == 1)
		mlx_put_image_to_window(c->mlx, c->window, c->img.img, OFF_X, OFF_Y);
	put_strings(c);
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
