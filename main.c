/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/16 18:37:16 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key(int key, fdf *coords)
{
	printf("%d\n", key);
	if(key == 124)
		coords->sdvigx += 10;
	if(key == 125)
		coords->sdvigy += 10;
	if(key == 123)
		coords->sdvigx -= 10;
	if(key == 126)
		coords->sdvigy -= 10;
	if(key == 69)
		coords->zoom += 30;
	if(key == 78)
		coords->zoom -= 30;
	if(key == 23)
		coords->ze -= 1;
	if(key == 22)
		coords->ze += 1;
	mlx_clear_window(coords->mlx_ptr, coords->win_ptr);
	ft_create(coords);
	return 0;
}

int		main(int argc, char **argv)
{
	int i;
	int fd;
	fdf *coords;
	
	coords = (fdf*)malloc(sizeof(fdf));
	if (argc == 1 || argc > 2)
	{
		printf("ERROR\n");
		return (0);
	}
	i = 0;
	//fd = open(argv[1], O_RDONLY, 0);
	//close(fd);
	// if (fd == 0)
	// 	printf ("OSHIBKA");
	ft_file(coords, argv[1]);
	coords->zoom = 30;
	coords->sdvigx = 150;
	coords->sdvigy = 150;
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, 1000, 1000, "FDF");
	ft_create(coords);
	mlx_key_hook(coords->win_ptr, deal_key, coords);
	mlx_loop(coords->mlx_ptr);
	// while (i <= coords->height)
    // {
	// 	ft_memdel((void **)&(coords->box[i]));
    //     i++;
    // }
	// ft_memdel((void **)&(coords->box));
	// ft_memdel((void **)&(coords));
	while (i <= coords->height)
    {
		free(coords->box[i]);
        i++;
    }
	free(coords->box);
	free(coords);
	return 0;
}