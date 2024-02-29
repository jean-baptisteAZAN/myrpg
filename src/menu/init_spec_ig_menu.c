/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include "my.h"
#include "my_rpg.h"

void init_ig_txt(main_s *data)
{
    data->menu_ig->money_compt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {380, 730},
        .size = 40,
        .text = my_put_nbr_int(data->player_s->money),
    });
}

void init_spec(main_s *data)
{
    data->menu_ig->piece_spr = my_sprite((sprite_create) {
        .color = sfColor_fromRGB(255, 255, 255),
        .texture = sfTexture_createFromFile("ressources/piece.png", NULL),
        .position = (sfVector2f) {300, 720},
        .scale = (sfVector2f) {0.2, 0.2},
    });
    data->menu_ig->money_slot = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {350, 800},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    init_ig_txt(data);
}
