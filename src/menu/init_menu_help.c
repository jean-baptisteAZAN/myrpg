/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include "my.h"
#include "my_rpg.h"

bool init_help_menu(main_s *data)
{
    if ((data->menu->help->back_txt =
    sfTexture_createFromFile("ressources/help/help1.png", NULL)) == false)
        return (false);
    data->menu->help->sprite_back = sfSprite_create();
    sfSprite_setTexture(data->menu->help->sprite_back,
    data->menu->help->back_txt, sfFalse);
    data->menu->help->back_button = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {0, 0},
        .color = sfColor_fromRGB(255, 255, 255),
        .scale = (sfVector2f) {1, 1},
    });
    data->menu->help->txt_back = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {60, 20},
        .size = 60,
        .text = "Retour",
    });
    return (true);
}
