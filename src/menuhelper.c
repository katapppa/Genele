/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menuhelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:59:09 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 18:06:27 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_anglele(int key, t_fdf *coords)
{
	if (key == 23)
		coords->angle -= 0.1;
	if (key == 22)
		coords->angle += 0.1;
}

void		ft_zeze(int key, t_fdf *coords)
{
	if (key == 91)
		coords->ze += 1;
	if (key == 84)
		coords->ze -= 1;
}
