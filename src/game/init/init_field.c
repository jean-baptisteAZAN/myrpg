/*
** EPITECH PROJECT, 2023
** init_field.c
** File description:
** function : init_field
*/

#include "../../../include/my.h"
#include "../../../include/my_rpg.h"

// For ress_s.size_fied:  x-min | y-min | x-max | y-max

void suite_init_field_size(main_s *data)
{
    data->ress_s.size_fied[2][0] = 1100;
    data->ress_s.size_fied[2][1] = 1570;
    data->ress_s.size_fied[2][2] = 115;
    data->ress_s.size_fied[2][3] = 355;

    data->ress_s.size_fied[3][0] = 1150;
    data->ress_s.size_fied[3][1] = 1560;
    data->ress_s.size_fied[3][2] = 475;
    data->ress_s.size_fied[3][3] = 865;

    data->ress_s.size_fied[4][0] = 860;
    data->ress_s.size_fied[4][1] = 1025;
    data->ress_s.size_fied[4][2] = 460;
    data->ress_s.size_fied[4][3] = 625;
}

void init_field_size(main_s *data)
{
    data->ress_s.size_fied =
        malloc(sizeof(int *) * (data->ress_s.nb_fields + 2));
    for (int n = 0; n < data->ress_s.nb_fields; n++)
        data->ress_s.size_fied[n] = malloc(sizeof(int) * 5);
    data->ress_s.size_fied[0][0] = 380;
    data->ress_s.size_fied[0][1] = 688;
    data->ress_s.size_fied[0][2] = 690;
    data->ress_s.size_fied[0][3] = 870;

    data->ress_s.size_fied[1][0] = 700;
    data->ress_s.size_fied[1][1] = 1000;
    data->ress_s.size_fied[1][2] = 690;
    data->ress_s.size_fied[1][3] = 870;
    suite_init_field_size(data);
}

void init_field_noise(main_s *data)
{
    int i = 0;
    data->ress_s.noise =
        malloc(sizeof(sfSprite *) * (data->ress_s.nb_fields + 2));
    for (; i < data->ress_s.nb_fields; i++) {
        data->ress_s.noise[i] =
            init_fond("./ressources/res/game/noise_texture.png");
        sfSprite_setPosition(data->ress_s.noise[i],
            (sfVector2f){data->ress_s.size_fied[i][0],
                data->ress_s.size_fied[i][2]});
        float scale_x =
            (float)(data->ress_s.size_fied[i][1] -
                data->ress_s.size_fied[i][0]) / 500;
        float scale_y =
            (float)(data->ress_s.size_fied[i][3] -
                data->ress_s.size_fied[i][2]) / 500;
        sfSprite_setScale(data->ress_s.noise[i],
            (sfVector2f){scale_x, scale_y});
    }
    data->ress_s.noise[i] = NULL;
}

void init_max_field(main_s *data)
{
    data->inv_s.time_recolted_max = sfClock_create();
    data->inv_s.recolted_max = sfText_create();
    sfFont *font = data->police;
    sfText_setString(data->inv_s.recolted_max,
        "Max !");
    sfText_setPosition(data->inv_s.recolted_max,
        (sfVector2f){3, 55});
    sfText_setFont(data->inv_s.recolted_max, font);
    sfText_setCharacterSize(data->inv_s.recolted_max, 20);
    sfText_setScale(data->inv_s.recolted_max, (sfVector2f){0.25, 0.25});
    sfText_setColor(data->inv_s.recolted_max, sfRed);
    data->inv_s.recolted_is_max = 0;
    data->inv_s.time_recolted_max = sfClock_create();
}

void home_init_field(main_s *data)
{
    data->ress_s.nb_fields = 5;
    data->ress_s.dirt = sfColor_fromRGB(139, 69, 19);
    data->ress_s.plowed = sfColor_fromRGB(97, 84, 2);
    data->ress_s.plowed_p = sfColor_fromRGB(59, 94, 6);
    data->ress_s.harvest = sfColor_fromRGB(208, 167, 2);
    data->ress_s.harvest_f = sfColor_fromRGB(121, 85, 72);
    init_field_size(data);
    init_field_noise(data);
    home_create_field(data);
}
