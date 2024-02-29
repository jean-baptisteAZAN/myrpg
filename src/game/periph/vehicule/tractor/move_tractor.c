/*
** EPITECH PROJECT, 2023
** move_tractor
** File description:
** function : move_forward_tractor.c
*/


#include "my.h"
#include "my_rpg.h"

void mooving_tractor(main_s *game_s, int y, int x)
{
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone, (x + game_s->tractor_s->pos_x),
        (y + game_s->tractor_s->pos_y)) == 0)
        return;
    if (collision_tractor(game_s, (y + game_s->tractor_s->pos_x),
        (x + game_s->tractor_s->pos_y)) == 1) {
        game_s->tractor_s->speed = 0;
        return;
    }
    if (sfClock_getElapsedTime(game_s->harvest_s->t_speed).microseconds
        >= 10000) {
        game_s->tractor_s->pos_y += x;
        game_s->tractor_s->pos_x += y;
        sfClock_restart(game_s->tractor_s->t_speed);
    }
}

void change_speed_tractor(main_s *game_s, float speed_m)
{
    if (speed_m > 0 && game_s->tractor_s->speed >= 0)
        game_s->tractor_s->speed += speed_m;
    if (speed_m < 0 && game_s->tractor_s->speed > 0)
        game_s->tractor_s->speed -= 0.5;

    if (speed_m < 0 && game_s->tractor_s->speed <= 0)
        game_s->tractor_s->speed += speed_m;
    if (speed_m > 0 && game_s->tractor_s->speed < 0)
        game_s->tractor_s->speed += 0.5;
}

void move_forward_tractor(main_s *game_s, float speed_m, int sens)
{
    if (sfClock_getElapsedTime(game_s->tractor_s->t_speed).microseconds < 10000)
        return;
    int no_pass = 0;
    if ((game_s->tractor_s->speed + speed_m) > game_s->tractor_s->speed_limit
        && sens == 1)
        no_pass = 1;
    if ((game_s->tractor_s->speed + speed_m) <
        (game_s->tractor_s->speed_limit * -1) && sens == -1)
        no_pass = 1;
    if (no_pass == 0)
        change_speed_tractor(game_s, speed_m);
    suite_move_forward_tractor(game_s, game_s->tractor_s->speed);
}

void brake_forward_tractor(main_s *game_s,float speed_m)
{
    if (sfClock_getElapsedTime(game_s->tractor_s->t_speed).microseconds < 10000)
        return;
    if (game_s->tractor_s->speed < 0.2 && game_s->tractor_s->speed > -0.2) {
        game_s->tractor_s->speed = 0;
        return;
    }
    if (game_s->tractor_s->speed > 0)
        game_s->tractor_s->speed -= speed_m;
    if (game_s->tractor_s->speed < 0)
        game_s->tractor_s->speed += speed_m;
    suite_brake_forward_tractor(game_s, game_s->tractor_s->speed);
}
