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
	int		bpp;
	int		stride;
	int		endian;
	void	*img;
	char	*img_data;
}					t_img;

typedef struct		s_mlx
{
	void	*mlx;
	void	*window;
	t_img	img;
}					t_mlx;


// FUNCTIONS - main.c
void	draw(t_mlx *mlx);

#endif
