/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** display_tuto
*/

#include "my.h"
#include "my_rpg.h"

void display_all_tuto(main_s *data)
{
    update_all_tuto(data);
    if (data->tuto->new && data->inv_s.verif == false &&
    data->ress_s.open_map != 1)
        sfRenderWindow_drawSprite(data->window->game_window,
        data->tuto->panneau, NULL);
}
