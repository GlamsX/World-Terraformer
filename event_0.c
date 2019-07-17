/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:28+02:00
 */

#include "my.h"

int event_close(global_t *gbl, map_t *maps)
{
    if (gbl->event.type == sfEvtClosed ||
    (gbl->event.key.code == sfKeyEscape &&
    gbl->event.type == sfEvtKeyPressed) || maps->mod.options == (-21)) {
        sfRenderWindow_close(gbl->window);
        return (-1);
    }
}

int event_zoom(global_t *gbl, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfFalse) {
        if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue)
            maps->zoom += maps->zoom / 10;
        else if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue)
            maps->zoom -= maps->zoom / 10;
    }
}

int event_moves(global_t *gbl, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfFalse) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
            maps->posy -= maps->zoom;
        else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
            maps->posy += maps->zoom;
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            maps->posx += maps->zoom;
        else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
            maps->posx -= maps->zoom;
    }
}

int event_mouse(global_t *gbl, map_t *maps)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        maps->mouse = sfMouse_getPosition(gbl->window);
        detect_nearest(maps, 1, maps->mod.brush);
    } else if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
        maps->mouse = sfMouse_getPosition(gbl->window);
        detect_nearest(maps, (-1), maps->mod.brush);
    }
}
