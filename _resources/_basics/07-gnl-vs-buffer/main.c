/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/10 00:40:17 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_usage();
	else
		fdf(argv[1]);
	return (0);
}

void	fdf(char *filename)
{
	t_canvas c;
	
	c.mlx = mlx_init();
	c.window = mlx_new_window(c.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "nmolina fdf");
	c.img.img = mlx_new_image(c.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	c.img.data = (int *)mlx_get_data_addr(c.img.img, &c.img.bpp, &c.img.sl, &c.img.e);
	c.img.width = WINDOW_WIDTH;
	c.filename = filename;

	mlx_string_put(c.mlx, c.window, 10, 10, 0xFFFFFF, c.filename);
	mlx_string_put(c.mlx, c.window, 10, 30, 0xAAAAAA, "'1' - put_pixel");
	mlx_string_put(c.mlx, c.window, 10, 50, 0xAAAAAA, "'2' - put_image");
	mlx_string_put(c.mlx, c.window, 10, 70, 0xAAAAAA, "'3' - benchmark_read_gnl");
	mlx_string_put(c.mlx, c.window, 10, 90, 0xAAAAAA, "'4' - benchmark_read_buf");
	
	mlx_key_hook(c.window, key_pressed, &c);
	mlx_mouse_hook(c.window, mouse_clicked, &c);
	mlx_loop(c.mlx);
}

void	ft_usage()
{
	ft_putstr("usage: ./fdf <MAP_FILE>\n");
	exit(0);
}

void	ft_error_msg(int err, char *msg)
{
	if (err < 1)
	{
		ft_putstr("- ERROR: ");
		ft_putstr(msg);
		ft_putstr("\n");
		exit(1);
	}
}

// void	ft_check_args(t_canvas *c, int argc, char **argv)
// {
// 	int i;

// 	i = 1;
// 	(argc >= 2 && argc <= 6) ? 0 : ft_usage();
// 	c->file = ft_strdup(argv[1]);
// 	c->w_x = 0;
// 	c->w_y = 0;
// 	while (i < argc)
// 	{
// 		if (!ft_strcmp(argv[i], "-w") && i + 1 < ac)
// 			c->w_x = ft_atoi(argv[i + 1]);
// 		else if (!ft_strcmp(argv[i], "-h") && i + 1 < ac)
// 			c->w_y = ft_atoi(argv[i + 1]);
// 		else if (!ft_strcmp(argv[i], "--help"))
// 			ft_usage();
// 		i++;
// 	}
// 	c->w_x = (c->w_x < 600 || c->w_x > 1920 ? 1280 : c->w_x);
// 	c->w_y = (c->w_y < 600 || c->w_y > 1280 ? 1024 : c->w_y);
// }