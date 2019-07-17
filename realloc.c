/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:26:11+02:00
 */

#include "my.h"

int *int_unrealloc(int *tab, int size_of_tab, int to_sub)
{
    int *new_tab = malloc(sizeof(int) * (size_of_tab - to_sub + 1));
    int i = 0;

    for (; i < size_of_tab - to_sub; ++i)
        new_tab[i] = tab[i];
    new_tab[i] = NULL;
    return (new_tab);
}

int **int_tab_unrealloc(int **tab, int size_of_tab, int to_sub)
{
    int **new_tab = malloc(sizeof(int *) * (size_of_tab - to_sub + 1));
    int i = 0;

    for (; i < size_of_tab - to_sub; ++i)
        new_tab[i] = int_unrealloc(tab[i], size_of_tab, to_sub);
    new_tab[i] = NULL;
    return (new_tab);
}

int *int_realloc(int *tab, int size_of_tab, int size_to_add)
{
    int *new_tab = malloc(sizeof(int) * (size_of_tab + size_to_add));
    int i = 0;

    for (; i < size_of_tab; i++)
        new_tab[i] = tab[i];
    if (i == size_of_tab)
        while (i < size_of_tab + size_to_add) {
            new_tab[i] = 0;
            i++;
        }
    return (new_tab);
}

int **int_tab_realloc(int **tab, int size_of_tab, int size_to_add)
{
    int **new_tab = malloc(sizeof(int *) * (size_of_tab + size_to_add + 1));
    int i = 0;

    for (; i < size_of_tab; ++i)
        new_tab[i] = int_realloc(tab[i], size_of_tab, size_to_add);
    if (i == size_of_tab) {
        for (; i < size_of_tab + size_to_add; i++)
            new_tab[i] = full_with_zero(size_of_tab, size_to_add);
    }
    new_tab[i] = NULL;
    return (new_tab);
}

void select_button_b(int idx, map_t *maps, object_t *button)
{
    if (idx == 1) {
        maps->mod.brush += 40;
        maps->mod.brush %= 160;
        if (maps->mod.brush == 0)
            maps->mod.brush = 40;
    } else if (idx == 2 && maps->mapX < 401)
        reshape_mapz(maps, 1);
    if (idx == 4)
        maps->mod.options *= (-1);
    else if (idx == 5)
        save_map(maps);
    if (idx == 9)
        reset_altitude(maps);
}
