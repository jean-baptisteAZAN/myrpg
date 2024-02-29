/*
** EPITECH PROJECT, 2023
** move_back_pickup
** File description:
** function : move_back_pickup.c
*/

#include "my.h"
#include "my_rpg.h"

void turn_sprite(main_s *game_s)
{
    if ((game_s->pickup_s.sens >= 0 && game_s->pickup_s.sens <= 2) ||
        game_s->pickup_s.sens == 7)
        turn_01(game_s);
    if (game_s->pickup_s.sens >= 2 && game_s->pickup_s.sens <= 4)
        turn_02(game_s);
    if (game_s->pickup_s.sens >= 5 && game_s->pickup_s.sens <= 6)
        turn_03(game_s);
    return;
}

void turn_pickup_right(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->pickup_s.t_rotate).microseconds < 400000)
        return;
    if (game_s->pickup_s.sens == 7) {
        game_s->pickup_s.sens = 0;
        turn_sprite(game_s);
    } else {
        game_s->pickup_s.sens++;
        turn_sprite(game_s);
    }
    sfClock_restart(game_s->pickup_s.t_rotate);
}

void turn_pickup_left(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->pickup_s.t_rotate).microseconds < 400000)
        return;
    if (game_s->pickup_s.sens == 0) {
        game_s->pickup_s.sens = 7;
        turn_sprite(game_s);
    } else {
        game_s->pickup_s.sens--;
        turn_sprite(game_s);
    }
    sfClock_restart(game_s->pickup_s.t_rotate);
    return;
}
