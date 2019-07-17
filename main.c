/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:04+02:00
 */

#include "my.h"

int event_window(global_t *gbl, map_t *maps, object_t **button)
{
    while (eve(gbl->window, &gbl->event)) {
        event_close(gbl, maps);
        event_button(gbl, maps, button);
        event_reset(gbl, maps);
    }
    event_mouse(gbl, maps);
    event_rot(gbl, maps);
    event_zoom(gbl, maps);
    event_moves(gbl, maps);
    return (0);
}

void init_mapz(map_t *maps)
{
    srand(&maps);
    maps->mapz = malloc(sizeof(int *) * (maps->mapY + 1));
    maps->mapz[0] = malloc(sizeof(int) * (maps->mapX + 1));
    maps->mapz[0][0] = rand_scale() * rand() % 150 + 40;
    randomize_map_borders(maps);
    randomize_map_insides(maps);
    create_twod_map(maps);
}

object_t **mal_button(void)
{
    object_t **button = malloc(sizeof(object_t *) * 10);

    init_button_tab(button);
    return (button);
}

int my_world(int ac, char **av)
{
    global_t gbl = init_gbl((sfVideoMode){WIDTH, HEIGHT, BIT_PIXEL});
    map_t maps = init_maps(ac, av);
    object_t **button = mal_button();

    while ((sfRenderWindow_isOpen(gbl.window) && gbl.event_val != (-1)) \
    || maps.mapz == NULL) {
        gbl.event_val = event_window(&gbl, &maps, button);
        modify_map(&maps);
        sfRenderWindow_clear(gbl.window, sfBlack);
        draw_twod_map(&gbl, &maps);
        if (maps.mod.help == 1)
            draw_help_window(&gbl, &maps);
        draw_button(&gbl, button, 10, &maps);
        sfRenderWindow_display(gbl.window);
    }
    free_struct(button, &maps);
    sfRenderWindow_destroy(gbl.window);
    return (0);
}

int main(int ac, char *av[])
{
    if (ac > 2) {
        write(2, "There was an error launching the program:\n\tPlease retry \
with \"./my_world\" or \"./my_world $savedmapfile.legend\"", 110);
        return (84);
    } else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write(1, "Welcome to my_world!\n\nUsage:\n  \
Open new random map: ./my_world\n  Open existing map: \
./my_world $map_file.legend\n", 112);
        return (0);
    }
    my_world(ac, av);
    return (0);
}
