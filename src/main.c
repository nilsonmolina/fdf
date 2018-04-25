/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 21:04:19 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *filename)
{
	t_canvas c;

	c.mlx = mlx_init();
	c.window = mlx_new_window(c.mlx, WIN_WIDTH, WIN_HEIGHT, "nmolina fdf");
	c.img.img = mlx_new_image(c.mlx, WIN_WIDTH - OFF_X, WIN_HEIGHT - OFF_Y);
	c.img.data = (int *)mlx_get_data_addr(c.img.img,
			&c.img.bpp, &c.img.sl, &c.img.e);
	c.img.width = WIN_WIDTH - OFF_X;
	c.img.height = WIN_HEIGHT - OFF_Y;
	c.filename = filename;
	set_map(&c);
	init_map(&c);
	mlx_key_hook(c.window, key_pressed, &c);
	mlx_mouse_hook(c.window, mouse_clicked, &c);
	mlx_loop(c.mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else
		fdf(argv[1]);
	return (0);
}

void	usage(void)
{
	ft_putstr("usage: ./fdf <MAP_FILE>\n");
	exit(0);
}

void	check_error(int err, char *msg)
{
	if (err < 1)
	{
		ft_putstr("- ERROR: ");
		ft_putstr(msg);
		ft_putstr("\n");
		exit(1);
	}
}

void	init_map(t_canvas *c)
{
	c->map.rot_x = 15;
	c->map.rot_y = 0;
	c->map.move_x = 0;
	c->map.move_y = 0;
	set_scale(c);
	c->map.center_x = (WIN_WIDTH - (c->map.columns * c->map.scale)) / 2;
	c->map.center_y = (WIN_HEIGHT - (c->map.rows * c->map.scale)) / 2;
	c->map.z_height /= 2;
	put_img_map(c);
}
