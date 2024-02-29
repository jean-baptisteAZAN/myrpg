/*
** EPITECH PROJECT, 2023
** hunter
** File description:
** hunter
*/

#include "my.h"
#include "my_rpg.h"

void add_coin(main_s *data)
{
    data->hun->coin++;
    char *nb = malloc(sizeof(char) * 2);
    nb[0] = data->hun->coin + 48;
    nb[1] = '\0';
    sfText_setString(data->hun->nb_coin, nb);
}

void print_one(main_s *data)
{
    sfVector2f pos = sfSprite_getPosition(data->hun->bird);

    data->hun->degs = my_text((text_create){
        .color = sfWhite,
        .text = "- 1",
        .font = data->police,
        .position = (sfVector2f) {pos.x, pos.y - 60},
        .size = 60,
    });
    sfClock_restart(data->hun->text_clock);
    data->hun->tuch = true;
}

void status_button_end(main_s *data)
{
    sfSprite_setTexture(data->hun->return_game,
        data->menu->but->texture_pressed, sfFalse);
    if (data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft ) {
        data->go_hunt->chat_go_hunt = false;
        data->where = 3;
        reset_all(data);
    }
}

void button_end(main_s *data)
{
    if (data->hun->finish == false)
        return;
    sfFloatRect end_g = sfSprite_getGlobalBounds(data->hun->return_game);

    if (sfFloatRect_contains(&end_g,
    data->mouse_pos.x, data->mouse_pos.y) && data->hun->loose)
        status_button_end(data);
    else
        sfSprite_setTexture(data->hun->return_game,
            data->menu->but->texture_play, sfFalse);
}

void is_in_hunter(main_s *data)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(data->window->game_window);
    sfFloatRect start = sfSprite_getGlobalBounds(data->hun->bird);

    button_end(data);
    if (sfFloatRect_contains(&start, (float)pos.x, (float)pos.y) == sfTrue &&
        data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft) {
        data->hun->health--;
        print_one(data);
        if (data->hun->health == 0)
            add_coin(data);
    }
    if (data->hun->health == 0) {
        sfSprite_setPosition(data->hun->bird, (sfVector2f) {-50, rand() % 880});
        data->hun->health = 4 - data->player_s->gun_xp;
    }
}
