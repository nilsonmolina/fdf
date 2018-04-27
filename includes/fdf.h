/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:51:18 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/27 15:25:21 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ------ LIBRARIES ------
*/
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

/*
** ------ VARIABLES ------
*/
# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define OFF_X			0
# define OFF_Y			0
# define ROT_DEGREES	5
# define MV_PIXELS		5
# define BUF_SIZE 		102400
# define RED			0xFF2222
# define GREEN			0x22FF22
# define BLUE			0x2222FF
# define PURPLE			0xFF22FF
# define WHITE			0xFFFFFF
# define GREY			0xAAAAAA
# define DGREY			0x444444

/*
** ------ STRUCTS ------
*/
typedef struct	s_vector
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	t_vector	*vectors;
	t_vector	prev;
	int			rows;
	int			columns;
	int			scale;
	int			max_z;
	float		z_height;
	int			center_x;
	int			center_y;
	int			rot_x;
	int			rot_y;
	int			move_x;
	int			move_y;
}				t_map;

typedef struct	s_img
{
	int			bpp;
	int			sl;
	int			e;
	void		*img;
	int			*data;
	int			width;
	int			height;
}				t_img;

typedef struct	s_canvas
{
	void		*mlx;
	void		*window;
	char		*filename;
	t_img		img;
	t_map		map;
	int			shft;
	int			mode;
	int			color_on;
}				t_canvas;

typedef struct	s_file
{
	char		**split_y;
	char		**split_x;
	char		*contents;
	char		*temp;
	char		buffer[BUF_SIZE + 1];
	int			fd;
	int			ret;
}				t_file;

typedef struct	s_iterator
{
	int			i;
	int			x;
	int			y;
	int			z;
}				t_iterator;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_line;
/*
** ------ PUBLIC FUNCTIONS ------
** main.c
*/
void			usage();
void			init_map(t_canvas *c);
void			check_error(int err, char *msg);
/*
** events.c
*/
int				key_up(int key, t_canvas *c);
int				key_hold(int key, t_canvas *c);
int				mouse_clicked(int button, int x, int y, t_canvas *c);
/*
** render.c
*/
void			clear_img(t_canvas *c);
void			put_img_map(t_canvas *c);
void			put_img_vector(t_canvas *c, t_vector vector);
/*
** scanner.c
*/
void			set_map(t_canvas *c);
void			free_array(void **arr);
/*
** prepare.c
*/
void			prepare(t_canvas c, t_vector *v);
void			set_scale(t_canvas *c);
float			set_theta(int degrees);
void			set_color(t_vector *v, t_map *map);
/*
** mutate.c
*/
void			rotate_axis(t_canvas *c, int *axis, int degrees);
void			adjust_scale(t_canvas *c, int direction);
void			adjust_height(t_canvas *c, float direction);
void			move_map(t_canvas *c, int *axis, int pixels);

#endif
