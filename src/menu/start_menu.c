/*
** EPITECH PROJECT, 2023
** stat
** File description:
** sfv
*/

#include "my.h"
#include "my_rpg.h"

void sub_visu_player(main_s *data)
{
    data->menu->perso->visu_sprite = my_sprite((sprite_create) {
        .texture = sfTexture_createFromFile("ressources/skin1.png", NULL),
        .position = (sfVector2f) {1400, 150},
        .scale = (sfVector2f) {0.7, 0.7},
        .color = sfWhite,
        .rotate = 0,
    });
    data->menu->perso->before_start =
    sfImage_createFromFile("ressources/perso_menu.png");
    data->menu->perso->before_txt =
    sfTexture_createFromImage(data->menu->perso->before_start, NULL);
    data->menu->perso->before_sprite = sfSprite_create();
    sfSprite_setTexture(data->menu->perso->before_sprite,
    data->menu->perso->before_txt, sfFalse);
}

void sub_init(main_s *data)
{
    data->menu->perso->button_back = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {100, 1000},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0, .scale = (sfVector2f) {1, 1},
    });
    data->menu->perso->txt_back = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {70, 920},
        .size = 60,
        .text = "Retour",
    });
    sub_visu_player(data);
}

void init_text_zone(main_s *data)
{
    data->menu->perso->name = NULL;
    data->menu->perso->text_zone = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {150, 200},
        .size = 80,
        .text = "quenting",
    });
    data->menu->perso->zone_name = my_rectangle((button_create) {
        .color = sfColor_fromRGBA(0, 0, 0, 128),
        .position = (sfVector2f) {100, 200},
        .size = (sfVector2f) {700, 100},
    });
    sub_init(data);
}

void init_start_menu(main_s *data)
{
    init_text_zone(data);
    data->menu->perso->button_start = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1350, 800},
        .origine = (sfVector2f) {0, 0},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu->perso->txt_strt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1430, 825},
        .size = 50,
        .text = "Jouer",
    });
}
