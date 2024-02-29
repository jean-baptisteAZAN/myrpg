/*
** EPITECH PROJECT, 2023
** periph_vehicule
** File description:
** function : periph_vehicule.c
*/

#include "my.h"
#include "my_rpg.h"

void sub_leave_tractor(main_s *game_s, int no_pass)
{
    if (collision_player_map(game_s, (game_s->tractor_s->pos_x + 30),
        (game_s->tractor_s->pos_y)) == 0) {
        game_s->player_s->pos_p_y = game_s->tractor_s->pos_y;
        no_pass = 1;
        game_s->player_s->pos_p_x = game_s->tractor_s->pos_x + 25;
    }
    if (collision_player_map(game_s, (game_s->tractor_s->pos_x - 30),
        (game_s->tractor_s->pos_y)) == 0) {
        game_s->player_s->pos_p_y = game_s->tractor_s->pos_y;
        no_pass = 1;
        game_s->player_s->pos_p_x = game_s->tractor_s->pos_x - 25;
    }
    if (no_pass == 0) {
        game_s->ress_s.display_text_block = 1;
        sfClock_restart(game_s->ress_s.time_text_block);
        game_s->where_vehicule = 2;
    }
}

void leave_tractor(main_s *game_s)
{
    if (sfClock_getElapsedTime(
        game_s->ress_s.colddown_enter_vehicule).microseconds < 500000) return;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        int no_pass = 0;
        game_s->where_vehicule = 0;
        game_s->tractor_s->speed = 0;
        sfClock_restart(game_s->ress_s.colddown_enter_vehicule);
        sub_leave_tractor(game_s, no_pass);
    }
}

int periph_tractor(main_s *game_s)
{
    home_plowed(game_s);
    sfView_setCenter(game_s->ress_s.view_p,
        (sfVector2f){(int)game_s->tractor_s->pos_x,
            (int)game_s->tractor_s->pos_y});
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_forward_tractor(game_s, 0.1, 1);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_forward_tractor(game_s, -0.06, -1);
    if (!sfKeyboard_isKeyPressed(sfKeyZ) || !sfKeyboard_isKeyPressed(sfKeyS))
        brake_forward_tractor(game_s, 0.05);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        turn_tractor_right(game_s);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        turn_tractor_left(game_s);
    leave_tractor(game_s);
    sfSprite_setPosition(game_s->tractor_s->tractor,
        (sfVector2f){game_s->tractor_s->pos_x,game_s->tractor_s->pos_y});
    return 0;
}
