/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:14+02:00
 */

#include "my.h"

void draw_ninety_deg(sfRenderWindow *window, map_t *maps)
{
    for (int x = 0; x < maps->mapX - 1; ++x)
        for (int y = 0; y < maps->mapY - 1; ++y)
            draw_annex(window, maps, x, y);
}

void draw_h_eighty_deg(sfRenderWindow *window, map_t *maps)
{
    for (int y = maps->mapY - 2; y >= 0; --y)
        for (int x = 0; x < maps->mapX - 1; ++x)
            draw_annex(window, maps, x, y);
}

void draw_twoh_seventy_deg(sfRenderWindow *window, map_t *maps)
{
    for (int x = maps->mapX - 2; x >= 0; --x)
        for (int y = maps->mapY - 2; y >= 0; --y)
            draw_annex(window, maps, x, y);
}

void draw_zero_deg(sfRenderWindow *window, map_t *maps)
{
    for (int y = 0; y < maps->mapY - 1; ++y)
        for (int x = maps->mapX - 2; x >= 0; --x)
            draw_annex(window, maps, x, y);
}

sfColor choose_color(int h, float sh)
{
    if (h > 120)
        return ((sfColor){(255 * sh), (250 * sh), (250 * sh), 255});
    if (h > 90)
        return ((sfColor){(149 * sh), (148 * sh), (139* sh), 255});
    if (h < 20)
        return ((sfColor){(238 * sh), (191 * sh), sh, 255});
    else
        return ((sfColor){(56 * sh), (196 * sh), (28 * sh), 255});
}
