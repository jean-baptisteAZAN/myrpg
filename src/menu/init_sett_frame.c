/*
** EPITECH PROJECT, 2023
** init
** File description:
** sett
*/
#include "my.h"
#include "my_rpg.h"

void resume_but(main_s *data)
{
    data->menu->settings->resume_button = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/bouton_backup.png", NULL),
        .origine = (sfVector2f) {0, 0},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .position = (sfVector2f) {0, 0},
        .scale = (sfVector2f) {2.5, 2.5},
    });
}

void sub_sub_init_frame(main_s *data)
{
    data->menu->settings->plus_select_frame =
    sfTexture_createFromFile("ressources/bouton_plus_selected.png", NULL);
    data->menu->settings->min_select_frame =
    sfTexture_createFromFile("ressources/bouton_min_selected.png", NULL);
    data->menu->settings->command_but = my_rectangle((button_create) {
        .color = sfColor_fromRGBA(255, 255, 255, 128),
        .position = (sfVector2f) {1120, 670}, .size = (sfVector2f) {550, 100},
    });
    resume_but(data);
}

void sub_init_frame(main_s *data)
{
    data->menu->settings->minus_button_frame = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/bouton_moins.png", NULL),
        .position = (sfVector2f) {1445, 700},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0, .scale = (sfVector2f) {2.5, 2.5},
    });
    data->menu->settings->nb_fps_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1300, 450},
        .size = 70, .text = my_put_nbr(data->menu->settings->nb_fps),
    });
    sub_sub_init_frame(data);
}

void init_settings_frame(main_s *data)
{
    data->menu->settings->framerate_bar = my_rectangle((button_create) {
        .color = sfColor_fromRGBA(255, 255, 255, 128),
        .position = (sfVector2f) {1300, 450},
        .size = (sfVector2f) {190, 100},
    });
    data->menu->settings->plus_button_frame = my_sprite((sprite_create) {
        .texture = sfTexture_createFromFile("ressources/bouton_plus.png", NULL),
        .position = (sfVector2f) {1750, 700},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {2.5, 2.5},
    });
    sub_init_frame(data);
}
