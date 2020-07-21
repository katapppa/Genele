/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:50:54 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 18:34:27 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_numbers *num)
{
	if (num->z0 >= 0 && num->z >= 0)
	{
		if (num->z0 > num->z)
			return (ft_colorizer(num));
		if (num->z > num->z0)
			return (ft_colorizerr(num));
	}
	if (num->z0 <= 0 && num->z <= 0)
	{
		if (num->z0 > num->z)
			return (ft_colorizerr(num));
		if (num->z > num->z0)
			return (ft_colorizer(num));
	}
	if ((num->z == num->z0) && num->z != 0)
		return (num->ec);
	return (num->sc);
}
