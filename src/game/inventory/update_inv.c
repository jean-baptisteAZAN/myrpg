/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** update_inv
*/

#include "my.h"
#include "my_rpg.h"

void update_inv(main_s *data)
{
    sfText_setString(data->inv_s.nb_coin_inv
    ,my_put_nbr((float) data->player_s->money));
    sfText_setString(data->menu_ig->money_compt,
    my_put_nbr((float) data->player_s->money));
}
