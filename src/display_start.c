/*
** EPITECH PROJECT, 2023
** displ
** File description:
** displ
*/

#include "my.h"
#include "my_rpg.h"

void sub_sprite_gene(main_s *data)
{
    data->menu->but->resume = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1150, 750},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .scale = (sfVector2f) {1, 1},
    });
    data->menu->but->help_txt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1150, 820},
        .size = 60,
        .text = "Aide",
    });
}

void display_start_menu(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->perso->before_sprite, NULL);
    sfRenderWindow_drawRectangleShape(data->window->game_window,
    data->menu->perso->zone_name, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->perso->text_zone, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->perso->button_start, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->perso->txt_strt, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->perso->button_back, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->perso->txt_back, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->perso->visu_sprite, NULL);
}
