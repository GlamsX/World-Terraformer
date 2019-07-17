/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:31+02:00
 */

#include "my.h"

void draw_annex(sfRenderWindow *window, map_t *maps, int x, int y)
{
    if (maps->mod.doted == 1)
        sfRenderWindow_drawVertexArray(window, \
        create_line(maps->map[x][y], maps->map[x][y + 1], \
        maps->map[x + 1][y], maps->map[x + 1][y + 1]), NULL);
    get_shader(x, y, maps);
    maps->shade = (maps->shade + (2.2)) / (1.5);
    if (maps->shade > 1.00)
        maps->shade = 1.00;
    draw_all(window, maps, x, y);
}
