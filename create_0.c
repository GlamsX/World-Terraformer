/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:49+02:00
 */

#include "my.h"

sfVertexArray *create_square(sfVector2f *v, int highness, float shade)
{
    sfColor color = choose_color(highness, shade);
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

sfVertexArray *create_base(map_t *maps)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2f a = project_iso_point(0, 0, (-100), maps);
    sfVector2f b = project_iso_point((maps->mapX - 1) * maps->zoom, \
    0, (-100), maps);
    sfVector2f c = project_iso_point((maps->mapX - 1) * maps->zoom, \
    (maps->mapY - 1) * maps->zoom, (-100), maps);
    sfVector2f d = project_iso_point(0, (maps->mapY - 1) * maps->zoom, \
    (-100), maps);
    sfVertex ver1 = {.position = a, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver2 = {.position = b, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver3 = {.position = c, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver4 = {.position = d, .color = (sfColor){76, 25, 25, 255}};

    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_append(vertex_array, ver3);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

sfVertexArray *create_sidex(map_t *maps, int x, int y)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2f a = maps->map[x][y];
    sfVector2f b = maps->map[x][y + 1];
    sfVector2f c = project_iso_point(x * maps->zoom, (y + 1) * maps->zoom, \
    (-100), maps);
    sfVector2f d = project_iso_point(x * maps->zoom, y * maps->zoom, \
    (-100), maps);
    sfVertex ver1 = {.position = a, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver2 = {.position = b, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver3 = {.position = c, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver4 = {.position = d, .color = (sfColor){76, 25, 25, 255}};

    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_append(vertex_array, ver3);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

sfVertexArray *create_sidey(map_t *maps, int x, int y)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2f a = maps->map[x][y];
    sfVector2f b = maps->map[x + 1][y];
    sfVector2f c = project_iso_point((x + 1) * maps->zoom, y * maps->zoom, \
    (-100), maps);
    sfVector2f d = project_iso_point(x * maps->zoom, y * maps->zoom, \
    (-100), maps);
    sfVertex ver1 = {.position = a, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver2 = {.position = b, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver3 = {.position = c, .color = (sfColor){76, 25, 25, 255}};
    sfVertex ver4 = {.position = d, .color = (sfColor){76, 25, 25, 255}};

    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_append(vertex_array, ver3);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

sfVertexArray *create_line(sfVector2f a, sfVector2f b, \
sfVector2f c, sfVector2f d)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex ver1 = {.position = a, .color = sfWhite};
    sfVertex ver2 = {.position = b, .color = sfWhite};
    sfVertex ver3 = {.position = c, .color = sfWhite};
    sfVertex ver4 = {.position = d, .color = sfWhite};

    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_append(vertex_array, ver1);
    sfVertexArray_append(vertex_array, ver3);
    sfVertexArray_append(vertex_array, ver4);
    sfVertexArray_append(vertex_array, ver2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}
