/*
** EPITECH PROJECT, 2023
** voool
** File description:
** vol
*/

#include "my.h"
#include "my_rpg.h"

void sub_sub_init_settings(main_s *data)
{
    data->menu->settings->minus_button = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/bouton_moins.png", NULL),
        .position = (sfVector2f) {445, 700},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {2.5, 2.5},
    });
    data->menu->but->exit = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {100, 100},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
}

void sub_init_settings(main_s *data)
{
    sub_sub_init_settings(data);
    data->menu->settings->volume_nb = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {300, 450},
        .text = my_put_nbr(data->volume),
        .size = 80,
    });
    data->menu->settings->plus_select =
    sfTexture_createFromFile("ressources/bouton_plus_selected.png", NULL);
    data->menu->settings->min_select =
    sfTexture_createFromFile("ressources/bouton_min_selected.png", NULL);
    init_settings_frame(data);
}

void init_reso_settings(main_s *data)
{
    data->menu->settings->rect_res = my_rectangle((button_create) {
        .position = (sfVector2f) {170, 780},
        .color = sfColor_fromRGBA(255, 255, 255, 128),
        .size = {400, 100},
    });
    data->menu->settings->min_res = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/fleche_droite.png", NULL),
        .position = (sfVector2f) {580, 780},
        .origine = (sfVector2f) {0, 0},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {2.5, 2.5},
    });
    data->menu->settings->res_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {200, 800},
        .text = "Windowed", .size = 50,
    });
}

void init_settings_params(main_s *data)
{
    data->menu->settings->sound_bar = my_rectangle((button_create) {
        .color = sfColor_fromRGBA(255, 255, 255, 128),
        .position = (sfVector2f) {300, 450},
        .size = (sfVector2f) {190, 100},
    });
    data->menu->settings->plus_button = my_sprite((sprite_create) {
        .texture = sfTexture_createFromFile("ressources/bouton_plus.png", NULL),
        .position = (sfVector2f) {750, 700},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {2.5, 2.5},
    });
    sub_init_settings(data);
    init_reso_settings(data);
}
