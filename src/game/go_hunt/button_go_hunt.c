/*
** EPITECH PROJECT, 2023
** go
** File description:
** go
*/

#include "my.h"
#include "my_rpg.h"

void sub_go_hunt(main_s *data)
{
    sfFloatRect but_no = sfSprite_getGlobalBounds(data->go_hunt->button_no);
    sfFloatRect but_yes = sfSprite_getGlobalBounds(data->go_hunt->button_yes);
    if (sfFloatRect_contains(&but_yes,
        data->mouse_pos.x, data->mouse_pos.y))
            status_button_yes(data);
    else
        sfSprite_setTexture(data->go_hunt->button_yes,
            data->menu->but->texture_play, sfFalse);
    if (sfFloatRect_contains(&but_no,
        data->mouse_pos.x, data->mouse_pos.y))
            status_button_no(data);
    else
        sfSprite_setTexture(data->go_hunt->button_no,
            data->menu->but->texture_play, sfFalse);
}

void sub_display_chat_hunt(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
        data->go_hunt->chat, NULL );
        sfRenderWindow_drawText(data->window->game_window,
        data->go_hunt->want_hunt, NULL);
        sfRenderWindow_drawSprite(data->window->game_window,
        data->go_hunt->button_yes, NULL );
        sfRenderWindow_drawText(data->window->game_window,
        data->go_hunt->text_yes, NULL);
        sfRenderWindow_drawSprite(data->window->game_window,
        data->go_hunt->button_no, NULL );
        sfRenderWindow_drawText(data->window->game_window,
        data->go_hunt->text_no, NULL); sub_go_hunt(data);
}
