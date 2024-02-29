/*
** EPITECH PROJECT, 2023
** free
** File description:
** free
*/

#include "my.h"
#include "my_rpg.h"

void free_ress(main_s *data)
{
    sfClock_destroy(data->ress_s.saison);
    sfText_destroy(data->ress_s.text_block);
    sfClock_destroy(data->ress_s.time_text_block);
    sfSprite_destroy(data->ress_s.compter);
    sfRectangleShape_destroy(data->ress_s.rect_compter);
    sfClock_destroy(data->ress_s.could_down_save);
    sfClock_destroy(data->ress_s.could_downn_tab);
    sfMusic_destroy(data->music);
}

void free_pickup(main_s *data)
{
    sfSprite_destroy(data->pickup_s.pickup);
    sfClock_destroy(data->pickup_s.t_rotate);
    sfClock_destroy(data->pickup_s.t_speed);
    sfSprite_destroy(data->player_s->player);
    sfClock_destroy(data->player_s->time_sprite);
    sfClock_destroy(data->player_s->time_moove);
    sfImage_destroy(data->collis_s->map_collis);
    sfSprite_destroy(data->collis_s->sprite_map_collis);
    sfSprite_destroy(data->ress_s.map_01);
    sfSprite_destroy(data->ress_s.map_02);
    for (int i = 0; data->ress_s.noise[i]; i++)
        sfSprite_destroy(data->ress_s.noise[i]);
    sfView_destroy(data->ress_s.view_map);
    sfClock_destroy(data->ress_s.time);
    sfClock_destroy(data->ress_s.colddown_enter_vehicule);
    sfClock_destroy(data->ress_s.clock_open_map);
    free_ress(data);
    free(data->collis_s);
    free(data->player_s);
}

void free_harvest(main_s *data)
{
    sfSprite_destroy(data->harvest_s->harvest);
    sfClock_destroy(data->harvest_s->t_rotate);
    sfClock_destroy(data->harvest_s->t_speed);
    free(data->harvest_s);
    sfSprite_destroy(data->tractor_s->tractor);
    sfClock_destroy(data->tractor_s->t_rotate);
    sfClock_destroy(data->tractor_s->t_speed);
    free(data->tractor_s);
    free_pickup(data);
}
