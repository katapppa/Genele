#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "get_next_line.h"

typedef struct
{
    int     height;
    int     width;
    int     **box;
}       fdf;

int     ft_file(fdf *coords, char *file);

#endif