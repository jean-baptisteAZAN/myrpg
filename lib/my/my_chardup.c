/*
** EPITECH PROJECT, 2022
** char
** File description:
** char**
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char const *src);

void my_freechar(char **str)
{
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}

char **my_chardup(char **str, char **src)
{
    int i = 0;
    int cpt = 0;
    my_freechar(str);
    for (; src[cpt]; cpt++);
    str = malloc(sizeof(char *) * (cpt + 1));
    for (; src[i]; i++) {
        str[i] = my_strdup(src[i]);
    }
    str[i] = NULL;
    return (str);
}
