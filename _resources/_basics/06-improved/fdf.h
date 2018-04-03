#ifndef FDF_H
# define FDF_H

// Libraries
# include "libft.h"
# include "mlx.h"
# include <math.h>

// VARIABLES
# define WINDOW_WIDTH	400//1280
# define WINDOW_HEIGHT	400//720

// STRUCTS
typedef struct		s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	void		*img;
	int			*img_data;
	int			img_width;
}					t_img;

typedef struct		s_vector
{
	int			x;
	int			y;
	int			z;
	int			color;
}					t_vector;

typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_vector	*map;
}					t_mlx;


// FUNCTIONS 
// main.c
void	init(t_mlx *mlx);

// events.c
int		key_pressed(int keycode, t_mlx *mlx);
int		mouse_clicked(int button, int x, int y, t_mlx *mlx);

// render.c
void 	put_pixel_square(t_mlx *mlx);
void	put_image_square(t_mlx *mlx);
void	put_img_pixel(t_img *img, int x, int y, int color);
void	put_img_vector(t_img *img, t_vector vector);

// scanner.c


#endif
