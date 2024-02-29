/*
** EPITECH PROJECT, 2023
** move_back_pickup
** File description:
** function : move_back_pickup.c
*/

#include "my.h"
#include "my_rpg.h"

void turn_sprite_tractor(main_s *game_s)
{
    if ((game_s->tractor_s->sens >= 0 && game_s->tractor_s->sens <= 2) ||
        game_s->tractor_s->sens == 7)
        turn_01_tractor(game_s);
    if (game_s->tractor_s->sens >= 2 && game_s->tractor_s->sens <= 4)
        turn_02_tractor(game_s);
    if (game_s->tractor_s->sens >= 5 && game_s->tractor_s->sens <= 6)
        turn_03_tractor(game_s);
}

void turn_tractor_right(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->tractor_s->t_rotate).microseconds <
        400000)
        return;
    if (game_s->tractor_s->sens == 6) {
        game_s->tractor_s->sens = 0;
        turn_sprite_tractor(game_s);
    } else {
        game_s->tractor_s->sens += 2;
        turn_sprite_tractor(game_s);
    }
    sfClock_restart(game_s->tractor_s->t_rotate);
}

void turn_tractor_left(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->tractor_s->t_rotate).microseconds <
        400000)
        return;
    if (game_s->tractor_s->sens == 0) {
        game_s->tractor_s->sens = 6;
        turn_sprite_tractor(game_s);
    } else {
        game_s->tractor_s->sens -= 2;
        turn_sprite_tractor(game_s);
    }
    sfClock_restart(game_s->tractor_s->t_rotate);
}
