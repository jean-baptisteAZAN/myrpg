/*
** EPITECH PROJECT, 2023
** animed_sprite_player.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void turn_01_harvest(main_s *game_s)
{
    if (game_s->harvest_s->sens == 7) {
        sfIntRect textureRect = {27, 25, 129, 128};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){40, 80});
    }
    if (game_s->harvest_s->sens == 0) {
        sfIntRect textureRect = {206, 33, 77, 119};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){38, 60});
    }
    if (game_s->harvest_s->sens == 1) {
        sfIntRect textureRect = {316, 67, 134, 115};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){67, 57});
    }
}

void turn_02_harvest(main_s *game_s)
{
    if (game_s->harvest_s->sens == 2) {
        sfIntRect textureRect = {332, 206, 116, 88};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){58, 44});
    }
    if (game_s->harvest_s->sens == 3) {
        sfIntRect textureRect = {314, 320, 121, 111};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){60, 55});
    }
    if (game_s->harvest_s->sens == 4) {
        sfIntRect textureRect = {208, 393, 77, 111};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){38, 55});
    }
}

void turn_03_harvest(main_s *game_s)
{
    if (game_s->harvest_s->sens == 5) {
        sfIntRect textureRect = {65, 352, 107, 102};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){53, 51});
    }
    if (game_s->harvest_s->sens == 6) {
        sfIntRect textureRect = {49, 206, 111, 87};
        sfSprite_setTextureRect(game_s->harvest_s->harvest, textureRect);
        sfSprite_setOrigin(game_s->harvest_s->harvest, (sfVector2f){55, 43});
    }
}

void suite_move_forward_harvest(main_s *game_s, float speed)
{
    if (game_s->harvest_s->sens == 7)
        mooving_harvest(game_s, (int)(speed * - 1), (int)(speed * -1));
    if (game_s->harvest_s->sens == 6)
        mooving_harvest(game_s, (int)(speed * -1), 0);
    if (game_s->harvest_s->sens == 5)
        mooving_harvest(game_s, (int)(speed * - 1), (int)(speed));
    if (game_s->harvest_s->sens == 4)
        mooving_harvest(game_s, 0, (int)speed);
    if (game_s->harvest_s->sens == 3)
        mooving_harvest(game_s, (int)speed, (int)speed);
    if (game_s->harvest_s->sens == 2)
        mooving_harvest(game_s, (int)speed, 0);
    if (game_s->harvest_s->sens == 1)
        mooving_harvest(game_s, (int)speed, (int)(speed * -1));
    if (game_s->harvest_s->sens == 0)
        mooving_harvest(game_s, 0, (int)(speed * -1));
}

void suite_brake_forward_harvest(main_s *game_s, float speed)
{
    if (game_s->harvest_s->sens == 7)
        mooving_harvest(game_s, (int)(speed * -1), (int)(speed * -1));
    if (game_s->harvest_s->sens == 6)
        mooving_harvest(game_s, (int)(speed * -1), 0);
    if (game_s->harvest_s->sens == 5)
        mooving_harvest(game_s, (int)(speed * -1), (int)(speed));
    if (game_s->harvest_s->sens == 4)
        mooving_harvest(game_s, 0, (int)speed);
    if (game_s->harvest_s->sens == 3)
        mooving_harvest(game_s, (int)speed, (int)speed);
    if (game_s->harvest_s->sens == 2)
        mooving_harvest(game_s, (int)speed, 0);
    if (game_s->harvest_s->sens == 1)
        mooving_harvest(game_s, (int)speed, (int)(speed * -1));
    if (game_s->harvest_s->sens == 0)
        mooving_harvest(game_s, 0, (int)(speed * -1));
}
