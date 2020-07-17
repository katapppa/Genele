/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:40:24 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/17 13:59:30 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_numbers		*ft_createy(t_numbers *num, int x, int y)
{
	num->x = x;
	num->x0 = x;
	num->y = y;
	num->y0 = y + 1;
	return (num);
}

t_numbers		*ft_createx(t_numbers *num, int x, int y)
{
	num->x = x;
	num->x0 = x + 1;
	num->y = y;
	num->y0 = y;
	return (num);
}