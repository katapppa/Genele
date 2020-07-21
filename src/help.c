/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:40:24 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 17:17:13 by cgamora          ###   ########.fr       */
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

double			ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void			ft_print_menu(t_fdf *coords)
{
	char *line;

	line = "ZOOM: + and -";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 10, 0xEEEE69, line);
	line = "MOVE: WASD and arrow keys";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 30, 0xEEEE69, line);
	line = "ROTATE: 5 and 6";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 50, 0xEEEE69, line);
	line = "UP/DOWN: 8 and 2";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 70, 0xEEEE69, line);
	line = "FULLSCREEN: f";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 90, 0xEEEE69, line);
	line = "2D/3D: 2";
	mlx_string_put(coords->mlx_ptr, coords->win_ptr, 10, 110, 0xEEEE69, line);
}

void			ft_init_struct(t_fdf *coords)
{
	coords->dvad = 1;
	coords->a = 2000;
	coords->b = 1000;
	coords->angle = 0.7;
	coords->zoom = 15;
	coords->sdvigx = 150;
	coords->sdvigy = 150;
	coords->ze = 0;
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr,
			coords->a, coords->b, "FDF");
}
