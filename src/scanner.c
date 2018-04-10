/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/09 17:23:00 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

// remove this before turning in
#include <stdio.h>
//

void    set_map(t_mlx *mlx)
{
    int     fd;
    char    *line;
	char	**row;

    if ((fd = open(mlx->map.filename, O_RDONLY)) < 1)
        exit(0);
    while (get_next_line(fd, &line) == 1)
    {
		row = ft_strsplit(line, ' ');
		while ( *row ) printf( "%s", *row++ );
		printf("%s", "\n");
		free(line);
		// free(row);
    }
}

/*

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = -1;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1 )
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);


*/