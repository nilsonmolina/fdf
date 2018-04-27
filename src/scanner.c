/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 15:21:45 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(t_canvas *c, t_file *file)
{
	int i;

	check_error((file->fd = open(c->filename, O_RDONLY)),
			"Failed to open file.");
	file->contents = ft_memalloc(1);
	while ((file->ret = read(file->fd, &file->buffer, BUF_SIZE)))
	{
		file->buffer[file->ret] = '\0';
		file->temp = file->contents;
		file->contents = ft_strjoin(file->temp, file->buffer);
		free(file->temp);
	}
	file->split_y = ft_strsplit(file->contents, '\n');
	file->split_x = ft_strsplit(file->split_y[0], ' ');
	i = 0;
	while (file->split_x[i])
		free(file->split_x[i++]);
	c->map.columns = i;
	i = 0;
	while (file->split_y[i])
		i++;
	c->map.rows = i;
	free(file->contents);
	free(file->split_x);
}

void	set_vector(t_canvas *c, t_iterator *iter, t_file *file)
{
	char	**val;

	val = ft_strsplit(file->split_x[iter->x], ',');
	c->map.vectors[iter->i].x = iter->x;
	c->map.vectors[iter->i].y = iter->y;
	c->map.vectors[iter->i].z = ft_atoi_base(file->split_x[iter->x], 10);
	if (c->map.vectors[iter->i].z > c->map.max_z)
		c->map.max_z = c->map.vectors[iter->i].z;
	if (val[1])
		c->map.vectors[iter->i].color = ft_atoi_base(val[1] + 2, 16);
	else
	{
		if (c->map.vectors[iter->i].z == 0)
			c->map.vectors[iter->i].color = GREEN;
		else
			c->map.vectors[iter->i].color = PURPLE;
	}
	free_array((void **)val);
}

void	create_map(t_canvas *c, t_file *file)
{
	t_iterator	iter;

	c->map.vectors = malloc(sizeof(t_vector) * (c->map.rows * c->map.columns));
	c->map.max_z = 0;
	iter.i = 0;
	iter.y = 0;
	while (file->split_y[iter.y])
	{
		iter.x = 0;
		file->split_x = ft_strsplit(file->split_y[iter.y], ' ');
		while (file->split_x[iter.x])
		{
			if (iter.x >= c->map.columns)
				break ;
			set_vector(c, &iter, file);
			free(file->split_x[iter.x++]);
			iter.i++;
		}
		if (iter.x < c->map.columns)
			check_error(0, "map error - improper row sizes");
		free(file->split_x);
		iter.y++;
	}
	free_array((void **)file->split_y);
}

void	set_map(t_canvas *c)
{
	t_file	file;

	read_file(c, &file);
	create_map(c, &file);
	init_map(c);
}

void	free_array(void **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
