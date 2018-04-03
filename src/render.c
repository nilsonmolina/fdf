#include "fdf.h"

// remove this before turning in
#include <stdio.h>
//

void 	    put_pixel_square(t_mlx *mlx)
{
	int x;
	int y;

	mlx_clear_window(mlx->mlx, mlx->window);	
	
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
    mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_pixel");	
}

void	    put_image_square(t_mlx *mlx)
{
	int x = 0;
	int y = 0;

	mlx_clear_window(mlx->mlx, mlx->window);

	while (y < 100) 
	{
		while (x < 100)
		{
			put_img_pixel(&mlx->img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 50, 50);
	mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xFFFFFF, "put_image");
}

void        put_img_pixel(t_img *img, int x, int y, int color)
{
	int i;

    i = x + (y * img->img_width); 
    img->img_data[i] = color;
}

void        put_img_vector(t_img *img, t_vector vector)
{
	int i;

    i = vector.x + (vector.y * img->img_width); 
    img->img_data[i] = vector.color;
}