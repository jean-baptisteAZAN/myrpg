/*
** EPITECH PROJECT, 2023
** gebne
** File description:
** gene
*/

#include "my.h"
#include "my_rpg.h"

void sub_generate_txt(main_s *data)
{
    data->window->resolution_state = 0;
    data->menu->but->settings_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {520, 675},
        .size = 40,
        .text = "Parametres",
    });
    data->menu->but->quit = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {55, 10},
        .size = 60,
        .text = "Quitter",
    });
}

void init_txt(main_s *data)
{
    init_settings_params(data);
    init_cmd_menu(data);
    data->menu->but->play_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1130, 510},
        .size = 60,
        .text = "Jouer",
    });
    data->menu->but->resume_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1080, 670},
        .size = 50,
        .text = "Reprendre",
    });
    sub_generate_txt(data);
    init_start_menu(data);
}

void sub_generate_sprite(main_s *data)
{
    data->menu->but->settings = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {570, 750},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu->but->button_help = my_sprite ((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1150, 900},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
}

void generate_sprite_buttons(main_s *data)
{
    data->menu->but->play = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1150, 600},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .scale = (sfVector2f) {1, 1},
    });
    sub_sprite_gene(data);
    sub_generate_sprite(data);
}
