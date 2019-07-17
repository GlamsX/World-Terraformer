/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:47+02:00
 */

#include "my.h"

float ct_rad(int deg)
{
    return (deg * PI / 180);
}

float norm_vector(float x, float y, float z)
{
    return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

int rand_scale(void)
{
    int scale;

    if (rand() % 2 == 0)
        scale = 1;
    else
        scale = (-1);
    return (scale);
}

int my_strlen(char *str)
{
    int n = 0;

    if (str == NULL)
        return (0);
    for (; str[n] != 0; n++);
    return (n);
}

char *my_revstr(char *str)
{
    char tamp;
    int nb = my_strlen(str);

    for (int n = 0; n < nb; n++, nb--) {
        tamp = str[n];
        str[n] = str[nb - 1];
        str[nb - 1] = tamp;
    }
    return (str);
}
