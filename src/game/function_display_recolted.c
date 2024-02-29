/*
** EPITECH PROJECT, 2023
** function_display_recolted.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void init_display_recolted(main_s *data)
{
    data->inv_s.nb_recolted = 10;
    data->inv_s.text_nb_recolted = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/minecraft_font.ttf");
    sfText_setString(data->inv_s.text_nb_recolted, "0");
    sfText_setPosition(data->inv_s.text_nb_recolted, (sfVector2f){125, 480});
    sfText_setFont(data->inv_s.text_nb_recolted, font);
    sfText_setCharacterSize(data->inv_s.text_nb_recolted, 20);
    sfText_setScale(data->inv_s.text_nb_recolted, (sfVector2f){0.25, 0.25});
    sfText_setColor(data->inv_s.text_nb_recolted, sfWhite);

    sfColor color = {30, 30, 30, 255};
    data->inv_s.back_text_recolted = sfRectangleShape_create();
    sfRectangleShape_setPosition(data->inv_s.back_text_recolted,
        (sfVector2f){125, 480});
    sfRectangleShape_setFillColor(data->inv_s.back_text_recolted, color);
    sfRectangleShape_setSize(data->inv_s.back_text_recolted,
        (sfVector2f){30, 10});
    data->inv_s.icon_recolted =
        init_fond("./ressources/res/game/icon_wheat.png");
    sfSprite_setScale(data->inv_s.icon_recolted, (sfVector2f){0.17, 0.17});
}

void change_position_display_recolted(main_s *data)
{
    sfVector2f pos = sfView_getCenter(data->ress_s.view_p);
    sfRectangleShape_setPosition(data->inv_s.back_text_recolted,
        (sfVector2f){pos.x - 142, pos.y - 79});
    sfSprite_setPosition(data->inv_s.icon_recolted,
        (sfVector2f){pos.x - 141, pos.y - 78});
    sfText_setPosition(data->inv_s.text_nb_recolted,
        (sfVector2f){pos.x - 135, pos.y - 77});
}

int get_nb_enum(int nb)
{
    int count = 0;
    do {
        ++count;
        nb /= 10;
    } while (nb != 0);
    return count;
}

void display_recolted(main_s *data)
{
    if (data->ress_s.open_map == 1)
        return;
    if (data->inv_s.verif == true)
        return;
    change_position_display_recolted(data);

    if (data->inv_s.text_nb_recolted != 0) {
        sfText_setString(data->inv_s.text_nb_recolted,
            int_pass_char(data->inv_s.nb_recolted));
        sfText_setString(data->inv_s.nb_ble,
        int_pass_char(data->inv_s.nb_recolted));
    }
    sfRectangleShape_setSize(data->inv_s.back_text_recolted,
        (sfVector2f){9 + (4 * get_nb_enum(data->inv_s.nb_recolted)), 10});
    sfRenderWindow_drawRectangleShape(data->window->game_window,
        data->inv_s.back_text_recolted, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
        data->inv_s.icon_recolted, NULL);
    sfRenderWindow_drawText(data->window->game_window,
        data->inv_s.text_nb_recolted, NULL);
}
