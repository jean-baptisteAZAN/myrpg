/*
** EPITECH PROJECT, 2022
** strlen
** File description:
** strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int compt = 0;
    int i = 0;
    while (str[i] != '\0') {
        compt++;
        i++;
    }
    return (compt);
}
