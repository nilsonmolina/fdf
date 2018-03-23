#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH			400//1280
# define WINDOW_HEIGHT			400//720

typedef struct		s_mlx
{
	void	*mlx;
	void	*window;
}					t_mlx;

void	draw(t_mlx *mlx);

#endif