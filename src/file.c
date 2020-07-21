/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:53:25 by kirill            #+#    #+#             */
/*   Updated: 2020/07/21 18:44:15 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_wdcounter(char const *str, char c)
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

void		ft_zapolnenie(int *z_line, char *line)
{
	char	**nums;
	int		i;

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

int			ft_vysota(char *file, t_fdf *coords)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		if (i == 0)
			coords->width = ft_wdcounter(line, ' ');
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int			ft_file(t_fdf *coords, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	coords->height = ft_vysota(file, coords);
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
	return (0);
}
