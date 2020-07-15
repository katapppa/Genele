/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:53:25 by kirill            #+#    #+#             */
/*   Updated: 2020/07/15 12:15:33 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void    ft_zapolnenie(int *z_line, char *line)
{
    char    **nums;
    int i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}

// int     ft_shyrota(char *file)
// {
//     int     i;
//     int     y;
//     char    *line;
//     int     fd;

//     i = 0;
//     y = 0;
//     fd = open(file, O_RDONLY, 0);
//     while (get_next_line(fd, &line))
//     {
//         while (line[y] != '\0')
//         {
//             while(line[y] != ' ' && line[y] != '\0')
//                 y++;
//             i++;
//             while(line[y] == ' ')
//                 y++;
//         }
//         free(line);
//         printf("I IS : %d\n", i);
//     }
//     close(fd);
//     return (i);
// }

int     ft_vysota(char *file, fdf *coords)
{
    int     i;
    char    *line;
    int     fd;

    i = 0;
    fd = open(file, O_RDONLY, 0);
    while(get_next_line(fd, &line))
    {
        if (i == 0)
            coords->width = ft_wdcounter(line, ' ');
        i++;
        free(line);
    }
    close(fd);
    return (i);
}

int     ft_file(fdf *coords, char *file)
{
    int     i;
    int     fd;
    char    *line;

    i = 0;
    coords->height = ft_vysota(file, coords);
    //coords->width = ft_shyrota(file);
    coords->box = (int**)malloc(sizeof(int*) * (coords->height + 1));
    while (i <= coords->height)
    {
        coords->box[i] = (int*)malloc(sizeof(int) * (coords->width + 1));
        i++;
    }
    i = 0;
    fd = open(file, O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        ft_zapolnenie(coords->box[i], line);
        free(line);
        i++;
    }
    close(fd);
    printf("%d\n", coords->height);
    printf("%d\n", coords->width);
    return 0;
}