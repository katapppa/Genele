/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:13:51 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/15 12:35:26 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        ft_draw(float x, float y, float x0, float y0, fdf *coords)
{
    float   xstp;
    float   ystp;
    int     max;

    xstp = x0 - x;
    ystp = y0 - y;
    max = (MOD(xstp) > MOD(ystp) ? xstp : ystp);
    xstp /= max;
    ystp /= max;
    while ((int)(x - x0) || (int)(y - y0))
    {
        //mlx_pixel_put(coords->mlx_ptr, coords->win_ptr, (int)x, (int)y, 0xffffff);
        x += xstp;
        y += ystp;
    }
}