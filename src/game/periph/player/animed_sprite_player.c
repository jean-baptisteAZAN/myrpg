/*
** EPITECH PROJECT, 2023
** animed_sprite.c
** File description:
** function : animed_sprite
*/


#include "my.h"
#include "my_rpg.h"

void anime_sprite_player_up(main_s *game_s)
{
    if (game_s->player_s->frame_player == 1) {
        sfIntRect textureRect = {0, 315, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 2) {
        sfIntRect textureRect = {105, 315, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 3) {
        sfIntRect textureRect = {225, 315, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
}

void anime_sprite_player_down(main_s *game_s)
{
    if (game_s->player_s->frame_player == 1) {
        sfIntRect textureRect = {0, 0, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 2) {
        sfIntRect textureRect = {110, 0, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 3) {
        sfIntRect textureRect = {220, 0, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
}

void anime_sprite_player_right(main_s *game_s)
{
    if (game_s->player_s->frame_player == 1) {
        sfIntRect textureRect = {0, 469, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 2) {
        sfIntRect textureRect = {94, 469, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 3) {
        sfIntRect textureRect = {216, 469, 60, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
}

void anime_sprite_player_left(main_s *game_s)
{
    if (game_s->player_s->frame_player == 1) {
        sfIntRect textureRect = {0, 160, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 2) {
        sfIntRect textureRect = {103, 160, 55, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
    if (game_s->player_s->frame_player == 3) {
        sfIntRect textureRect = {218, 160, 60, 120};
        sfSprite_setTextureRect(game_s->player_s->player, textureRect);
        sfSprite_setOrigin(game_s->player_s->player, (sfVector2f){30, 60});
    }
}
