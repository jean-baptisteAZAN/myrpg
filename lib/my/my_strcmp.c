/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** strncmp
*/

#include <unistd.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    for (;((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')); i++);
    return (s1[i] - s2[i]);
}
