/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:45:02 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/13 00:29:07 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 10000

typedef struct	s_memory
{
	char	buf[BUFF_SIZE + 1];
	int		head;
}				t_memory;

int				get_next_line(const int fd, char **line);
char			*ft_empty_str(void);
int				read_file(const int fd, t_memory *file);
char			*ft_straddchar(char *src, char c);
size_t			ft_strlen(const char *s);

#endif
