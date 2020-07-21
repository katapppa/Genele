/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:16:12 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 17:27:28 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_dvad(t_fdf *coords)
{
	if (coords->dvad == 0)
		coords->dvad = 1;
	else
		coords->dvad = 0;
}

void			ft_helper(t_numbers *num)
{
	num->xstart = num->x;
	num->ystart = num->y;
	num->x0end = num->x0;
	num->y0end = num->y0;
	num->ec = 0x03C5B3;
	num->sc = 0x86D403;
}

int				ft_colorizer(t_numbers *num)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;

	if ((num->x0end - num->xstart) > (num->y0end - num->ystart))
		percentage = ft_percent(num->xstart, num->x0end, num->x);
	else
		percentage = ft_percent(num->ystart, num->y0end, num->y);
	red = get_light((num->sc >> 16) & 0xFF,
			(num->ec >> 16) & 0xFF, percentage);
	green = get_light((num->sc >> 8) & 0xFF,
			(num->ec >> 8) & 0xFF, percentage);
	blue = get_light(num->sc & 0xFF,
			num->ec & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int				ft_colorizerr(t_numbers *num)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;

	if ((num->x0end - num->xstart) > (num->y0end - num->ystart))
		percentage = ft_percent((num->xstart), (num->x0end), (num->x));
	else
		percentage = ft_percent((num->ystart), (num->y0end), (num->y));
	red = get_light((num->ec >> 16) & 0xFF, (num->sc >> 16) & 0xFF, percentage);
	green = get_light((num->ec >> 8) & 0xFF, (num->sc >> 8) & 0xFF, percentage);
	blue = get_light(num->ec & 0xFF, num->sc & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
