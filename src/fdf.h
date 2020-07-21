/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:27:52 by cgamora           #+#    #+#             */
/*   Updated: 2020/07/21 18:07:49 by cgamora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "get_next_line.h"
# define MOD(x) (x < 0 ? -x : x)

typedef struct	s_fdf
{
	int			dvad;
	int			a;
	int			b;
	int			height;
	int			width;
	int			**box;
	int			zoom;
	int			color;
	int			sdvigx;
	int			sdvigy;
	float		angle;
	int			ze;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct	s_numbers
{
	float		x;
	float		y;
	float		x0;
	float		y0;
	float		z;
	float		z0;
	float		xstart;
	float		x0end;
	float		ystart;
	float		y0end;
	int			sc;
	int			ec;
}				t_numbers;

int				deal_key(int key, t_fdf *coords);
int				ft_file(t_fdf *coords, char *file);
void			ft_draw(t_numbers *num, t_fdf *coords);
void			ft_create(t_fdf *coords);
t_numbers		*ft_createy(t_numbers *num, int x, int y);
t_numbers		*ft_createx(t_numbers *num, int x, int y);
double			ft_percent(int start, int end, int current);
int				get_color(t_numbers *num);
double			ft_percenta(int start, int end, int current);
void			ft_print_menu(t_fdf *coords);
void			ft_init_struct(t_fdf *coords);
void			ft_dvad(t_fdf *coords);
void			ft_helper(t_numbers *num);
int				ft_colorizerr(t_numbers *num);
int				ft_colorizer(t_numbers *num);
void			ft_anglele(int key, t_fdf *coords);
void			ft_zoomzoom(int key, t_fdf *coords);
void			ft_zeze(int key, t_fdf *coords);
int				get_light(int start, int end, double percentage);

#endif
