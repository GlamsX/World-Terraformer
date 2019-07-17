/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:34+02:00
 */

#include "my.h"

void seeable_button(object_t *button[])
{
    for (int idx = 5; idx < 7; ++idx) {
        if (button[idx]->vector.x > 1849)
            button[idx]->vector.x -= 5;
        else
            button[idx]->vector.x = 1849;
    }
}

void unseeable_button(object_t *button[])
{
    for (int idx = 5; idx < 7; ++idx)
        if (button[idx]->vector.x < 1920)
            button[idx]->vector.x += 5;
}

void detect_real_nearest(map_t *maps, int tril, int ret, int x)
{
    for (int y = 0; y < maps->mapY; y++) {
        maps->opp = abs(maps->map[x][y].y - maps->mouse.y);
        maps->adj = abs(maps->map[x][y].x - maps->mouse.x);
        if (maps->opp + maps->adj < ret) {
            maps->mapz[x][y] += tril;
        }
    }
}

int *full_with_zero(int size_of_tab, int size_to_add)
{
    int *tab = malloc(sizeof(int) * (size_of_tab + size_to_add));

    for (int j = 0; j < size_of_tab + size_to_add; j++)
        tab[j] = 0;
    return (tab);
}

void rand_map_real_insides(map_t *maps, int x, int y)
{
    int scale = rand_scale();

    if (((maps->mapz[y - 1][x] + maps->mapz[y][x - 1]) / 2) >= 150)
        scale = (-1);
    else if (((maps->mapz[y - 1][x] + maps->mapz[y][x - 1]) / 2) <= 00)
        scale = 1;
    maps->mapz[y][x] = ((maps->mapz[y - 1][x] + \
    maps->mapz[y][x - 1]) / 2) + scale * (rand() % 10);
}
