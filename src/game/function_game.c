/*
** EPITECH PROJECT, 2023
** ALL fonction
** File description:
** function : fonction_game.c
*/
#include "my.h"
#include "my_rpg.h"

// Return 1 if is good or 0 if is not good
// zone : [X-min][X-max][Y-min][Y-max]
int verif_zone_point(int* zone, int x, int y)
{
    if (x >= zone[0] && x <= zone[1]) {
        if (y >= zone[2] && y <= zone[3])
            return 1;
    }
    return 0;
}

int verif_zone(int* zone, sfRenderWindow* window_r)
{
    sfWindow *window = (sfWindow*)sfRenderWindow_getSystemHandle(window_r);
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2u size_w = sfWindow_getSize(window);
    float width = size_w.x;
    float height = size_w.y;
    float radio_x = width / 1920;
    float radio_y = height / 1029;
    zone[0] *= radio_x;
    zone[1] *= radio_x;
    zone[2] *= radio_y;
    zone[3] *= radio_y;
    if (mouse.x >= zone[0] && mouse.x <= zone[1]) {
        if (mouse.y >= zone[2] && mouse.y <= zone[3])
            return 1;
    }
    return 0;
}

char* int_pass_char(int nbr)
{
    int tmp = nbr;
    int dgt = 0;
    while (tmp != 0) {
        tmp /= 10;
        dgt++;
    }
    char* str = (char*) malloc((dgt + 1) * sizeof(char));
    tmp = nbr;
    str[dgt] = '\0';
    for (int i = dgt - 1; i >= 0; i--) {
        str[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    return str;
}

char *int_to_char(int nbr)
{
    int i = 0;
    char tmp;
    char *str = malloc(sizeof(char) * 20);

    if (nbr == 0) {
        str[i++] = '0';
    } else {
        while (nbr > 0) {
            str[i++] = (nbr % 10) + '0';
            nbr /= 10;
        }
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        tmp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tmp;
    }
    return str;
}

int	my_getnbr(char const *str)
{
    int neg = 1;
    long nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45)
            neg = neg * -1;
        if (str[i] >= 48 && str[i] <= 57)
            nb = nb * 10 + (str[i] - 48);
        nb = nb * neg;
        if (nb < -2147483648 || nb > 2147483647)
            return 0;
        nb = nb * neg;
    }
    int result = nb * neg;
    return result;
}
