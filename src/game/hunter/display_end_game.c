/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** function end_game_win, end_game_loose
*/

#include "my_rpg.h"
#include "my.h"

void reset_all(main_s *data)
{
    data->hun->coin = 0;
    data->hun->pass = false;
    data->hun->loose = false;
    sfSprite_setPosition(data->hun->bird, (sfVector2f) {-50, rand() % 880});
    data->hun->health = 4 - data->player_s->gun_xp;
    sfText_setString(data->hun->nb_coin, "0");
}

void sub_end_game_win(main_s *data)
{
    data->inv_s.nb_recolted = 10;
    sfRenderWindow_drawText(data->window->game_window, data->hun->perdu,
        NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
        data->hun->return_game, NULL);
    sfRenderWindow_drawText(data->window->game_window, data->hun->yes_return,
        NULL);
    sfRenderWindow_setMouseCursorVisible(data->window->game_window, sfTrue);
}

void end_game_win(main_s *data)
{
    data->hun->finish = true;
    data->hun->loose = true;
    data->hun->perdu = my_text((text_create){
        .color = sfWhite,
        .text = "Bravo, c'etait une \n  super chasse !",
        .font =
        data->police,
        .position = (sfVector2f) {500, 425},
        .size = 100,
    });
    if (data->hun->pass == 0) {
        data->player_s->money += data->inv_s.nb_recolted *
        (data->hun->coin / 4);
        data->hun->pass = 1;
    }
    sub_end_game_win(data);
}

void sub_end_game_loose(main_s *data)
{
    data->inv_s.nb_recolted = 10;
    sfRenderWindow_drawText(data->window->game_window, data->hun->perdu,
        NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
        data->hun->return_game, NULL);
    sfRenderWindow_drawText(data->window->game_window, data->hun->yes_return,
        NULL);
    sfRenderWindow_setMouseCursorVisible(data->window->game_window, sfTrue);
}

void end_game_loose(main_s *data)
{
    data->hun->finish = true;
    data->hun->loose = true;
    data->hun->perdu = my_text((text_create){
        .color = sfWhite,
        .text = "Perdu !",
        .font = data->police,
        .position = (sfVector2f) {800, 425},
        .size = 100,
    });
    if (data->hun->pass == 0) {
        data->player_s->money += data->inv_s.nb_recolted *
        (data->hun->coin / 4);
        data->hun->pass = 1;
    }
    sub_end_game_loose(data);
}
