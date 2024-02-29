/*
** EPITECH PROJECT, 2023
** init
** File description:
** menu
*/

#include "my.h"
#include "my_rpg.h"

void init_txt_ig(main_s *data)
{
    data->menu_ig->txt_sav = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {340, 255},
        .size = 70,
        .text = "Save",
    });
    data->menu_ig->txt_load = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {780, 270},
        .size = 55,
        .text = "Load Game",
    });
}

void sub_init_ig(main_s *data)
{
    data->menu_ig->button_settings = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1350, 350},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu_ig->exit_but = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1600, 100},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    init_txt_ig(data);
}

void init_button_ig_menu(main_s *data)
{
    data->menu_ig->button_sav = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {350, 350},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu_ig->button_load = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {850, 350},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    sub_init_ig(data);
}

void init_ig_menu(main_s *data)
{
    data->menu_ig->menu_ig_img =
    sfImage_createFromFile("ressources/ig_menu.png");
    data->menu_ig->menu_ig_txt =
    sfTexture_createFromImage(data->menu_ig->menu_ig_img, NULL);
    data->menu_ig->ig_menu_spr = sfSprite_create();
    sfSprite_setTexture(data->menu_ig->ig_menu_spr,
    data->menu_ig->menu_ig_txt, sfFalse);
    init_button_ig_menu(data);
    init_spec(data);
}
