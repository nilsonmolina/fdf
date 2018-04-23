/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <nmolina@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:19:40 by nmolina           #+#    #+#             */
/*   Updated: 2018/04/22 19:25:08 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_canvas *c, int degrees)
{
    int d;

    d = c->map.rot_x + degrees;
    if (d >= 360)
        c->map.rot_x = 0 + (d - 360);
    else if (d <= 0)
        c->map.rot_x = 360 - (0 - d);
    else
        c->map.rot_x = d;
}