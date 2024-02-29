/*
** EPITECH PROJECT, 2023
** home_verif_file.c
** File description:
** home_verif_file
*/

#include "my.h"
#include "my_rpg.h"

int check_files(char **files)
{
    int i;
    FILE *fp;
    for (i = 0; i < 53; i++) {
        fp = fopen(files[i], "r");
        if (fp == NULL) {
            my_printf("Missing file: %s\n", files[i]);
            return -1;
        }
        fclose(fp);
    }
    return 0;
}

int sub_check_size_map(sfVector2u size)
{
    sfImage *map_all =
        sfImage_createFromFile("./ressources/res/game/map_all.png");
    size = sfImage_getSize(map_all);
    if (size.x != 1920 || size.y != 1080) {
        my_printf("Erreur de fichier avec le fichier: \
./ressources/res/game/map_all.png\n");
        return -1;
    }
    sfImage_destroy(map_all);
    sfImage *map_collision =
    sfImage_createFromFile("./ressources/res/game/map_collision.png");
    size = sfImage_getSize(map_collision);
    if (size.x != 1920 || size.y != 1080) {
        my_printf("Erreur de fichier avec le fichier: \
./ressources/res/game/map_collision.png\n");
        return -1;
    }
    sfImage_destroy(map_collision);
    return 0;
}

int check_size_map(void)
{
    sfVector2u size;
    sfImage *map_void;
    map_void = sfImage_createFromFile("./ressources/res/game/map_void.png");
    size = sfImage_getSize(map_void);
    if (size.x != 1920 || size.y != 1080) {
        my_printf("Erreur de fichier avec le fichier: \
./ressources/res/game/map_void.png\n");
        return -1;
    }
    sfImage_destroy(map_void);
    return sub_check_size_map(size);
}

int verif_file(void)
{
    if (check_files(create_tab_file()) == -1)
        return -1;
    if (check_size_map() == -1)
        return -1;
    return 0;
}
