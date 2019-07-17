/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:18+02:00
 */

#include "my.h"

int event_reset(global_t *gbl, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && \
        sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue)
        reset_altitude(maps);
    else if (gbl->event.type == sfEvtKeyPressed) {
        if (gbl->event.key.code == sfKeySpace) {
            maps->zoom = 14;
            maps->posx = 7 * WIDTH / 10;
            maps->posy = HEIGHT / 10;
            maps->rx = 69;
            maps->ry = 54;
            maps->rz = 1;
        }
    }
}

void event_rot(global_t *gbl, map_t *maps)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
            maps->ry += 1;
        else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
            maps->ry -= 1;
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            maps->rx += 1;
        else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
            maps->rx -= 1;
        if (sfKeyboard_isKeyPressed(sfKeyPageUp) == sfTrue)
            maps->rz += 1;
        else if (sfKeyboard_isKeyPressed(sfKeyPageDown) == sfTrue)
            maps->rz -= 1;
    }
}

void select_button_a(int idx, map_t *maps, object_t *button)
{
    button->but_coord.left = 111;
    select_button_b(idx, maps, button);
    if (idx == 6)
        maps->mod.options = (-21);
    else if (idx == 7)
        maps->mod.help *= (-1);
    if (idx == 8) {
        randomize_map_borders(maps);
        randomize_map_insides(maps);
    } else if (idx == 3 && maps->mapX > 20)
        reshape_mapz(maps, (-1));
}

void init_text(text_t *text)
{
    sfText_setFont(text->help, text->font);
    sfText_setCharacterSize(text->help, 24);
    sfText_setColor(text->help, (sfWhite));
    sfText_setPosition(text->help, (sfVector2f){1000, 530});
    sfText_setString(text->help, "Welcome to my_world!\n\nUsage:\n  \
Open new random map: ./my_world\n  Open existing map: \
./my_world $map_file\n\nButton 1: Change the brush size   |   Right/Left \
click to increase/decrease altitude of the ground\nButton 2: \
Enable/Disable dotted mode\nButton 3/4: Increase/Decrease map size by one\n\
Button 5: Randomize the ground\nButton 6: Open the option menu =>\tClick the \
|\"Save\" Button to create a save file of the current map.\n\t\t\t\t\t\t\t\
\t\t\t\t\t\t\t\t\t\t\t|\"Quit\" Button to quit the program (you can also \
press the escape key).\n\n - Use arrows to move the map on your screen.\n \
- Use the Page(Up/Down) keys to zoom or unzoom\n - Use \"Ctrl\" with the \
keys quoted above to rotate the map.\n - Use \"Space\" key to reset zoom \
and rotation.\n - Use \"Ctrl\" + \"Space\" to set every altitude to 0.");
}

void draw_help_window(global_t *gbl, map_t *maps)
{
    init_text(&gbl->text);
    sfSprite_setPosition(gbl->text.sprite, (sfVector2f){gbl->text.vector.x - 50, gbl->text.vector.y - 120});
    sfRenderWindow_drawSprite(gbl->window, gbl->text.sprite, NULL);
    sfRenderWindow_drawText(gbl->window, gbl->text.help, NULL);
}
