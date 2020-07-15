#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "get_next_line.h"
#include <math.h>
#define MOD(x) (x > 0 ? x : -x)

typedef struct
{
    int     height;
    int     width;
    int     **box;
    int     zoom;
    int     color;

    void    *mlx_ptr;
    void    *win_ptr;
}       fdf;

int     ft_file(fdf *coords, char *file);
int     deal_key(int key, void *data);
void    ft_draw(float x, float y, float x0, float y0, fdf *coords);
void    ft_create(fdf *coords);

#endif