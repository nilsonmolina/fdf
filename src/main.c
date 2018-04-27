/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 15:21:32 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_canvas c;

	if (argc != 2)
		usage();
	c.filename = argv[1];
	c.mlx = mlx_init();
	c.window = mlx_new_window(c.mlx, WIN_WIDTH, WIN_HEIGHT, "nmolina fdf");
	c.img.width = WIN_WIDTH - OFF_X;
	c.img.height = WIN_HEIGHT - OFF_Y;
	c.img.img = mlx_new_image(c.mlx, c.img.width, c.img.height);
	c.img.data = (int *)mlx_get_data_addr(c.img.img,
			&c.img.bpp, &c.img.sl, &c.img.e);
	c.shft = 0;
	c.mode = 1;
	c.color_on = -1;
	set_map(&c);
	mlx_hook(c.window, 2, 0, key_hold, &c);
	mlx_key_hook(c.window, key_up, &c);
	mlx_loop(c.mlx);
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
	c->map.rot_x = 5;
	c->map.rot_y = 0;
	c->map.move_x = 0;
	c->map.move_y = 0;
	set_scale(c);
	c->map.center_x = (WIN_WIDTH - (c->map.columns * c->map.scale)) / 2;
	c->map.center_y = (WIN_HEIGHT - (c->map.rows * c->map.scale)) / 2;
	c->map.z_height = 1;
	put_img_map(c);
}
