/*
** EPITECH PROJECT, 2023
** create_field.c
** File description:
** function : create_field
*/

#include "../../../include/my.h"
#include "../../../include/my_rpg.h"

void create_field(main_s *data, int *size_fied)
{
    int x = size_fied[0];
    int y = size_fied[2];
    for (; x <= size_fied[1]; x++) {
        y = size_fied[2];
        for (; y <= size_fied[3]; y++) {
            sfImage_setPixel(data->ress_s.img_map_01, x, y,
                data->ress_s.dirt);
        }
    }
}

void home_create_field(main_s *data)
{
    for (int i = 0; i < data->ress_s.nb_fields; i++)
        create_field(data, data->ress_s.size_fied[i]);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}
