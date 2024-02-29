/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/
#include "my_rpg.h"
#include "my.h"

void init_ennemy(main_s *data)
{
    data->opps->opp = my_sprite((sprite_create) {
        .color = sfWhite,
        .texture = sfTexture_createFromFile("ressources/farmer.png", NULL),
        .position = (sfVector2f) {323, 345},
        .scale = (sfVector2f) {0.015, 0.015},
    });
}
