/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/17 17:19:05 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* private functions */
void    read_file(t_canvas *c, t_file *file);
void    create_map(t_canvas *c, t_file *file);
void    set_vector(t_canvas *c, t_iterator *iter, t_file *file);

void    set_map(t_canvas *c)
{
    t_file  file;

    read_file(c, &file);
    create_map(c, &file);
    printf("Rows: %d | Columns: %d\n", c->map.rows, c->map.columns);
    print_map(c);
}

void    read_file(t_canvas *c, t_file *file)
{
    int i;
    
    file->contents = ft_memalloc(1);
    check_error((file->fd = open(c->filename, O_RDONLY)), "Failed to open file.");
    while ((file->ret = read(file->fd, &file->buffer, BUF_SIZE)))
    {
        file->buffer[file->ret] = '\0';
        file->temp = file->contents;
        file->contents = ft_strjoin(file->temp, file->buffer);
        free(file->temp);
    }
    file->splitY = ft_strsplit(file->contents, '\n');
    file->splitX = ft_strsplit(file->splitY[0], ' ');
    i = 0;
    while (file->splitX[i])
        free(file->splitX[i++]);
    c->map.columns = i;
    i = 0;
    while (file->splitY[i])
        i++;
    c->map.rows = i;
    free(file->contents);
    free(file->splitX);
}

void    create_map(t_canvas *c, t_file *file)
{
    t_iterator  iter;
    t_vector    v[c->map.rows * c->map.columns];

    c->map.vectors = v;
    iter.i = 0;
    iter.y = 0;
    while (file->splitY[iter.y])
    {
        iter.x = 0;
        file->splitX = ft_strsplit(file->splitY[iter.y], ' ');
        while (file->splitX[iter.x])
        {
            if (iter.x >= c->map.columns)
                break ;
            set_vector(c, &iter, file);
            free(file->splitX[iter.x++]);
            iter.i++;
        }
        if (iter.x < c->map.columns)
            check_error(0, "map error - improper row sizes");
        free(file->splitX);
        iter.y++;
    }
    free_array((void **)file->splitY);
}

void    set_vector(t_canvas *c, t_iterator *iter, t_file *file)
{
    char    **val;

    val = ft_strsplit(file->splitX[iter->x], ',');
    c->map.vectors[iter->i].x = iter->x;
    c->map.vectors[iter->i].y = iter->y;
    c->map.vectors[iter->i].z = ft_atoi_base(file->splitX[iter->x], 10);
    if (val[1])
        c->map.vectors[iter->i].color = ft_atoi_base(val[1]+2, 16);
    else
        c->map.vectors[iter->i].color = c->map.color;
    free_array((void **)val);
    printf("x: %2d | y: %2d | z: %2d | color: %d\n", c->map.vectors[iter->i].x, c->map.vectors[iter->i].y, c->map.vectors[iter->i].z, c->map.vectors[iter->i].color);
}

void    print_map(t_canvas *c)
{
    int i = -1;
    while (++i < (c->map.rows * c->map.columns))
        printf("x: %2d | y: %2d | color: %d\n", c->map.vectors[i].x, c->map.vectors[i].y, c->map.vectors[i].color);
}

/*
void    create_map(t_canvas *c, t_file *file)
{
    char        **val;
    t_iterator  iter;

    c->map.vectors = malloc(sizeof(t_vector *) * (c->map.rows));
    while (iter.y < c->map.rows)
    {
        iter.x = 0;
        file->splitX = ft_strsplit(file->splitY[iter.y], ' ');
        c->map.vectors[iter.y] = malloc(sizeof(t_vector *) * (c->map.columns));
        while (iter.x < c->map.columns)
        {
            val = ft_strsplit(file->splitX[iter.x], ',');
            c->map.vectors[iter.y][iter.x].x = iter.x;
            c->map.vectors[iter.y][iter.x].y = iter.y;
            c->map.vectors[iter.y][iter.x].z = ft_atoi_base(val[0], 10);
            if (val[1])
                c->map.vectors[iter.y][iter.x].color = ft_atoi_base(val[1], 16);
            else
                c->map.vectors[iter.y][iter.x].color = c->map.color;
            // iter.i = 0;
            // while (val[iter.i])
            //     free(val[iter.i++]);
            // free(val);
            free(file->splitX[iter.x++]);
        }
        free(file->splitX);
        iter.y++;
    }
}
*/
