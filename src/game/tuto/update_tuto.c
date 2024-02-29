/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** update_tuto
*/

#include "my.h"
#include "my_rpg.h"

void verif_move(main_s *data)
{
    int tab[] = {sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    int tab2[] = {data->where_vehicule == 3 && data->tuto->plant &&
    data->tuto->statement == 4,
    data->tuto->ready && data->tuto->statement == 5,
    data->where_vehicule == 2 && data->tuto->statement == 6,
    data->tuto->recolt && data->tuto->statement == 7,
    data->hun->finish == true && data->tuto->statement == 8,
    };
    for (int i = 0; i < 4; i++)
        if (data->window->event.key.code == tab[i] &&
        data->tuto->statement == i)
            data->tuto->statement++;
    for (int i = 0; i < 6; i++) {
        if (tab2[i] == 1)
            data->tuto->statement++;
    }
}

void update_all_tuto(main_s *data)
{
    if (data->tuto->new == false)
        return;
    sfVector2f pos = sfView_getCenter(data->ress_s.view_p);
    sfSprite_setPosition(data->tuto->panneau, (sfVector2f)
    {pos.x + 10, pos.y - 60});
    verif_move(data);
    if (data->tuto->statement == 10) {
        data->tuto->new = false;
        return;
    }
    sfSprite_setTexture(data->tuto->panneau,
    data->tuto->tab_text[data->tuto->statement], 0);
}
