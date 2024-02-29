/*
** EPITECH PROJECT, 2023
** animed_sprite_player.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"


void turn_01(main_s *game_s)
{
    if (game_s->pickup_s.sens == 7) {
        sfIntRect textureRect = {154, 120, 160, 172};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){80, 86});
    }
    if (game_s->pickup_s.sens == 0) {
        sfIntRect textureRect = {344, 40, 96, 178};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){48, 89});
    }
    if (game_s->pickup_s.sens == 1) {
        sfIntRect textureRect = {486, 120, 160, 172};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){80, 86});
    }
}

void turn_02(main_s *game_s)
{
    if (game_s->pickup_s.sens == 2) {
        sfIntRect textureRect = {565, 329, 185, 103};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){92, 51});
    }
    if (game_s->pickup_s.sens == 3) {
        sfIntRect textureRect = {485, 480, 161, 172};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){80, 86});
    }
    if (game_s->pickup_s.sens == 4) {
        sfIntRect textureRect = {352, 571, 106, 184};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){53, 92});
    }
}

void turn_03(main_s *game_s)
{
    if (game_s->pickup_s.sens == 5) {
        sfIntRect textureRect = {154, 480, 161, 172};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){80, 86});
    }
    if (game_s->pickup_s.sens == 6) {
        sfIntRect textureRect = {51, 330, 185, 99};
        sfSprite_setTextureRect(game_s->pickup_s.pickup, textureRect);
        sfSprite_setOrigin(game_s->pickup_s.pickup, (sfVector2f){92, 50});
    }
}

void suite_move_forward_pickup(main_s *game_s, float speed)
{
    if (game_s->pickup_s.sens == 7)
        mooving_pickup(game_s, (int)(speed * - 1), (int)(speed * -1));
    if (game_s->pickup_s.sens == 6)
        mooving_pickup(game_s, (int)(speed * -1), 0);
    if (game_s->pickup_s.sens == 5)
        mooving_pickup(game_s, (int)(speed * - 1), (int)(speed));
    if (game_s->pickup_s.sens == 4)
        mooving_pickup(game_s, 0, (int)speed);
    if (game_s->pickup_s.sens == 3)
        mooving_pickup(game_s, (int)speed, (int)speed);
    if (game_s->pickup_s.sens == 2)
        mooving_pickup(game_s, (int)speed, 0);
    if (game_s->pickup_s.sens == 1)
        mooving_pickup(game_s, (int)speed, (int)(speed * -1));
    if (game_s->pickup_s.sens == 0)
        mooving_pickup(game_s, 0, (int)(speed * -1));
}

void suite_brake_forward_pickup(main_s *game_s, float speed)
{
    if (game_s->pickup_s.sens == 7)
        mooving_pickup(game_s, (int)(speed * -1), (int)(speed * -1));
    if (game_s->pickup_s.sens == 6)
        mooving_pickup(game_s, (int)(speed * -1), 0);
    if (game_s->pickup_s.sens == 5)
        mooving_pickup(game_s, (int)(speed * -1), (int)(speed));
    if (game_s->pickup_s.sens == 4)
        mooving_pickup(game_s, 0, (int)speed);
    if (game_s->pickup_s.sens == 3)
        mooving_pickup(game_s, (int)speed, (int)speed);
    if (game_s->pickup_s.sens == 2)
        mooving_pickup(game_s, (int)speed, 0);
    if (game_s->pickup_s.sens == 1)
        mooving_pickup(game_s, (int)speed, (int)(speed * -1));
    if (game_s->pickup_s.sens == 0)
        mooving_pickup(game_s, 0, (int)(speed * -1));
}
