/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 22:53:56 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/16 16:05:53 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* private functions */
void    copy_file(t_canvas *c);
void    set_sizes(t_canvas *c);
void    clearFile(t_canvas *c);
char	*ft_empty_str(void);

void    set_map(t_canvas *c)
{    
    copy_file(c);
    // set_sizes(c);
    printf("Rows: %d | Columns: %d\n", c->map.rows, c->map.columns);
}

void    copy_file(t_canvas *c)
{
    if (c->file.contents != NULL)
        free(c->file.contents);
    c->file.contents = ft_memalloc(1);
    ft_error_msg((c->file.fd = open(c->filename, O_RDONLY)), "Failed to open file.");
    while ((c->file.ret = read(c->file.fd, &c->file.buffer, BUF_SIZE)))
    {
        c->file.buffer[c->file.ret] = '\0';
        c->file.temp = c->file.contents;
        c->file.contents = ft_strjoin(c->file.temp, c->file.buffer);
        free(c->file.temp);
    }
}

void    set_sizes(t_canvas *c)
{
    int i;

    c->file.splitY = ft_strsplit(c->file.contents, '\n');
    c->file.splitX = ft_strsplit(c->file.splitY[0], ' ');
    i = 0;    
    while (c->file.splitX[i])
        i++;
    c->map.columns = i;
    i = 0;
    while (c->file.splitY[i])
        i++;
    c->map.rows = i;
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