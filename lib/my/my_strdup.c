/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** task01
*/
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;
    int j = 0;
    while (src[i] != '\0') {
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    while (src[j] != '\0') {
        str[j] = src[j];
        j++;
    }
    str[j] = '\0';
    return str;
}
