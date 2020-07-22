#define MOD(x) (x < 0 ? -x : x)
#include <stdio.h>
#include "fdf.h"

int     main()
{
    mlx_init();
    return 0;
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