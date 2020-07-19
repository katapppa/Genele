/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:13:51 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/19 19:28:40 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_zet(t_fdf *coords, int x , int y)
{
	float z;

	z = coords->box[y][x];
	if (z != 0)
		z += coords->ze;
	// if (z < 0)
	// 	z -= coords->ze;
	return (z);
}

void		ft_magic(t_numbers *num, t_fdf *coords)
{
	num->x = (num->x - num->y) * cos(coords->angle);
	num->y = (num->x + num->y) * sin(coords->angle) - num->z;
}

void		ft_magica(t_numbers *num, t_fdf *coords)
{
	num->x0 = (num->x0 - num->y0) * cos(coords->angle);
	num->y0 = (num->x0 + num->y0) * sin(coords->angle) - num->z0;
}

void		ft_idkhtn(t_numbers *num, t_fdf *coords)
{
	//coords->color = 0xe80c0c;//(num->z != 0 || num->z0 != 0) ? 0xe80c0c : 0xffffff;
	if (coords->dvad == 1)
	{
		ft_magic(num,coords);
		ft_magica(num,coords);
	}
	num->x += coords->sdvigx;
	num->x0 += coords->sdvigx;
	num->y += coords->sdvigy;
	num->y0 += coords->sdvigy;
}

int			ft_gradient(t_fdf *coords, t_numbers *num)
{
	int x;
	int y;

	x = (int)num->x0 / 5;
	y = (int)num->y0 / 5;
	coords->color = 0x1BE1F4;
	if (num->x < x || num->y < y)
		return (coords->color);
	else if ((num->x < x*2 && num->x >= x) || (num->y < y*2  && num->y >= x))
		return (coords->color + 0xb);
	else if ((num->x < x*3 && num->x >= x*2) || (num->y < y*3 && num->y >= x*2))
		return (coords->color + 0x16);
	else if ((num->x < x*4 && num->x >= x*3) || (num->y < y*4 && num->y >= x*3))
		return (coords->color + 0x21);
	else if ((num->x <= x*5 && num->x >= x*4) || (num->y <= y*5 && num->y >= x*4))
		return (coords->color + 0x2c);
	return (coords->color);
}

void		ft_draw(t_numbers *num, t_fdf *coords)
{
	float	xstp;
	float	ystp;
	float	max;

	num->z = ft_zet(coords, (int)num->x, (int)num->y);//coords->box[(int)num->y][(int)num->x];
	num->z0 = ft_zet(coords, (int)num->x0, (int)num->y0);//coords->box[(int)num->y0][(int)num->x0];
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
	num->xstp = xstp;
	num->ystp = ystp;
	num->xstart = num->x;
	num->ystart = num->y;
	num->x0end = num->x0;
	num->y0end = num->y0;
	num->endcolor = 0xF79833; 
	num->startcolor = 0xFF0000;//0xCE35CE;
	coords->color = 0xCE35CE;
	printf("XSTP IS %f\n", xstp);
	printf("YSTP IS %f\n\n", ystp);
	while ((int)(num->x - num->x0) || (int)(num->y - num->y0))
	{
		mlx_pixel_put(coords->mlx_ptr, coords->win_ptr,
			num->x, num->y, coords->color = get_color(coords, num));//coords->color -= 0xfff);
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
