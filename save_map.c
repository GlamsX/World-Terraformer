/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-30T16:45:21+02:00
 */

#include "my.h"

char *str_zero(void)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = '0';
    str[1] = 0;
    return (str);
}

char *int_to_str(int nb, char *str)
{
    int mal = 0;
    int m = 0;

    if (nb < 0) {
        mal++;
        m = 1;
        nb *= (-1);
    } else if (nb == 0)
        return (str_zero());
    for (int nb2 = nb; nb2 != 0; nb2 /= 10, mal++);
    str = malloc(sizeof(char) * (mal + 1));
    for (int idx = 0; nb != 0; nb /= 10, idx++)
        str[idx] = nb % 10 + 48;
    if (m == 1)
        str[mal - 1] = '-';
    str[mal] = 0;
    return (my_revstr(str));
}

void save_map(map_t *maps)
{
    FILE *fp;
    char *str = NULL;

    fp = fopen("save.legend", "w");
    if (fp == NULL)
        return;
    for (int x = 0; x < maps->mapX; x++) {
        for (int y = 0; y < maps->mapY; y++) {
            str = int_to_str(maps->mapz[x][y], str);
            fwrite(str, 1, my_strlen(str), fp);
            fwrite(":", 1, 1, fp);
            free(str);
        }
        fwrite("\n", 1, 1, fp);
    }
    fclose(fp);
}
