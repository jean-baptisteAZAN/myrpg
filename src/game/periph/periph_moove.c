/*
** EPITECH PROJECT, 2023
** periph_moove
** File description:
** function : periph_moove.c
*/

#include "my.h"
#include "my_rpg.h"

void mooving_view(main_s *game_s, int y, int x)
{
    int map_zone[4] = {320, 1580, 83, 960};
    if (verif_zone_point(map_zone, (x + game_s->ress_s.x_view),
        (y + game_s->ress_s.y_view)) == 0)
        return;
    game_s->ress_s.x_view += x;
    game_s->ress_s.y_view += y;
    sfClock_restart(game_s->ress_s.time);
}

int verif_clock_moove(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->ress_s.time).microseconds > 7000)
        return 1;
    return 0;
}

int periph_moove(main_s *game_s, sfEvent act)
{
    if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape)
        game_s->where = -1;
    int speed_moove = 1;
    if (game_s->where_vehicule != -1)
        return 0;
    if (verif_clock_moove(game_s) == 0)
        return 0;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        mooving_view(game_s, speed_moove * -1, 0);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        mooving_view(game_s, speed_moove, 0);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        mooving_view(game_s, 0, speed_moove * -1);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        mooving_view(game_s, 0, speed_moove);
    sfView_setCenter(game_s->ress_s.view_p,
        (sfVector2f){(int)game_s->ress_s.x_view, (int)game_s->ress_s.y_view});
    return 1;
}
