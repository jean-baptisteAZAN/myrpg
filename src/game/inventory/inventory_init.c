/*
** EPITECH PROJECT, 2023
** init
** File description:
** inv
*/

#include "my.h"
#include "my_rpg.h"

void take_gun(main_s *data)
{
    data->inv_s.gun->find = true;
}

void init_info_coin(main_s *data)
{
    data->inv_s.coin_cpy = my_sprite((sprite_create) {
        .color = sfWhite,
        .position = (sfVector2f) {1150, 270},
        .texture =
        sfTexture_createFromFile("./ressources/hunter/coin.png", NULL),
        .origine = (sfVector2f) {10, 10},
        .scale = (sfVector2f) {0.4, 0.4},
    });
    init_desc_coin(data);
}

void init_gun_coin(main_s *data)
{
    data->inv_s.gun->gun = my_sprite((sprite_create) {
        .color = sfWhite,
        .texture =
        sfTexture_createFromFile("ressources/object_inv/gun.png", NULL),
        .scale = (sfVector2f) {0.05, 0.05},
        .position = (sfVector2f) {1200, 915},
        .origine = (sfVector2f) {288.5, 216.5},
    });
    data->inv_s.coin = my_sprite((sprite_create) {
        .color = sfWhite,
        .position = (sfVector2f) {600, 390},
        .texture =
        sfTexture_createFromFile("./ressources/hunter/coin.png", NULL),
        .origine = (sfVector2f) {10, 10},
        .scale = (sfVector2f) {0.2, 0.2},
    });
    init_info_coin(data);
}

void init_txt_inven(main_s *data)
{
    data->inv_s.txt_desc_inv = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1100, 450},
        .size = 30,
        .text = my_strcat(text_inven[0], text_inven[1]),
    });
    data->inv_s.gun->gun_cpy = my_sprite((sprite_create) {
        .color = sfWhite,
        .texture =
        sfTexture_createFromFile("ressources/object_inv/gun.png", NULL),
        .scale = (sfVector2f) {0.8, 0.8},
        .position = (sfVector2f) {1400, 290},
        .origine = (sfVector2f) {288.5, 216.5},
    });
}

void inventory_init(main_s *data)
{
    data->inv_s.txt_inv =
    sfTexture_createFromFile("ressources/inventaire.png", NULL);
    data->inv_s.sprite_txt = sfSprite_create();
    sfSprite_setTexture(data->inv_s.sprite_txt, data->inv_s.txt_inv, sfFalse);
    data->inv_s.gun->lvl = 1;
    data->inv_s.gun->find = false;
    init_gun_coin(data);
    init_txt_inven(data);
    init_lvl_inven(data);
    data->inv_s.button_boost = my_sprite((sprite_create) {
        .texture = sfTexture_createFromFile("ressources/bouton_plus.png", NULL),
        .position = (sfVector2f) {600, 900},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {3.5, 3.5},
    });
}
