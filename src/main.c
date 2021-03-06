/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/22 16:12:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_fdf *coords)
{
	int i;

	i = 0;
	while (i <= coords->height)
	{
		free(coords->box[i]);
		i++;
	}
	free(coords->box);
	free(coords);
}

void	ft_exit(t_fdf *coords)
{
	free_struct(coords);
	exit(1);
}

void	ft_fullscreen(t_fdf *coords)
{
	if (coords->a == 2560 && coords->b == 1440)
	{
		coords->a = 2000;
		coords->b = 1000;
	}
	else
	{
		coords->a = 2560;
		coords->b = 1440;
	}
	mlx_destroy_window(coords->mlx_ptr, coords->win_ptr);
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, coords->a,
			coords->b, "FDF");
	ft_create(coords);
	ft_print_menu(coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	mlx_loop(coords->mlx_ptr);
}

int		deal_key(int key, t_fdf *coords)
{
	if (key == 124 || key == 2)
		coords->sdvigx += 10;
	if (key == 125 || key == 1)
		coords->sdvigy += 10;
	if (key == 123 || key == 0)
		coords->sdvigx -= 10;
	if (key == 126 || key == 13)
		coords->sdvigy -= 10;
	if (key == 69 || key == 78)
		ft_zoomzoom(key, coords);
	if (key == 23 || key == 22)
		ft_anglele(key, coords);
	if (key == 53)
		ft_exit(coords);
	if (key == 91 || key == 84)
		ft_zeze(key, coords);
	if (key == 3)
		ft_fullscreen(coords);
	if (key == 19)
		ft_dvad(coords);
	mlx_clear_window(coords->mlx_ptr, coords->win_ptr);
	ft_print_menu(coords);
	ft_create(coords);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fdf	*coords;

	if (argc == 1 || argc > 2)
	{
		write(1, "Usage: ./fdf map.fdf\n", 21);
		return (0);
	}
	if (!(coords = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	if (!(ft_isfdf(argv[1])))
	{
		perror("ERROR");
		free(coords);
		exit(1);
	}
	ft_file(coords, argv[1]);
	ft_init_struct(coords);
	ft_print_menu(coords);
	ft_create(coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	mlx_loop(coords->mlx_ptr);
	free_struct(coords);
	return (0);
}
