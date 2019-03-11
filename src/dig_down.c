/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Digs down when called
*/

#include "world.h"

static int dcr_corner_altitude(sfRenderWindow *win, map_t *map, int i, int j)
{
    map->grid[i][j].altitude -= 1;
    update_points(map);
    return (1);
}

void dig_down_corner(sfRenderWindow *win, map_t *map)
{
    int *index = transfer_indexes(NULL);

    if (index == NULL) {
        update_selected_point(win, map);
        index = transfer_indexes(NULL);
    }
    dcr_corner_altitude(win, map, index[0], index[1]);
}

static int dcr_square_alitude(sfRenderWindow *win, map_t *map, int i, int j)
{
    if (!is_on_tile(win, map, &map->grid[i], j))
        return (0);
    map->grid[i][j].altitude -= 1;
    map->grid[i][j + 1].altitude -= 1;
    map->grid[i + 1][j].altitude -= 1;
    map->grid[i + 1][j + 1].altitude -= 1;
    update_points(map);
    return (1);
}

void dig_down_square(sfRenderWindow *win, map_t *map)
{
    int n_return = 0;

    for (int i = map->rows - 2; i >= 0; i--) {
        for (int j = map->columns - 2; j >= 0 && n_return == 0; j--)
            n_return = dcr_square_alitude(win, map, i, j);
        if (n_return == 1)
            break;
    }
}
