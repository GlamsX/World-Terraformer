/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:07+02:00
 */

#include "my.h"

void init_button_tab(object_t **button)
{
    button[0] = init_button("sprites/button1.png", \
    (sfVector2f){0, 5 * 78}, (sfIntRect){0, 0, 71, 78}, 0);
    button[1] = init_button("sprites/button2.png", \
    (sfVector2f){0, 4 * 78}, (sfIntRect){0, 0, 71, 78}, 1);
    button[2] = init_button("sprites/ButtonAdd.png", \
    (sfVector2f){0, 6 * 78}, (sfIntRect){0, 0, 71, 78}, 1);
    button[3] = init_button("sprites/ButtonSub.png", \
    (sfVector2f){0, 7 * 78}, (sfIntRect){0, 0, 71, 78}, 1);
    button[4] = init_button("sprites/options.png", \
    (sfVector2f){1849, 50}, (sfIntRect){0, 0, 71, 78}, 1);
    button[5] = init_button("sprites/save.png", \
    (sfVector2f){1920, 128}, (sfIntRect){0, 0, 71, 78}, 1);
    button[6] = init_button("sprites/quit.png", \
    (sfVector2f){1920, 206}, (sfIntRect){0, 0, 71, 78}, 1);
    button[7] = init_button("sprites/help.png", \
    (sfVector2f){1849, 953}, (sfIntRect){0, 0, 71, 78}, 1);
    button[8] = init_button("sprites/dice.png", \
    (sfVector2f){0, 8 * 78}, (sfIntRect){0, 0, 71, 78}, 1);
    button[9] = init_button("sprites/shave.png", \
    (sfVector2f){0, 9 * 78}, (sfIntRect){0, 0, 71, 78}, 1);
}

sfVertexArray *create_water(sfVector2f *v, float shade)
{
    sfColor color = {90, 188, 216, 180};
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex ver1 = {.position = v[0], .color = color};
    sfVertex ver2 = {.position = v[1], .color = color};
    sfVertex ver3 = {.position = v[2], .color = color};
    sfVertex ver4 = {.position = v[3], .color = color};

    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver3);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesFan);
    return (vertex_array);
}

void draw_all(sfRenderWindow *window, map_t *maps, int x, int y)
{
    sfRenderWindow_drawVertexArray(window, \
    create_square((sfVector2f[4]){maps->map[x][y], \
    maps->map[x][y + 1], maps->map[x + 1][y], \
    maps->map[x + 1][y + 1]}, maps->mapz[x][y], maps->shade), NULL);
}

int close_before(FILE *fp, char *str)
{
    fclose(fp);
    free(str);
    return (-1);
}
