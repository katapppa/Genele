/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menuhelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:59:09 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/22 15:55:25 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_anglele(int key, t_fdf *coords)
{
	if (key == 23)
		coords->angle -= 0.1;
	if (key == 22)
		coords->angle += 0.1;
}

void		ft_zeze(int key, t_fdf *coords)
{
	if (key == 91)
		coords->ze += 1;
	if (key == 84)
		coords->ze -= 1;
}

int			ft_isfdf(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'f')
		{
			i++;
			if (line[i] == 'd')
			{
				i++;
				if (line[i] == 'f')
				{
					i++;
					if (line[i] == '\0')
						return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

void		ft_perror(t_fdf *coords)
{
	free(coords);
	perror("ERROR");
	exit(1);
}

void		ft_perror1(t_fdf *coords, int i)
{
	while (i)
	{
		free(coords->box[i]);
		i--;
	}
	free(coords->box);
	free(coords);
	perror("ERROR");
	exit(1);
}
