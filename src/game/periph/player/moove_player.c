/*
** EPITECH PROJECT, 2023
** moove_player.c
** File description:
** function : moove_player
*/


#include "my.h"
#include "my_rpg.h"

void moove_player_up(main_s *game_s)
{
    game_s->player_s->moove_on_off = 1;
    game_s->player_s->sens = 1;
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone, (game_s->player_s->pos_p_x),
        (game_s->player_s->pos_p_y - (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007))) == 0)
        return;
    if (collision_player(game_s, (game_s->player_s->pos_p_x),
        (game_s->player_s->pos_p_y - (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007))) == 1)
        return;
    game_s->player_s->pos_p_y -= game_s->player_s->speed *
    sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds * 0.00007;
}

void moove_player_down(main_s *game_s)
{
    game_s->player_s->moove_on_off = 1;
    game_s->player_s->sens = 3;
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone, (game_s->player_s->pos_p_x),
        (game_s->player_s->pos_p_y + (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007))) == 0)
        return;
    if (collision_player(game_s, (game_s->player_s->pos_p_x),
        (game_s->player_s->pos_p_y + (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007))) == 1)
        return;
    game_s->player_s->pos_p_y += game_s->player_s->speed *
    sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds * 0.00007;
}

void moove_player_right(main_s *game_s)
{
    game_s->player_s->moove_on_off = 1;
    game_s->player_s->sens = 2;
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone,
        (game_s->player_s->pos_p_x + (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007)), (game_s->player_s->pos_p_y)) == 0)
        return;
    if (collision_player(game_s,
        (game_s->player_s->pos_p_x + (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007)), (game_s->player_s->pos_p_y)) == 1)
        return;
    game_s->player_s->pos_p_x += game_s->player_s->speed *
    sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds * 0.00007;
}

void moove_player_left(main_s *game_s)
{
    game_s->player_s->moove_on_off = 1;
    game_s->player_s->sens = 4;
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone,
        (game_s->player_s->pos_p_x - (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007)), (game_s->player_s->pos_p_y)) == 0)
        return;
    if (collision_player(game_s,
        (game_s->player_s->pos_p_x - (game_s->player_s->speed *
            sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds *
                0.00007)), (game_s->player_s->pos_p_y)) == 1)
        return;
    game_s->player_s->pos_p_x -= game_s->player_s->speed *
    sfClock_getElapsedTime(game_s->player_s->time_moove).microseconds * 0.00007;
}
