/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:54+02:00
 */

#include "my.h"

global_t init_gbl(sfVideoMode mode)
{
    global_t gbl;

    gbl.window = sfRenderWindow_create(mode, "My_World", \
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(gbl.window, 50);
    gbl.event_val = 0;
    gbl.text.font = sfFont_createFromFile("text/font.ttf");
    gbl.text.help = sfText_create();
    gbl.text.sprite = sfSprite_create();
    gbl.text.texture = sfTexture_createFromFile("sprites/board.png", NULL);
    gbl.text.vector = (sfVector2f){960, 492};
    sfSprite_setTexture(gbl.text.sprite, gbl.text.texture, NULL);
    return (gbl);
}

mod_t init_mod(void)
{
    mod_t mod;

    mod.doted = (-1);
    mod.pincase = 1;
    mod.options = (-1);
    mod.brush = 80;
    mod.help = 1;
    mod.cir = sfCircleShape_create();
    return (mod);
}

map_t init_maps(int ac, char **av)
{
    map_t map;

    map.mod = init_mod();
    map.zoom = 14;
    map.posx = 7 * WIDTH / 10;
    map.posy = HEIGHT / 10;
    map.mapX = 80;
    map.mapY = 80;
    map.rx = 69;
    map.ry = 54;
    map.rz = 1;
    if (ac == 2 && text_to_int_arr(av[1], &map) == 0) {
        create_twod_map(&map);
    } else
        init_mapz(&map);
    sfCircleShape_setFillColor(map.mod.cir, (sfColor){207, 47, 47, 180});
    sfCircleShape_setOutlineColor(map.mod.cir, (sfColor){240, 240, 240, 180});
    sfCircleShape_setOutlineThickness(map.mod.cir, (float)(1.00));
    return (map);
}

object_t *init_button(char *path, sfVector2f vector, sfIntRect rec, int type)
{
    object_t *button = malloc(sizeof(object_t) * 1);

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(path, NULL);
    button->vector = vector;
    button->but_coord = rec;
    button->type = type;
    sfSprite_setTexture(button->sprite, button->texture, NULL);
    sfSprite_setTextureRect(button->sprite, button->but_coord);
    return (button);
}
