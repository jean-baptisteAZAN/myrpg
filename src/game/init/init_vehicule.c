/*
** EPITECH PROJECT, 2023
** init_menu_home
** File description:
** function : init_menu_home.c
*/
#include "my.h"
#include "my_rpg.h"

void init_pickup(main_s *game_s)
{
    game_s->pickup_s.pickup = init_fond("./ressources/res/game/pickup.png");
    sfSprite_setScale(game_s->pickup_s.pickup, (sfVector2f){0.25, 0.25});
    game_s->pickup_s.pos_x = 600;
    game_s->pickup_s.pos_y = 280;
    game_s->pickup_s.sens = 7;
    turn_sprite(game_s);
    game_s->pickup_s.speed_x = 0;
    game_s->pickup_s.speed_y = 0;
    game_s->pickup_s.speed = 0;
    game_s->pickup_s.speed_limit = 4.2;
    game_s->pickup_s.t_rotate = sfClock_create();
    game_s->pickup_s.t_speed = sfClock_create();
    sfSprite_setPosition(game_s->pickup_s.pickup,
        (sfVector2f){(int)game_s->pickup_s.pos_x, (int)game_s->pickup_s.pos_y});
}

void init_player(main_s *game_s)
{
    game_s->player_s->player = init_fond("./ressources/res/game/farmer.jpg");
    sfSprite_setScale(game_s->player_s->player, (sfVector2f){0.1, 0.1});
    game_s->player_s->frame_player = 1;
    game_s->player_s->sens = 1;
    game_s->player_s->moove_on_off = 0;
    game_s->player_s->pos_p_x = 780;
    game_s->player_s->pos_p_y = 362;
    game_s->player_s->speed = 0.7;
    game_s->player_s->time_moove = sfClock_create();
    game_s->player_s->time_sprite = sfClock_create();
    sfSprite_setPosition(game_s->player_s->player,
        (sfVector2f){game_s->player_s->pos_p_x, game_s->player_s->pos_p_y});
}

void init_tractor(main_s *game_s)
{
    game_s->tractor_s->tractor = init_fond("./ressources/res/game/tractor.png");
    sfSprite_setScale(game_s->tractor_s->tractor, (sfVector2f){0.39, 0.39});
    game_s->tractor_s->pos_x = 600;
    game_s->tractor_s->pos_y = 630;
    game_s->tractor_s->sens = 6;
    turn_sprite_tractor(game_s);
    game_s->tractor_s->speed_x = 0;
    game_s->tractor_s->speed_y = 0;
    game_s->tractor_s->speed = 0.3;
    game_s->tractor_s->speed_limit = 2.0;
    game_s->tractor_s->t_rotate = sfClock_create();
    game_s->tractor_s->t_speed = sfClock_create();
    sfSprite_setPosition(game_s->tractor_s->tractor,
        (sfVector2f){(int)game_s->tractor_s->pos_x,
            (int)game_s->tractor_s->pos_y});
}

void init_harvester(main_s *game_s)
{
    game_s->harvest_s = malloc(sizeof(c_s));
    game_s->harvest_s->harvest = init_fond("./ressources/res/game/harvest.png");
    sfSprite_setScale(game_s->harvest_s->harvest, (sfVector2f){0.39, 0.39});
    game_s->harvest_s->pos_x = 550;
    game_s->harvest_s->pos_y = 630;
    game_s->harvest_s->sens = 6;
    turn_sprite_harvest(game_s);
    game_s->harvest_s->speed_x = 0;
    game_s->harvest_s->speed_y = 0;
    game_s->harvest_s->speed = 0.3;
    game_s->harvest_s->speed_limit = 2.0;
    game_s->harvest_s->t_rotate = sfClock_create();
    game_s->harvest_s->t_speed = sfClock_create();
    sfSprite_setPosition(game_s->harvest_s->harvest,
        (sfVector2f){(int)game_s->harvest_s->pos_x,
            (int)game_s->harvest_s->pos_y});
}

void init_vehicule(main_s * game_s)
{
    game_s->ress_s.colddown_enter_vehicule = sfClock_create();
    init_harvester(game_s);
    init_pickup(game_s);
    init_player(game_s);
    init_tractor(game_s);
    init_compter(game_s);
    game_s->where_vehicule = 0;
}
