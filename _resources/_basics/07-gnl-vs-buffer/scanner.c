/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/10 00:56:44 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

// remove this before turning in
#include <stdio.h>
//

void    set_map(t_canvas *canvas)
{
    int         fd;
    char        *line;
	char	    **row;
    t_iterator  iter;    

    ft_error_msg((fd = open(canvas->filename, O_RDONLY)), "Failed to open file.");
    iter.i = 0;
    iter.y = 0;
    while (get_next_line(fd, &line) == 1)
    {
        iter.x = 0;
		row = ft_strsplit(line, ' ');
		while (row[iter.x]) 
        {
            // canvas->map.vectors[iter.i].x = iter.x;
            // canvas->map.vectors[iter.i].y = iter.y;
            // canvas->map.vectors[iter.i].z = ft_atoi(row[iter.x]);
            // canvas->map.vectors[iter.i].color = 0xFFFFFF;            
            
            // printf( "%d ", canvas->map.vectors[iter.i].z);
            iter.i++;
            iter.x++;
        }
        iter.y++;
		// printf("%s", "\n");
		free(line);
        free(row);
    }
}

void    set_map2(t_canvas *canvas)
{
    int     fd;
    int     ret;
    char    line[BUF_SIZE+1];
	char	**row;

    ft_error_msg((fd = open(canvas->filename, O_RDONLY)), "Failed to open file.");    
    while ((ret = read(fd, &line, BUF_SIZE)))
    {
		row = ft_strsplit(line, '\n');
		while ( *row ) printf( "%s", *row++ );
		printf("%s", "\n");
		// free(line);
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