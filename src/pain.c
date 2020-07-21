/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:13:51 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 17:15:21 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_zet(t_fdf *coords, int x, int y)
{
	float z;

	z = coords->box[y][x];
	if (z != 0)
		z += coords->ze;
	return (z);
}

void		ft_idkhtn(t_numbers *num, t_fdf *coords)
{
	if (coords->dvad == 1)
	{
		num->x = (num->x - num->y) * cos(coords->angle);
		num->y = (num->x + num->y) * sin(coords->angle) - num->z;
		num->x0 = (num->x0 - num->y0) * cos(coords->angle);
		num->y0 = (num->x0 + num->y0) * sin(coords->angle) - num->z0;
	}
	num->x += coords->sdvigx;
	num->x0 += coords->sdvigx;
	num->y += coords->sdvigy;
	num->y0 += coords->sdvigy;
}

void		ft_draw(t_numbers *num, t_fdf *coords)
{
	float	xstp;
	float	ystp;
	float	max;

	num->z = ft_zet(coords, (int)num->x, (int)num->y);
	num->z0 = ft_zet(coords, (int)num->x0, (int)num->y0);
	num->x *= coords->zoom;
	num->y *= coords->zoom;
	num->x0 *= coords->zoom;
	num->y0 *= coords->zoom;
	ft_idkhtn(num, coords);
	xstp = num->x0 - num->x;
	ystp = num->y0 - num->y;
	max = ((MOD(xstp) > MOD(ystp)) ? MOD(xstp) : MOD(ystp));
	xstp /= max;
	ystp /= max;
	ft_helper(num);
	while ((int)(num->x - num->x0) || (int)(num->y - num->y0))
	{
		mlx_pixel_put(coords->mlx_ptr, coords->win_ptr,
			num->x, num->y, coords->color = get_color(num));
		num->x += xstp;
		num->y += ystp;
	}
}

void		ft_create(t_fdf *coords)
{
	int			y;
	int			x;
	t_numbers	*num;

	num = (t_numbers*)malloc(sizeof(t_numbers));
	y = 0;
	while (y < coords->height)
	{
		x = 0;
		while (x < coords->width)
		{
			if (x < coords->width - 1)
				ft_draw(ft_createx(num, x, y), coords);
			if (y < coords->height - 1)
				ft_draw(ft_createy(num, x, y), coords);
			x++;
		}
		y++;
	}
	free(num);
}
