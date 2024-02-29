/*
** EPITECH PROJECT, 2023
** init_menu_home
** File description:
** function : init_menu_home.c
*/

#include "../../../include/my.h"
#include "../../../include/my_rpg.h"

void reset_speed_all_vehicule(main_s *data)
{
    data->pickup_s.speed = 0;
    data->tractor_s->speed = 0;
    data->harvest_s->speed = 0;
}

void periph_basic(main_s *game_s)
{
    if (sfKeyboard_isKeyPressed(sfKeyTab) &&
        sfClock_getElapsedTime(game_s->ress_s.could_downn_tab).microseconds
        > 400000) {
        game_s->where_vehicule++;
        if (game_s->where_vehicule == 4)
            game_s->where_vehicule = 1;
        reset_speed_all_vehicule(game_s);
        sfClock_restart(game_s->ress_s.could_downn_tab);
    }
    if ((sfClock_getElapsedTime(game_s->ress_s.clock_open_map).microseconds
        > 400000 && sfKeyboard_isKeyPressed(sfKeyM))) {
        sfClock_restart(game_s->ress_s.clock_open_map);
        if (game_s->ress_s.open_map == 1)
            game_s->ress_s.open_map = 0;
        else
            game_s->ress_s.open_map = 1;
    }
}

void periph_home(main_s *game_s, sfEvent act)
{
    muration(game_s);
    periph_basic(game_s);
    if (game_s->ress_s.open_map == 1)
        return;
    if (game_s->where_vehicule == -1) {
        if (periph_moove(game_s, act) == 1)
            return;
    }
    if (game_s->where_vehicule >= 1 && game_s->where_vehicule <= 3) {
        if (periph_vehicule(game_s) == 1)
            return;
    }
    if (game_s->where_vehicule == 0) {
        home_periph_player(game_s);
    }
}
