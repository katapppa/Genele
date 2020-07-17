/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/17 13:57:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_struct(t_fdf *coords)
{
	coords->zoom = 30;
	coords->sdvigx = 150;
	coords->sdvigy = 150;
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

int		deal_key(int key, t_fdf *coords)
{
	int i;

	i = 0;
	if (key == 124)
		coords->sdvigx += 10;
	if (key == 125)
		coords->sdvigy += 10;
	if (key == 123)
		coords->sdvigx -= 10;
	if (key == 126)
		coords->sdvigy -= 10;
	if (key == 69)
		coords->zoom += 30;
	if (key == 78)
		coords->zoom -= 30;
	if (key == 23)
		coords->ze -= 1;
	if (key == 22)
		coords->ze += 1;
	mlx_clear_window(coords->mlx_ptr, coords->win_ptr);
	ft_create(coords);
	return (1);
}

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
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, 1000, 1000, "FDF");
	ft_create(coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	mlx_loop(coords->mlx_ptr);
	free_struct(coords);
	return (0);
}
