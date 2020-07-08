/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 15:05:06 by kirill            #+#    #+#             */
/*   Updated: 2020/07/08 14:07:04 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fileopen();

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
	while(i < coords->height)
	{
		j = 0;
		while(j < coords->width)
		{
			printf("%d ", coords->box[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	while (i <= coords->height)
    {
		free(coords->box[i]);
        i++;
    }
	free(coords->box);
	free(coords);
	return 0;
}