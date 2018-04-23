#ifndef FDF_H
# define FDF_H

/* ------ LIBRARIES ------ */
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# include <stdio.h> // remove this before turning in


/* ------ VARIABLES ------ */
# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720
# define OFF_X			100
# define OFF_Y			100
# define BUF_SIZE 		500000

/* ------ STRUCTS ------ */
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
	int			rows;
	int			columns;
	int			color;
	int			scale;
	int			cntr_x;
	int			cntr_y;
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
}					t_img;

typedef struct	s_canvas
{
	void		*mlx;
	void		*window;
	char		*filename;
	t_img		img;
	t_map		map;
}				t_canvas;

typedef struct	s_file
{
	char		**splitY;
	char		**splitX;
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

/* ------ PUBLIC FUNCTIONS ------ */
/* main.c */
void	usage();
void	check_error(int err, char *msg);
void	free_array(void **arr);

/* events.c */
int		key_pressed(int keycode, t_canvas *c);
int		mouse_clicked(int button, int x, int y, t_canvas *c);

/* render.c */
void	clear_img(t_canvas *c);
void	put_img_map(t_canvas *c);
void	put_img_vector(t_canvas *c, t_vector vector);

/* scanner.c */
void    set_map(t_canvas *c);
void    print_map(t_canvas *c); // remove this before turning in

/* transform.c */
void	transform(t_map map, t_vector *v);
void	set_scale(t_canvas *c);
float	set_theta(int degrees);

/* mutate.c */
void	rotate_x(t_canvas *c, int degrees);

#endif