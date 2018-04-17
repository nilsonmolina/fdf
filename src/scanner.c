/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/17 14:40:32 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* private functions */
void    copy_file(t_canvas *c, t_file *file);
void    create_map(t_canvas *c, t_file *file);
void    free_file(t_file *file);

void    set_map(t_canvas *c)
{
    t_file  file;

    copy_file(c, &file);
    create_map(c, &file);
    free_file(&file);
    printf("Rows: %d | Columns: %d\n", c->map.rows, c->map.columns);
}

void    copy_file(t_canvas *c, t_file *file)
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
    t_vector v[c->map.rows * c->map.columns];

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
            // val = ft_strsplit(file->splitX[iter.x], ',');
            v[iter.i].x = iter.x;
            v[iter.i].y = iter.y;
            v[iter.i].z = ft_atoi_base(file->splitX[iter.x], 10);
            v[iter.i].color = c->map.color;
            
            // if (val[1])
            //     c->map.vectors[iter.i].color = ft_atoi_base(val[1], 16);
            // else
            //     c->map.vectors[iter.i].color = c->map.color;
            free(file->splitX[iter.x++]);
            iter.i++;
        }
        free(file->splitX);
        iter.y++;
    }
    c->map.vectors = v;    
}

void    free_file(t_file *file)
{
    int i;

    // i = 0;
    // while (file->splitX[i])
    //     free(file->splitX[i++]);
    i = 0;
    while (file->splitY[i])
        free(file->splitY[i++]);
    // free(file->contents);
    // free(file->splitX);
    free(file->splitY);
}




// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*buff;

// 	if (!s1)
// 		return (char *)s2;
// 	if (!s2)
// 		return (char *)s1;
// 	if ((buff = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
// 		return (NULL);
// 	ft_strcpy(buff, s1);
// 	ft_strcat(buff, s2);
// 	return (buff);
// }


// void    create_map(t_canvas *c, t_file *file)
// {
//     char        **val;
//     t_iterator  iter;

//     c->map.vectors = malloc(sizeof(t_vector *) * (c->map.rows));
//     while (iter.y < c->map.rows)
//     {
//         iter.x = 0;
//         file->splitX = ft_strsplit(file->splitY[iter.y], ' ');
//         c->map.vectors[iter.y] = malloc(sizeof(t_vector *) * (c->map.columns));
//         while (iter.x < c->map.columns)
//         {
//             val = ft_strsplit(file->splitX[iter.x], ',');
//             c->map.vectors[iter.y][iter.x].x = iter.x;
//             c->map.vectors[iter.y][iter.x].y = iter.y;
//             c->map.vectors[iter.y][iter.x].z = ft_atoi_base(val[0], 10);
//             if (val[1])
//                 c->map.vectors[iter.y][iter.x].color = ft_atoi_base(val[1], 16);
//             else
//                 c->map.vectors[iter.y][iter.x].color = c->map.color;
//             // iter.i = 0;
//             // while (val[iter.i])
//             //     free(val[iter.i++]);
//             // free(val);
//             free(file->splitX[iter.x++]);
//         }
//         free(file->splitX);
//         iter.y++;
//     }
// }
