/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:25:41+02:00
 */

#include "my.h"

int countwords(char const *str, char sep)
{
    int wor = 0;
    int is = 0;

    if (str == NULL)
        return (0);
    for (int idx = 0; str[idx] != 0;) {
        while (str[idx] == sep || str[idx] == '\t') {
            idx++;
            is = 0;
        }
        while (str[idx] != sep && str[idx] != 0 && str[idx] != '\t') {
            idx++;
            is = 1;
        }
        if (is == 1)
            wor++;
    }
    return (wor);
}

int countletters(char const *str, char sep)
{
    int let = 0;
    static int idx = 0;

    if (str == NULL)
        return (0);
    for (; (str[idx] == sep || str[idx] == '\t') && str[idx] != 0; idx++);
    for (; str[idx] != 0 && str[idx] != sep && str[idx] != '\t'; idx++)
        let++;
    for (; (str[idx] == sep || str[idx] == '\t') && str[idx] != 0; idx++);
    if (str[idx] == 0)
        idx = 0;
    return (let);
}

char **my_str_to_word_array(char const *str, char sep)
{
    int wor_nb = countwords(str, sep);
    char **tab = malloc(sizeof(char *) * (wor_nb + 1));
    int w = 0;
    int idx = 0;

    tab[wor_nb] = NULL;
    for (int n = 0; n < wor_nb; n++)
        tab[n] = malloc(sizeof(char) * countletters(str, sep) + 1);
    for (; str[idx] != 0 && w < wor_nb; idx++, w++) {
        for (; (str[idx] == '\t' || str[idx] == sep) && str[idx] != 0; idx++);
        for (int k = 0; str[idx] != '\t' && \
        str[idx] != sep && str[idx] != 0; k++, idx++) {
            tab[w][k] = str[idx];
            tab[w][k + 1] = 0;
        }
    }
    return (tab);
}

int my_getnbr(char const *str)
{
    int min = 0;
    int num = 0;

    for (int n = 0; str[n] != 0; n++) {
        if (str[n] == '-') {
            min++;
            n++;
        } else if (str[n] == '+')
            n++;
        if ('0' <= str[n] && str[n] <= '9')
            num = num * 10 + str[n] - 48;
        else if ('A' <= str[n] && str[n] <= 'z')
            break;
    }
    if (min % 2 == 1)
        num *= (-1);
    return (num);
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    for (int idx = 0; str1[idx] != 0 && str2[idx] != 0; idx++) {
        if (str1[idx] != str2[idx])
            return (1);
    }
    return (0);
}
