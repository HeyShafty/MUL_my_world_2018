/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Contains the loop responsible of the editor
*/

#include "world.h"

void display_toolbox(toolbox_t *toolbox, map_t *map)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(toolbox->win, &event))
            analyse_events_win2(event, toolbox, map);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(toolbox->win, toolbox->sprites[i], NULL);
    sfRenderWindow_display(toolbox->win);
    sfRenderWindow_clear(toolbox->win, toolbox_color);
}

int loop_editor(sfRenderWindow *window, map_t *map, toolbox_t *tool)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window) || sfRenderWindow_isOpen(tool->win)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, map, event, tool);
        manage_mouse(map, window);
        sfRenderWindow_setView(window, map->view);
        draw_tiles(window, map);
        map->highlight(window, map);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        display_toolbox(tool, map);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
