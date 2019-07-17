/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:45+02:00
 */

#include "my.h"

void free_struct(object_t **button, map_t *maps)
{
    for (int idx = 0; idx < 2; idx++) {
        sfSprite_destroy(button[idx]->sprite);
        sfTexture_destroy(button[idx]->texture);
        free(button[idx]);
    }
    for (int x = 0; x < maps->mapX; x++) {
        free(maps->mapz[x]);
        free(maps->map[x]);
    }
    free(maps->mapz);
    free(maps->map);
    free(button);
}

int error_file(FILE *fp, char *file)
{
    if (fp == NULL) {
        write(2, "Couldn't open the file: please \
check if this file does really exist.\n", 69);
        return (-1);
    } else {
        while (file[0] != '.' && file[0] != 0)
            file++;
        if (file[0] == 0 || my_strcmp(file, ".legend") == 1) {
            write(2, "Wrong format file: \
it must be a \".legend\" file.\n", 48);
            return (-1);
        }
    }
    return (0);
}
