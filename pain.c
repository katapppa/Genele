/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:13:51 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/16 18:07:48 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void        ft_magic(numbers *num)
{
    num->x = (num->x - num->y) * cos(0.7);
    num->y = (num->x + num->y) * sin(0.7) - num->z;
}

void        ft_magica(numbers *num)
{
    num->x0 = (num->x0 - num->y0) * cos(0.7);
    num->y0 = (num->x0 + num->y0) * sin(0.7) - num->z0;
}

void        ft_draw(float x, float y, float x0, float y0, fdf *coords)
{
    float   xstp;
    float   ystp;
    float     maxe;
    //float     z;
    //float     z0;
    numbers *num;

    num = (numbers*)malloc(sizeof(numbers));
    num->z = ((coords->box[(int)y][(int)x]) != 0) ? ((coords->box[(int)y][(int)x]) + coords->ze) : ((coords->box[(int)y][(int)x]));
    num->z0 = ((coords->box[(int)y0][(int)x0]) != 0) ? ((coords->box[(int)y0][(int)x0]) + coords->ze) : ((coords->box[(int)y0][(int)x0]));
    //zoom
    num->x = x *= coords->zoom;
    num->y = y *= coords->zoom;
    num->x0 = x0 *= coords->zoom;
    num->y0 = y0 *= coords->zoom;
    //color
    coords->color = (num->z > 0 || num->z0 > 0) ? 0xe80c0c : 0xffffff;
    //3D
    ft_magic(num);
    ft_magica(num);
    num->x += coords->sdvigx;
    num->x0 += coords->sdvigx;
    num->y += coords->sdvigy;
    num->y0 += coords->sdvigy;
    xstp = num->x0 - num->x;
    ystp = num->y0 - num->y;
    maxe = ((MOD(xstp) > MOD(ystp)) ? MOD(xstp) : MOD(ystp));
    xstp /= maxe;
    ystp /= maxe;
    while ((int)(num->x - num->x0) || (int)(num->y - num->y0))
    {
        mlx_pixel_put(coords->mlx_ptr, coords->win_ptr, num->x, num->y, coords->color);
        num->x += xstp;
        num->y += ystp;
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