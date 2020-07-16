#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "get_next_line.h"
#define MOD(x) (x < 0 ? -x : x)

typedef struct
{
    int     height;
    int     width;
    int     **box;
    int     zoom;
    int     color;
    int     sdvigx;
    int     sdvigy;
    int     ze;

    void    *mlx_ptr;
    void    *win_ptr;
}       fdf;

typedef struct 
{
    float x;
    float y;
    float x0;
    float y0;
    float z;
    float z0;
}       numbers;


int     ft_file(fdf *coords, char *file);
void    ft_draw(float x, float y, float x0, float y0, fdf *coords);
void    ft_create(fdf *coords);

#endif