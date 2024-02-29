/*
** EPITECH PROJECT, 2023
** verif_info.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

int verif_info_where_name(char *str, int n)
{
    if (my_strlen(str) == 1 && n == 0) {
        if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3')
            return 0;
    }
    if (my_strlen(str) <= 11 && n == 1) {
        if (suite_verif_info_where_name(str) != -1)
            return 0;
    }
    return -1;
}

int verif_info_positif_nbr(char *str)
{
    if (my_strlen(str) > 50)
        return -1;
    if (my_strlen(str) == 0)
        return -1;
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] < '0' || str[n] > '9')
            return -1;
    }
    return 0;
}

// pos 1 = x & pos 2 = y
int verif_position_nbr(char *str, int pos)
{
    if (my_strlen(str) == 0 || my_strlen(str) == 1 || my_strlen(str) > 4)
        return -1;
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] < '0' || str[n] > '9')
            return -1;
    }
    if ((my_getnbr(str) > 1580 || my_getnbr(str) < 325) && pos == 1)
        return -1;
    if ((my_getnbr(str) < 93 || my_getnbr(str) > 957) && pos == 2)
        return -1;
    return 0;
}

int verif_sens_vehicule(char *str, int pos)
{
    if (my_strlen(str) != 1)
        return -1;
    if (pos == 1) {
        if (str[0] < '0' || str[0] > '7')
            return -1;
    }
    if (pos == 2) {
        if (str[0] != '0' && str[0] != '2' && str[0] != '4' && str[0] != '6')
            return -1;
    }
    return 0;
}

int verif_info_in_load(char *str, int n)
{
    if (n == 0 || n == 1)
        return verif_info_where_name(str, n);
    if ((n >= 2 && n <= 4) || n == 7)
        return verif_info_positif_nbr(str);
    if (n == 8 || n == 9)
        return sub_verif_info_in_load(str, n);
    if (n == 5 || n == 10 || n == 13 || n == 16)
        return verif_position_nbr(str, 1);
    if (n == 6 || n == 11 || n == 14 || n == 17)
        return verif_position_nbr(str, 2);
    if (n == 12)
        return verif_sens_vehicule(str, 1);
    if (n == 15 || n == 18)
        return verif_sens_vehicule(str, 2);
    return 0;
}
