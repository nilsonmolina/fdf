/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:48:37 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/22 19:03:48 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *filename);

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else
		fdf(argv[1]);
	return (0);
}

void	fdf(char *filename)
{
	t_canvas c;

	c.mlx = mlx_init();
	c.window = mlx_new_window(c.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "nmolina fdf");
	c.img.img = mlx_new_image(c.mlx, WINDOW_WIDTH - OFF_X, WINDOW_HEIGHT - OFF_Y);
	c.img.data = (int *)mlx_get_data_addr(c.img.img, &c.img.bpp, &c.img.sl, &c.img.e);
	c.img.width = WINDOW_WIDTH - OFF_X;
	c.img.height = WINDOW_HEIGHT - OFF_Y;
	c.filename = filename;
	c.map.color = 0xFFFFFF;
	c.map.rot_x = 0;
	c.map.rot_y = 0;
	c.map.move_x = 0;
	c.map.move_y = 0;

	mlx_string_put(c.mlx, c.window, 10, 10, 0xFFFFFF, c.filename);
	mlx_string_put(c.mlx, c.window, 10, 30, 0xAAAAAA, "'1'     - render_map");
	mlx_string_put(c.mlx, c.window, 10, 50, 0xAAAAAA, "'2'     - print_map_array");
	mlx_string_put(c.mlx, c.window, 10, 70, 0xAAAAAA, "'space' - clear_map");
	mlx_string_put(c.mlx, c.window, 10, 90, 0xAAAAAA, "'esc'   - quit");

	set_map(&c);

	mlx_key_hook(c.window, key_pressed, &c);
	mlx_mouse_hook(c.window, mouse_clicked, &c);
	mlx_loop(c.mlx);
}

void	usage()
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

void	free_array(void **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
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