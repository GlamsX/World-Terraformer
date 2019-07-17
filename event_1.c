/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:24+02:00
 */

#include "my.h"

void detect_nearest(map_t *maps, int tril, int ret)
{
    for (int x = 0; x < maps->mapX; x++)
        detect_real_nearest(maps, tril, ret, x);
}

void choose_mod(int idx, map_t *maps, object_t *button)
{
    if (idx == 0) {
        maps->mod.doted *= (-1);
        if (maps->mod.doted == 1) {
            button->but_coord.left = 111;
        } else
            button->but_coord.left = 0;
    } else if (idx == 1) {
        maps->mod.pincase *= (-1);
        if (maps->mod.pincase == (-1)) {
            button->but_coord.left = 111;
        } else
            button->but_coord.left = 0;
    }
    if (button->type == 1)
        select_button_a(idx, maps, button);
    sfSprite_setTextureRect(button->sprite, button->but_coord);
}

void click_it(map_t *maps, object_t **button, global_t *gbl)
{
    float x;
    float y;
    float wid;
    float hei;

    gbl->vec = sfRenderWindow_getSize(gbl->window);
    for (int idx = 0; idx < 10; idx++) {
        x = button[idx]->vector.x;
        y = button[idx]->vector.y;
        wid = button[idx]->but_coord.width;
        hei = button[idx]->but_coord.height;
        if (maps->mouse.x > x && maps->mouse.x < x + wid && \
        maps->mouse.y > y - (HEIGHT - gbl->vec.y) && \
        maps->mouse.y < y + hei - (HEIGHT - gbl->vec.y)) {
            choose_mod(idx, maps, button[idx]);
            break;
        }
    }
}

void reshape_mapz(map_t *maps, int act)
{
    for (int x = 0; x < maps->mapX; x++)
        free(maps->map[x]);
    free(maps->map);
    if (act == 1)
        maps->mapz = int_tab_realloc(maps->mapz, maps->mapX, 1);
    else if (act = (-1))
        maps->mapz = int_tab_unrealloc(maps->mapz, maps->mapX, 1);
    maps->mapX = maps->mapX + act;
    maps->mapY = maps->mapX;
    create_twod_map(maps);
}

void event_button(global_t *gbl, map_t *maps, object_t **button)
{
    maps->mouse = sfMouse_getPosition(gbl->window);
    for (int idx = 0; idx < 10; idx++) {
        if (button[idx]->type == 1) {
            button[idx]->but_coord.left = 0;
            sfSprite_setTextureRect(button[idx]->sprite, \
            button[idx]->but_coord);
        }
    }
    if (gbl->event.key.code == sfMouseLeft) {
        if (gbl->event.type == sfEvtMouseButtonPressed)
            click_it(maps, button, gbl);
    }
}
