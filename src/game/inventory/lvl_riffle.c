/*
** EPITECH PROJECT, 2023
** lvl
** File description:
** lv
*/

#include "my.h"
#include "my_rpg.h"

void init_txt_ble(main_s *data)
{
    data->inv_s.prin_ble = false;
    data->inv_s.sprite_ble = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/res/game/icon_wheat.png", NULL),
        .color = sfWhite,
        .position = (sfVector2f) {935, 380},
        .scale = (sfVector2f) {2.5, 2.5},
    });
    data->inv_s.cpy_ble = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile("ressources/res/game/icon_wheat.png", NULL),
        .color = sfWhite,
        .position = (sfVector2f) {1200, 250},
        .scale = (sfVector2f) {3.5, 3.5},
    });
    data->inv_s.nb_ble = my_text((text_create) {
        .font = data->police, .color = sfWhite,
        .position = (sfVector2f) {1320, 320},
        .size = 50, .text = my_put_nbr_int(data->inv_s.nb_recolted),
    });
}

void sub_init_lvl_inven(main_s *data)
{
    data->inv_s.text_ble = my_text((text_create) {
        .color = sfWhite,
        .position = (sfVector2f) {1100, 400},
        .size = 30,
        .font = data->police,
        .text = "Le ble que vous recoltez vous \npermet de gagner de l'argent\n\
en le vendant au chasseur !",
    });
    init_txt_ble(data);
}

void init_lvl_inven(main_s *data)
{
    data->inv_s.rect_lvl_riffle = my_rectangle((button_create) {
        .position = (sfVector2f) {1150, 700},
        .size = (sfVector2f) {450, 70},
        .color = sfBlack,
    });
    data->inv_s.nb_lvl_riffle = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1180, 710},
        .size = 40,
        .text = my_strcat("Niveau du fusil : ",
        my_put_nbr_int(data->player_s->gun_xp)),
    });
    sub_init_lvl_inven(data);
}
