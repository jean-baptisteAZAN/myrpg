/*
** EPITECH PROJECT, 2023
** home_load_game.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void load_line_eighteen(main_s *data, char *str, int n)
{
    if (n == 10)
        data->pickup_s.pos_x = my_getnbr(str);
    if (n == 11)
        data->pickup_s.pos_y = my_getnbr(str);
    if (n == 12)
        data->pickup_s.sens = my_getnbr(str);
    if (n == 13)
        data->harvest_s->pos_x = my_getnbr(str);
    if (n == 14)
        data->harvest_s->pos_y = my_getnbr(str);
    if (n == 15)
        data->harvest_s->sens = my_getnbr(str);
    if (n == 16)
        data->tractor_s->pos_x = my_getnbr(str);
    if (n == 17)
        data->tractor_s->pos_y = my_getnbr(str);
    if (n == 18)
        data->tractor_s->sens = my_getnbr(str);
}

int verif_file_is_good(void)
{
    bool map_png = false;
    bool save = false;

    FILE *fptr = fopen("./save/map.png", "r");
    if (fptr != NULL) {
        map_png = true;
        fclose(fptr);
    }
    fptr = fopen("./save/save", "r");
    if (fptr != NULL) {
        save = true;
        fclose(fptr);
    }

    if (map_png && save)
        return 0;
    else
        return -1;
}

int load_map(main_s *data)
{
    data->ress_s.img_map_01 = sfImage_createFromFile("./save/map.png");
    if (!data->ress_s.img_map_01)
        return -1;
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    if (!data->ress_s.textu_map_01)
        return -1;
    data->ress_s.map_01 = sfSprite_create();
    if (!data->ress_s.map_01)
        return -1;
    sfSprite_setTexture(data->ress_s.map_01, data->ress_s.textu_map_01, sfTrue);
    sfFloatRect size_map = sfSprite_getLocalBounds(data->ress_s.map_01);
    if (size_map.width != 1920 && size_map.height != 1080)
        return -1;
    return 0;
}

int load_info(main_s *data)
{
    int adresse = open("./save/save", O_RDONLY);
    if (adresse == -1) {
        close(adresse);
        return -1;
    }
    close(adresse);
    char *file = malloc(sizeof(char) * 100);
    int fd = open("./save/save", O_RDONLY);
    if (fd == -1)
        return -1;
    int size_file = read(fd, file, 99);
    if (size_file == -1)
        return -1;
    if (size_file == 0 || size_file == 1)
        return -1;
    file[size_file] = '\0';
    close(fd);
    if (load_info_in_struct(data, file) == -1)
        return -1;
    finish_load(data); return 0;
}

void finish_load(main_s *data)
{
    sfSprite_setPosition(data->tractor_s->tractor,
        (sfVector2f) {data->tractor_s->pos_x, data->tractor_s->pos_y});
    sfSprite_setPosition(data->pickup_s.pickup,
        (sfVector2f) {data->pickup_s.pos_x, data->pickup_s.pos_y});
    sfSprite_setPosition(data->harvest_s->harvest,
        (sfVector2f) {data->harvest_s->pos_x, data->harvest_s->pos_y});
    turn_sprite(data);
    turn_sprite_tractor(data);
    turn_sprite_harvest(data);
    data->ress_s.load = 0;
}
