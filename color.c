/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:50:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/19 16:39:35 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(int current, int start, t_fdf *coords, t_numbers *num) //start = 9717EC   end = F01DF0 
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (coords->color == num->endcolor)
        return (coords->color);
    if (num->x > num->y)
        percentage = percent(num->xstart, num->x0end, num->x);
    else
        percentage = percent(num->ystart, num->y0end, num->y);
    red = get_light((num->startcolor >> 16) & 0xFF, (num->endcolor >> 16) & 0xFF, percentage);
    green = get_light((num->startcolor >> 8) & 0xFF, (num->endcolor >> 8) & 0xFF, percentage);
    blue = get_light(num->startcolor & 0xFF, num->endcolor & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}