/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/18 16:28:11 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_struct(t_fdf *coords)
{
	coords->dvad = 1;
	coords->a = 1000;
	coords->b = 1000;
	coords->angle = 0.7;
	coords->zoom = 15;
	coords->sdvigx = 150;
	coords->sdvigy = 150;
	coords->ze = 0;
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, coords->a, coords->b, "FDF");
}

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
	exit(0);
}

int		deal_mouse(int key)
{
	printf("%d\n",key);
	return 0;
}

void	ft_print_menu(t_fdf *coords)
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

void	ft_fullscreen(t_fdf *coords)
{
	if (coords->a == 2560 && coords->b == 1440)
	{
		coords->a = 1000;
		coords->b = 1000;
	}
	else
	{
		coords->a = 2560;
		coords->b = 1440;
	}
	mlx_destroy_window(coords->mlx_ptr, coords->win_ptr);
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, coords->a, coords->b, "FDF");
	ft_create(coords);
	ft_print_menu(coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	mlx_loop(coords->mlx_ptr);
}

void	ft_dvad(t_fdf *coords)
{
	if (coords->dvad == 0)
		coords->dvad = 1;
	else
		coords->dvad = 0;	
}

int		deal_key(int key, t_fdf *coords)
{
	int i;

	i = 0;
	if (key == 124 || key == 2)
		coords->sdvigx += 10;
	if (key == 125 || key == 1)
		coords->sdvigy += 10;
	if (key == 123 || key == 0)
		coords->sdvigx -= 10;
	if (key == 126 || key == 13)
		coords->sdvigy -= 10;
	if (key == 69)
		coords->zoom += 5;
	if (key == 78)
		coords->zoom -= 5;
	if (key == 23)
		coords->angle -= 0.1;
	if (key == 22)
		coords->angle += 0.1;
	if (key == 53)
		ft_exit(coords);
	if (key == 91)
		coords->ze += 1;
	if (key == 84)
		coords->ze -= 1;
	if (key == 3)
		ft_fullscreen(coords);
	if (key == 19)
		ft_dvad(coords);
	mlx_clear_window(coords->mlx_ptr, coords->win_ptr);
	ft_print_menu(coords);
	ft_create(coords);
	return (1);
}

int		key_press();

int		main(int argc, char **argv)
{
	int		i;
	t_fdf	*coords;

	if (argc == 1 || argc > 2)
	{
		printf("ERROR\n");
		return (0);
	}
	coords = (t_fdf*)malloc(sizeof(t_fdf));
	i = 0;
	ft_file(coords, argv[1]);
	ft_init_struct(coords);
	ft_print_menu(coords);
	ft_create(coords);
	//mlx_hook(coords->win_ptr, 2, 0, deal_key, coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	//mlx_mouse_hook (coords->win_ptr, deal_mouse, coords);
	mlx_loop(coords->mlx_ptr);
	free_struct(coords);
	return (0);
}
