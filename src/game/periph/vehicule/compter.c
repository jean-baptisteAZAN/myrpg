/*
** EPITECH PROJECT, 2023
** compter.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"


void init_compter(main_s *data)
{
    data->ress_s.rect_compter = sfRectangleShape_create();
    sfRectangleShape_setPosition(data->ress_s.rect_compter,
        (sfVector2f){125, 480});
    sfRectangleShape_setFillColor(data->ress_s.rect_compter, sfWhite);
    sfRectangleShape_setSize(data->ress_s.rect_compter,
        (sfVector2f){18, 1});
    sfRectangleShape_setOrigin(data->ress_s.rect_compter,
        (sfVector2f){0.5, 0.5});
    sfRectangleShape_setOutlineThickness(data->ress_s.rect_compter, 0.5);
    sfRectangleShape_setOutlineColor(data->ress_s.rect_compter, sfBlack);

    data->ress_s.compter =
        init_fond("./ressources/res/game/compter.png");
    sfSprite_setScale(data->ress_s.compter, (sfVector2f){0.15, 0.15});
}

float get_speed_vehicule(main_s *data)
{
    if (data->where_vehicule == 1) {
        if (data->pickup_s.speed > 0)
            return data->pickup_s.speed;
        else
            return (data->pickup_s.speed * -1);
    }
    if (data->where_vehicule == 2) {
        if (data->tractor_s->speed > 0)
            return data->tractor_s->speed;
        else
            return (data->tractor_s->speed * -1);
    }
    if (data->where_vehicule == 3) {
        if (data->harvest_s->speed > 0)
            return data->harvest_s->speed;
        else
            return (data->harvest_s->speed * -1);
    }
    return 0;
}

float get_speed_limit_vehicule(main_s *data)
{
    if (data->where_vehicule == 1) {
        if (data->pickup_s.speed_limit > 0)
            return data->pickup_s.speed_limit;
        else
            return (data->pickup_s.speed_limit * -1);
    }
    if (data->where_vehicule == 2) {
        if (data->tractor_s->speed_limit > 0)
            return data->tractor_s->speed_limit;
        else
            return (data->tractor_s->speed_limit * -1);
    }
    if (data->where_vehicule == 3) {
        if (data->harvest_s->speed_limit > 0)
            return data->harvest_s->speed_limit;
        else
            return (data->harvest_s->speed_limit * -1);
    }
    return 1;
}

void change_roration_compter(main_s *data)
{
    sfVector2f pos = sfView_getCenter(data->ress_s.view_p);
    sfRectangleShape_setPosition(data->ress_s.rect_compter,
        (sfVector2f){pos.x + 120, pos.y + 65});

    float speed_prc = get_speed_vehicule(data) / get_speed_limit_vehicule(data);
    sfRectangleShape_setRotation(data->ress_s.rect_compter,
        (-220 + (250 * speed_prc)));

    sfSprite_setPosition(data->ress_s.compter,
        (sfVector2f){pos.x + 102, pos.y + 43});
}

void display_compter(main_s *data)
{
    if (data->ress_s.open_map == 1
        || data->where_vehicule == 0 || data->where_vehicule == -1)
        return;
    change_roration_compter(data);

    sfRenderWindow_drawSprite(data->window->game_window,
        data->ress_s.compter, NULL);

    sfRenderWindow_drawRectangleShape(data->window->game_window,
        data->ress_s.rect_compter, NULL);
}
