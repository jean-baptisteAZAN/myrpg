/*
** EPITECH PROJECT, 2023
** home_periph_player.c
** File description:
** function : home_periph_player
*/


#include "my.h"
#include "my_rpg.h"

void next_sprite_player(main_s *game_s)
{
    if (sfClock_getElapsedTime(game_s->player_s->time_sprite).microseconds
        < 90000)
        return;
    if (game_s->player_s->sens == 1)
        anime_sprite_player_up(game_s);
    if (game_s->player_s->sens == 3)
        anime_sprite_player_down(game_s);
    if (game_s->player_s->sens == 2)
        anime_sprite_player_right(game_s);
    if (game_s->player_s->sens == 4)
        anime_sprite_player_left(game_s);
    if (game_s->player_s->moove_on_off == 1) {
        if (game_s->player_s->frame_player == 3)
            game_s->player_s->frame_player = 1;
        else
            game_s->player_s->frame_player++;
    }
    sfClock_restart(game_s->player_s->time_sprite);
}

void home_moove_player(main_s *game_s)
{
    if (game_s->player_s->moove_on_off == 1) {
        next_sprite_player(game_s);
        sfClock_restart(game_s->player_s->time_moove);
    }
    if (game_s->player_s->moove_on_off == 0) {
        game_s->player_s->frame_player = 1;
        next_sprite_player(game_s);
    }
}

void enter_in_harvest(main_s *game_s)
{
    int calc_pos_x_harvest =
        game_s->player_s->pos_p_x - game_s->harvest_s->pos_x;
    int calc_pos_y_harvest =
        game_s->player_s->pos_p_y - game_s->harvest_s->pos_y;
    if (calc_pos_x_harvest > -40 && calc_pos_x_harvest < 40) {
        if (calc_pos_y_harvest > -40 && calc_pos_y_harvest < 40)
            game_s->where_vehicule = 3;
    }
}

void enter_in_vehicule(main_s *game_s)
{
    if (!sfKeyboard_isKeyPressed(sfKeyE))
        return;
    if (sfClock_getElapsedTime(
        game_s->ress_s.colddown_enter_vehicule).microseconds < 500000)
        return;
    int calc_pos_x_pickup = game_s->player_s->pos_p_x - game_s->pickup_s.pos_x;
    int calc_pos_y_pickup = game_s->player_s->pos_p_y - game_s->pickup_s.pos_y;
    if (calc_pos_x_pickup > -40 && calc_pos_x_pickup < 40)
        if (calc_pos_y_pickup > -40 && calc_pos_y_pickup < 40)
            game_s->where_vehicule = 1;
    int calc_pos_x_tractor =
        game_s->player_s->pos_p_x - game_s->tractor_s->pos_x;
    int calc_pos_y_tractor =
        game_s->player_s->pos_p_y - game_s->tractor_s->pos_y;
    if (calc_pos_x_tractor > -40 && calc_pos_x_tractor < 40) {
        if (calc_pos_y_tractor > -40 && calc_pos_y_tractor < 40)
            game_s->where_vehicule = 2;
    }
    enter_in_harvest(game_s);
    sfClock_restart(game_s->ress_s.colddown_enter_vehicule);
}

int home_periph_player(main_s *game_s)
{
    game_s->player_s->moove_on_off = 0;
    movement_player(game_s);
    home_moove_player(game_s);

    sfView_setCenter(game_s->ress_s.view_p,
        (sfVector2f){game_s->player_s->pos_p_x, game_s->player_s->pos_p_y});
    sfSprite_setPosition(game_s->player_s->player,
        (sfVector2f){game_s->player_s->pos_p_x, game_s->player_s->pos_p_y});

    enter_in_vehicule(game_s);
    return 0;
}
