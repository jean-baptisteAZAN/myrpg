/*
** EPITECH PROJECT, 2023
** dis
** File description:
** dis
*/

#include "my.h"
#include "my_rpg.h"

void disp_opps(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window, data->opps->opp, NULL);
}
