/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:50:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/19 19:23:36 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_lighta(int start, int end, double percentage)
{
    return ((int)(percentage * start + (1 - percentage) * end));
}

int		get_color(t_fdf *coords, t_numbers *num) //start = 9717EC   end = F01DF0 
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (num->z == 0 && num->z0 != 0)
    {
        if (coords->color == num->endcolor)
            return(coords->color);    
        // if (MOD(num->x0end - num->xstart) > MOD(num->y0end - num->ystart))
        //     percentage = ft_percent(MOD(num->xstart), MOD(num->x0end), MOD(num->x));
        if (MOD(num->xstp) > MOD(num->ystp))
            percentage = ft_percent(MOD(num->xstart), MOD(num->x0end), MOD(num->x));
        else
            percentage = ft_percent(MOD(num->ystart), MOD(num->y0end), MOD(num->y));
        red = get_light((num->startcolor >> 16) & 0xFF, (num->endcolor >> 16) & 0xFF, percentage);
        green = get_light((num->startcolor >> 8) & 0xFF, (num->endcolor >> 8) & 0xFF, percentage);
        blue = get_light(num->startcolor & 0xFF, num->endcolor & 0xFF, percentage);
        return ((red << 16) | (green << 8) | blue);
    }
    if (num->z != 0 && num->z0 == 0)
    {
        if (coords->color == num->endcolor)
            return(coords->color);    
        if ((num->x0end - num->xstart) > (num->y0end - num->ystart))
        //     percentage = ft_percent(MOD(num->xstart), MOD(num->x0end), MOD(num->x));
            percentage = ft_percent((num->xstart), (num->x0end), (num->x));
        else
            percentage = ft_percent((num->ystart), (num->y0end), (num->y));
        red = get_light((num->endcolor >> 16) & 0xFF, (num->startcolor >> 16) & 0xFF, percentage);
        green = get_light((num->endcolor >> 8) & 0xFF, (num->startcolor >> 8) & 0xFF, percentage);
        blue = get_light(num->endcolor & 0xFF, num->startcolor & 0xFF, percentage);
        return ((red << 16) | (green << 8) | blue);
    }
    if (num->z != 0 && num->z0 != 0)
        return (num->endcolor);
    return (num->startcolor);
}

//   2 -> 3  2.5               4  ->  3  