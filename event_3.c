/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:27:14+02:00
 */

#include "my.h"

void reset_altitude(map_t *maps)
{
    for (int x = 0; x < maps->mapX; ++x) {
        for (int y = 0; y < maps->mapY; ++y)
            maps->mapz[x][y] = 24;
    }
}

int count_size(char *filemap)
{
    char *str = malloc(sizeof(char) * 2);
    int fd = open(filemap, O_RDONLY);
    int n = 0;

    if (fd == (-1))
        return (-1);
    for (; read(fd, str, 1); ++n);
    close(fd);
    free(str);
    return (n);
}

int count_numbers(char *str)
{
    int n = 0;

    if (!str)
        return (0);
    for (int idx = 0; str[idx] != 0; ++idx) {
        if (str[idx] == ':')
            ++n;
    }
    return (n);
}

void stock_numbers(int *arr, char *str)
{
    int idx;
    char **tab = my_str_to_word_array(str, ':');

    for (idx = 0; tab[idx] != NULL; ++idx)
        arr[idx] = my_getnbr(tab[idx]);
    arr[idx] = NULL;
}

int text_to_int_arr(char *filemap, map_t *maps)
{
    ssize_t size = count_size(filemap);
    char *str = malloc(sizeof(char) * size + 1);
    FILE *fp = fopen(filemap, "r");
    int mal;

    if (error_file(fp, filemap) == (-1) || size == (-1))
        return (close_before(fp, str));
    size = getline(&str, &size, fp);
    mal = count_numbers(str);
    maps->mapz = malloc(sizeof(int *) * (mal + 1));
    for (int idx = 0; size != (-1); ++idx) {
        maps->mapz[idx] = malloc(sizeof(int) * (mal + 1));
        size = getline(&str, &size, fp);
        str[size - 1] = 0;
        stock_numbers(maps->mapz[idx], str);
        maps->mapX = idx + 1;
    }
    maps->mapY = maps->mapX;
    close_before(fp, str);
    return (0);
}
