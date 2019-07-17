/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:26+02:00
 */

#include "my.h"

sfVector2f project_iso_point(int x, int y, int z, map_t *maps)
{
    sfVector2f point_2d;
    float tmp;
    float ax = ct_rad(maps->rx);
    float ay = ct_rad(maps->ry);
    float az = ct_rad(maps->rz);

    maps->rx %= 360;
    maps->ry %= 360;
    maps->rz %= 360;
    if (maps->rx < 0)
        maps->rx = 360 + maps->rx;
    if (maps->ry < 0)
        maps->ry = 360 + maps->ry;
    if (maps->rz < 0)
        maps->rz = 360 + maps->rz;
    maps->vthf = (sfVector3f){x, y, z};
    get_threed_coords(ax, ay, az, maps);
    point_2d.x = maps->vthf.x + maps->posx;
    point_2d.y = maps->vthf.y + maps->posy;
    return (point_2d);
}

void create_twod_map(map_t *maps)
{
    maps->map = malloc(sizeof(sfVector2f *) * (maps->mapX + 1));
    for (int x = 0; x < maps->mapX; x++) {
        maps->map[x] = malloc(sizeof(sfVector2f) * (maps->mapY + 1));
        for (int y = 0; y < maps->mapY; y++) {
            maps->map[x][y] = project_iso_point(x * maps->zoom, \
            y * maps->zoom, maps->mapz[x][y], maps);
        }
    }
    maps->map[maps->mapX] = NULL;
}

void modify_map(map_t *maps)
{
    for (int x = 0; maps->map[x] != NULL && x < maps->mapX; x++) {
        for (int y = 0; y < maps->mapY; y++) {
            maps->map[x][y] = project_iso_point(x * maps->zoom, \
            y * maps->zoom, maps->mapz[x][y], maps);
        }
    }
}

void draw_twod_map(global_t *gbl, map_t *maps)
{
    if (maps->ry <= 90)
        sfRenderWindow_drawVertexArray(gbl->window, create_base(maps), NULL);
    if (maps->rx < 90 && maps->rx >= 0)
        draw_ninety_deg(gbl->window, maps);
    else if (maps->rx < 180 && maps->rx >= 90)
        draw_h_eighty_deg(gbl->window, maps);
    if (maps->rx < 270 && maps->rx >= 180)
        draw_twoh_seventy_deg(gbl->window, maps);
    else if (maps->rx < 360 && maps->rx >= 270)
        draw_zero_deg(gbl->window, maps);
    if (maps->ry > 90)
        sfRenderWindow_drawVertexArray(gbl->window, create_base(maps), NULL);
    draw_twod_sides(gbl->window, maps);
}
