/*
** EPITECH PROJECT, 2023
** free
** File description:
** free
*/

#include "my.h"
#include "my_rpg.h"

void free_but_struct(main_s *data)
{
    sfSprite_destroy(data->menu->sprite_menu);
    sfSprite_destroy(data->menu->but->settings);
    sfSprite_destroy(data->menu->but->resume);
    sfSprite_destroy(data->menu->but->play);
    sfSprite_destroy(data->menu->but->exit);
    sfSprite_destroy(data->menu->but->button_help);
    sfImage_destroy(data->menu->but->button);
    sfTexture_destroy(data->menu->but->texture_play);
    sfTexture_destroy(data->menu->but->texture_pressed);
    sfTexture_destroy(data->menu->but->texture_hover);
    sfText_destroy(data->menu->but->play_txt);
    sfText_destroy(data->menu->but->resume_txt);
    sfText_destroy(data->menu->but->settings_txt);
    sfText_destroy(data->menu->but->quit);
    sfText_destroy(data->menu->but->help_txt);
}

void free_window_s(main_s *data)
{
    sfRenderWindow_destroy(data->window->game_window);
}

void free_hunter_s(main_s *data)
{
    sfSprite_destroy(data->hun->img_back);
    sfSprite_destroy(data->hun->bird);
    sfSprite_destroy(data->hun->curs_sprite);
    sfSprite_destroy(data->hun->return_game);
    sfText_destroy(data->hun->nb_coin);
    sfText_destroy(data->hun->yes_return);
}

void free_cinematic(main_s *data)
{
    sfTexture_destroy(data->cinematic->text_dialogue_women);
    sfSprite_destroy(data->cinematic->sp_dialogue);
    sfText_destroy(data->cinematic->dialo);
    sfSprite_destroy(data->cinematic->button_next);
    sfText_destroy(data->error_message);
    sfSprite_destroy(data->tuto->panneau);
    sfClock_destroy(data->clock_error_load);
    sfImage_destroy(data->ress_s.img_map_01);
    for (int i = 0; data->tuto->tab_text[i]; i++)
        sfTexture_destroy(data->tuto->tab_text[i]);
}

void free_all(main_s *data)
{
    free_window_s(data);
    free_but_struct(data);
    free_hunter_s(data);
    free_go_hun(data);
    free_menu(data);
    free_cinematic(data);
    free_loading_bar(data);
    sfFont_destroy(data->police);
}
