/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:20+02:00
 */

#include "my.h"

void randomize_map_borders(map_t *maps)
{
    int scale = rand_scale();

    for (int x = 1; x < maps->mapX; x++) {
        scale = rand_scale();
        if (maps->mapz[0][x - 1] >= 150)
            scale = (-1);
        else if (maps->mapz[0][x - 1] <= 0)
            scale = 1;
        maps->mapz[0][x] = maps->mapz[0][x - 1] + scale * (rand() % 40);
    }
    for (int y = 1; y < maps->mapY; y++) {
        scale = rand_scale();
        if (maps->mapz[y - 1][0] >= 150)
            scale = (-1);
        else if (maps->mapz[y - 1][0] <= 0)
            scale = 1;
        maps->mapz[y] = malloc(sizeof(int) * (maps->mapX + 1));
        maps->mapz[y + 1] = NULL;
        maps->mapz[y][0] = maps->mapz[y - 1][0] + scale * (rand() % 40);
    }
}

void randomize_map_insides(map_t *maps)
{
    int scale;

    for (int y = 1; y < maps->mapY; y++) {
        for (int x = 1; x < maps->mapX; x++)
            rand_map_real_insides(maps, x, y);
    }
}

void get_threed_coords(float ax, float ay, float az, map_t *maps)
{
    float tmp;

    tmp = maps->vthf.x * cos(ax) - maps->vthf.y * sin(ax);
    maps->vthf.y = maps->vthf.x * sin(ax) + maps->vthf.y * cos(ax);
    maps->vthf.x = tmp;
    tmp = maps->vthf.y * cos(ay) - maps->vthf.z * sin(ay);
    maps->vthf.z = maps->vthf.y * sin(ay) + maps->vthf.z * cos(ay);
    maps->vthf.y = tmp;
    tmp = maps->vthf.z * cos(az) - maps->vthf.x * sin(az);
    maps->vthf.x = maps->vthf.z * sin(az) + maps->vthf.x * cos(az);
    maps->vthf.z = tmp;
}

sfVector3f get_xyz_p(int x, int y, int z, map_t *maps)
{
    sfVector3f vdir;
    float tmp;
    float ax = ct_rad(maps->rx);
    float ay = ct_rad(maps->ry);
    float az = ct_rad(maps->rz);

    maps->vthf = (sfVector3f){x, y, z};
    get_threed_coords(ax, ay, az, maps);
    return (maps->vthf);
}

float get_shader(int x, int y, map_t *maps)
{
    sfVector3f sun = {(-1), (1), 0};
    sfVector3f vnorm;
    float len;
    sfVector3f v0 = get_xyz_p(x, y, maps->mapz[x][y], maps);
    sfVector3f v1 = get_xyz_p(x + 1, y, maps->mapz[x + 1][y], maps);
    sfVector3f v2 = get_xyz_p(x, y + 1, maps->mapz[x][y + 1], maps);

    vnorm.x = (v1.x - v0.x) * (v2.x - v0.x);
    vnorm.y = (v1.y - v0.y) * (v2.y - v0.y);
    vnorm.z = (v1.z - v0.z) * (v2.z - v0.z);
    len = norm_vector(vnorm.x, vnorm.y, vnorm.z);
    vnorm.x /= len;
    vnorm.y /= len;
    vnorm.z /= len;
    maps->shade = sun.x * vnorm.x + sun.y * vnorm.y + sun.z * vnorm.z;
}
