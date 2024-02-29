/*
** EPITECH PROJECT, 2023
** dis*
** File description:
** display
*/

#include "my.h"
#include "my_rpg.h"
#include <time.h>

void end_game(main_s *data)
{
    data->hun->perdu = my_text((text_create){
        .color = sfWhite,
        .text = "Perdu !",
        .font = data->police,
        .position = (sfVector2f) {800, 425},
        .size = 100,
    });
    sfRenderWindow_drawText(data->window->game_window, data->hun->perdu,
        NULL);
    sfRenderWindow_setMouseCursorVisible(data->window->game_window, sfTrue);
}

sfVector2f chose_dire(main_s *data)
{
    int sens = 0;
    sfVector2f vector = {0, 0};
    sfVector2f pos = sfSprite_getPosition(data->hun->bird);
    if (sfClock_getElapsedTime(data->hun->y_clock).microseconds > 15000) {
        sens = rand() % 3;
        if (sens == 1 && pos.y < 880)
            vector = (sfVector2f){5, 5};
        if (pos.y > 100 && sens != 1)
            vector = (sfVector2f){5, -5};
        if (!(sens == 1 && pos.y < 880) && !(pos.y > 100 && sens != 1))
            vector = (sfVector2f){5, 0};
        sfClock_restart(data->hun->y_clock);
    }
    return vector;
}

void draw_cursor(main_s *data)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(data->window->game_window);
    sfSprite_setPosition(data->hun->curs_sprite,
        (sfVector2f) {mouse_pos.x, mouse_pos.y});
    sfRenderWindow_drawSprite(data->window->game_window,
        data->hun->curs_sprite, NULL);
    sfRenderWindow_drawText(data->window->game_window,
        data->hun->nb_coin, NULL);
}

void sub_display_hunter_game(main_s *data, sfVector2f vector)
{

    sfSprite_move(data->hun->bird, vector); anime_duck(data);
    if (data->hun->dead == false)
        sfRenderWindow_drawSprite(data->window->game_window,
            data->hun->bird, NULL);
    if (data->hun->tuch == true) {
        float time = sfClock_getElapsedTime(data->hun->text_clock).microseconds;
        sfRenderWindow_drawText(data->window->game_window,
            data->hun->degs, NULL);
        if (time >= 1000000)
            data->hun->tuch = false;
    }
    draw_cursor(data);
}

void display_hunter_game(main_s *data)
{
    time_t t;
    srand((unsigned) time(&t));
    sfVector2f vector = {5, 5};
    sfVector2f pos = sfSprite_getPosition(data->hun->bird);
    sfRenderWindow_setMouseCursorVisible(data->window->game_window, sfFalse);
    vector = chose_dire(data);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->hun->img_back, NULL);
    if (pos.x > 1940 && data->hun->dead == false) {
        end_game_loose(data);
        return;
    }
    if (data->hun->coin == 9) {
        end_game_win(data);
        return;
    }
    sub_display_hunter_game(data, vector);
}
