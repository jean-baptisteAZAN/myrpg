/*
** EPITECH PROJECT, 2023
** movement_player.c
** File description:
** function : movement_player
*/

#include "my.h"
#include "my_rpg.h"

void movement_player(main_s *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        moove_player_up(data);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        moove_player_down(data);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        moove_player_left(data);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        moove_player_right(data);
    sfClock_restart(data->player_s->time_moove);
}
