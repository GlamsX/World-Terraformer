/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:39+02:00
 */

#include "my.h"

void draw_sides_a(sfRenderWindow *window, map_t *maps)
{
    if (maps->rx < 90 && maps->rx >= 0) {
        for (int y = 0; y < maps->mapY - 1; ++y) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidex(maps, maps->mapX - 1, y), NULL);
        }
        for (int x = 0; x < maps->mapX - 1; ++x) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidey(maps, x, maps->mapY - 1), NULL);
        }
    } else if (maps->rx < 180 && maps->rx >= 90) {
        for (int y = 0; y < maps->mapY - 1; ++y) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidex(maps, maps->mapX - 1, y), NULL);
        }
        for (int x = 0; x < maps->mapX - 1; ++x) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidey(maps, x, 0), NULL);
        }
    }
}

void draw_sides_b(sfRenderWindow *window, map_t *maps)
{
    if (maps->rx < 270 && maps->rx >= 180) {
        for (int y = 0; y < maps->mapY - 1; ++y) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidex(maps, 0, y), NULL);
        }
        for (int x = 0; x < maps->mapX - 1; ++x) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidey(maps, x, 0), NULL);
        }
    } else if (maps->rx < 360 && maps->rx >= 270) {
        for (int y = 0; y < maps->mapY - 1; ++y) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidex(maps, 0, y), NULL);
        }
        for (int x = 0; x < maps->mapX - 1; ++x) {
            sfRenderWindow_drawVertexArray(window, \
            create_sidey(maps, x, maps->mapY - 1), NULL);
        }
    }
}

void draw_twod_sides(sfRenderWindow *window, map_t *maps)
{
    if (maps->rx < 180 && maps->rx >= 0)
        draw_sides_a(window, maps);
    else
        draw_sides_b(window, maps);
}

void draw_button(global_t *gbl, object_t *button[], int nb_sprite, map_t *maps)
{
    if (maps->mod.options == 1)
        seeable_button(button);
    else
        unseeable_button(button);
    for (int idx = 0; idx < nb_sprite; idx++) {
        sfSprite_setPosition(button[idx]->sprite, button[idx]->vector);
        sfRenderWindow_drawSprite(gbl->window, button[idx]->sprite, NULL);
    }
    sfCircleShape_setRadius(maps->mod.cir, maps->mod.brush);
    sfCircleShape_setPosition(maps->mod.cir, (sfVector2f){50, 100});
    sfRenderWindow_drawCircleShape(gbl->window, maps->mod.cir, NULL);
}
