/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/15 12:34:06 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     deal_key(int key, void *data)
{
	return 0;
}

int		main(int argc, char **argv)
{
	int i=0;
	int j=0;
	int fd;
	fdf *coords;
	
	coords = (fdf*)malloc(sizeof(fdf));
	if (argc == 1 || argc > 2)
	{
		printf("ERROR\n");
		return (0);
	}
	//fd = open(argv[1], O_RDONLY, 0);
	//close(fd);
	// if (fd == 0)
	// 	printf ("OSHIBKA");
	ft_file(coords, argv[1]);
	coords->mlx_ptr = mlx_init();
	coords->win_ptr = mlx_new_window(coords->mlx_ptr, 1000, 1000, "FDF");
	ft_draw(10, 10, 600, 300, coords);
	mlx_key_hook(coords->win_ptr, deal_key, NULL);
	mlx_loop(coords->mlx_ptr);
	i = 0;
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