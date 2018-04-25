/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:19:40 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/24 15:04:53 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_axis(t_canvas *c, int *axis, int degrees)
{
    int d;

    d = *axis + degrees;
    if (d >= 360)
        *axis = 0 + (d - 360);
    else if (d <= 0)
        *axis = 360 - (0 - d);
    else
        *axis = d;
    put_img_map(c);
}

void    adjust_scale(t_canvas *c, int *scale, int direction)
{
    double s;

    if (direction > 0)
        s = *scale *= 1.2;
    else if (direction < 0)
        s = *scale /= 1.2;
    else
        return ;
    if (s < 1 && direction > 0)
        s = 1;
    if (s == *scale && direction > 0)
        s++;
    if (s * c->map.rows > WINDOW_HEIGHT * 2)
        s = (WINDOW_HEIGHT * 2) / c->map.rows;
    else if (s * c->map.columns > WINDOW_WIDTH * 2)
        s = (WINDOW_WIDTH * 2) / c->map.columns;
    if (s < 1 && direction > 0)
        s = 1;
    *scale = s;
    put_img_map(c);
    printf("scale: %d\n", c->map.scale);
}

void    move_map(t_canvas *c, int *axis, int pixels)
{
    *axis += pixels;
    put_img_map(c); 
}