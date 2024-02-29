/*
** EPITECH PROJECT, 2023
** animed_sprite_player.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void turn_01_tractor(main_s *game_s)
{
    if (game_s->tractor_s->sens == 7) {
        sfIntRect textureRect = {74, 62, 120, 121};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){40, 80});
    }
    if (game_s->tractor_s->sens == 0) {
        sfIntRect textureRect = {206, 17, 77, 119};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){38, 60});
    }
    if (game_s->tractor_s->sens == 1) {
        sfIntRect textureRect = {299, 63, 123, 120};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){60, 60});
    }
}

void turn_02_tractor(main_s *game_s)
{
    if (game_s->tractor_s->sens == 2) {
        sfIntRect textureRect = {345, 206, 117, 96};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){58, 44});
    }
    if (game_s->tractor_s->sens == 3) {
        sfIntRect textureRect = {299, 299, 110, 122};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){55, 61});
    }
    if (game_s->tractor_s->sens == 4) {
        sfIntRect textureRect = {206, 370, 77, 113};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){38, 56});
    }
}

void turn_03_tractor(main_s *game_s)
{
    if (game_s->tractor_s->sens == 5) {
        sfIntRect textureRect = {82, 299, 111, 123};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){40, 80});
    }
    if (game_s->tractor_s->sens == 6) {
        sfIntRect textureRect = {35, 206, 113, 85};
        sfSprite_setTextureRect(game_s->tractor_s->tractor, textureRect);
        sfSprite_setOrigin(game_s->tractor_s->tractor, (sfVector2f){56, 42});
    }
}

void suite_move_forward_tractor(main_s *game_s, float speed)
{
    if (game_s->tractor_s->sens == 7)
        mooving_tractor(game_s, (int)(speed * - 1), (int)(speed * -1));
    if (game_s->tractor_s->sens == 6)
        mooving_tractor(game_s, (int)(speed * -1), 0);
    if (game_s->tractor_s->sens == 5)
        mooving_tractor(game_s, (int)(speed * - 1), (int)(speed));
    if (game_s->tractor_s->sens == 4)
        mooving_tractor(game_s, 0, (int)speed);
    if (game_s->tractor_s->sens == 3)
        mooving_tractor(game_s, (int)speed, (int)speed);
    if (game_s->tractor_s->sens == 2)
        mooving_tractor(game_s, (int)speed, 0);
    if (game_s->tractor_s->sens == 1)
        mooving_tractor(game_s, (int)speed, (int)(speed * -1));
    if (game_s->tractor_s->sens == 0)
        mooving_tractor(game_s, 0, (int)(speed * -1));
}

void suite_brake_forward_tractor(main_s *game_s, float speed)
{
    if (game_s->tractor_s->sens == 7)
        mooving_tractor(game_s, (int)(speed * -1), (int)(speed * -1));
    if (game_s->tractor_s->sens == 6)
        mooving_tractor(game_s, (int)(speed * -1), 0);
    if (game_s->tractor_s->sens == 5)
        mooving_tractor(game_s, (int)(speed * -1), (int)(speed));
    if (game_s->tractor_s->sens == 4)
        mooving_tractor(game_s, 0, (int)speed);
    if (game_s->tractor_s->sens == 3)
        mooving_tractor(game_s, (int)speed, (int)speed);
    if (game_s->tractor_s->sens == 2)
        mooving_tractor(game_s, (int)speed, 0);
    if (game_s->tractor_s->sens == 1)
        mooving_tractor(game_s, (int)speed, (int)(speed * -1));
    if (game_s->tractor_s->sens == 0)
        mooving_tractor(game_s, 0, (int)(speed * -1));
}
