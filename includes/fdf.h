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
# define BUF_SIZE 		500000

/* ------ STRUCTS ------ */
typedef struct	s_img
{
	int			bpp;
	int			sl;
	int			e;
	void		*img;
	int			*data;
	int			width;
}					t_img;

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
}				t_map;

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

typedef struct	s_canvas
{
	void		*mlx;
	void		*window;
	char		*filename;
	t_img		img;
	t_map		map;
	t_file		file;
}				t_canvas;

typedef struct	s_iterator
{
	int			i;
	int			x;
	int			y;
}				t_iterator;

/* ------ PUBLIC FUNCTIONS ------ */
/* main.c */
void	ft_usage();
void	ft_error_msg(int error, char *message);

/* events.c */
int		key_pressed(int keycode, t_canvas *c);
int		mouse_clicked(int button, int x, int y, t_canvas *c);

/* render.c */
void 	put_pixel_square(t_canvas *c);
void	put_image_square(t_canvas *c);
void	put_img_pixel(t_img *img, int x, int y, int color);
void	put_img_vector(t_img *img, t_vector vector);

/* scanner.c */
void    set_map(t_canvas *c);

#endif