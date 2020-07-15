/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:13:51 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/15 13:51:47 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        ft_magic(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8); //proverit
    *y = (*x + *y) * sin(0.8) - z;
}

void        ft_draw(float x, float y, float x0, float y0, fdf *coords)
{
    float   xstp;
    float   ystp;
    int     max;
    int     z;
    int     z0;

    z = coords->box[(int)y][(int)x];
    z0 = coords->box[(int)y0][(int)x0];
    //zoom
    x *= coords->zoom;
    y *= coords->zoom;
    x0 *= coords->zoom;
    y0 *= coords->zoom;
    //color
    coords->color = (z > 0) ? 0xe80c0c : 0xffffff;
    //3D
    ft_magic(&x, &y, z);
    ft_magic(&x0, &y0, z0);
    xstp = x0 - x;
    ystp = y0 - y;
    max = (MOD(xstp) > MOD(ystp) ? xstp : ystp);
    xstp /= max;
    ystp /= max;
    while ((int)(x - x0) || (int)(y - y0))
    {
        mlx_pixel_put(coords->mlx_ptr, coords->win_ptr, (int)x, (int)y, coords->color);
        x += xstp;
        y += ystp;
    }
}

void        ft_create(fdf *coords)
{
    int y;
    int x;

    y = 0;
    while (y < coords->height)
    {
        x = 0;
        while (x < coords->width)
        {
            if (x < coords->width - 1)
                ft_draw(x, y, x + 1, y, coords);
            if (y < coords->height - 1)
                ft_draw(x, y, x, y + 1, coords);
            x++;
        }
        y++;
    }
}