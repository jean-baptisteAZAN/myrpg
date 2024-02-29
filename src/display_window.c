/*
** EPITECH PROJECT, 2023
** dis
** File description:
** dis
*/

#include "my.h"
#include "my_rpg.h"
#include "struct_all.h"

void scene_3(main_s *data)
{
    sfRenderWindow_clear(data->window->game_window, sfBlack);
    periph_home(data, data->window->event);
    display_res(data, data->window->game_window);
    disp_opps(data);
    display_inv(data);
    if (data->loaded == 0)
        display_all_tuto(data);
    display_recolted(data);
}

void menu_display(main_s *data)
{
    if (data->where == 3) {
        if (data->cinematic->display_cine == 1)
            display_cinematic(data);
        else {
            scene_3(data);
            verif_inven(data);
            disp_go_hun(data);
        }
    }
    if (data->where == 4)
        display_help(data);
    if (data->where == 5)
        display_hunter_game(data);
    if (data->where == 6)
        display_ig_menu(data);
    if (data->where == 7)
        command_menu(data);
    if (data->where == 8)
        happy_end(data);
}

void draw_window(main_s *data)
{
    if (data->where == 0) {
        draw_frame_animed_fond(data);
        sfRenderWindow_drawSprite(data->window->game_window,
        data->menu->sprite_menu, NULL);
        while (data->info_load->env == -1)
            menu_loading(data, data->window->game_window);
        display_buttons_status(data);
    }
    if (data->where == 1)
        display_settings(data);
    if (data->where == 2)
        display_start_menu(data);
    menu_display(data);
}

void sub_display_window(main_s *data)
{
    while (sfRenderWindow_pollEvent(data->window->game_window,
    &data->window->event)) {
        if (data->window->event.type == sfEvtClosed)
            sfRenderWindow_close(data->window->game_window);
    }
    draw_window(data);
    update_window(data);
    memset(&data->window->event, 0, sizeof(sfEvent));
}

void display_window(main_s *data)
{
    sfMusic_play(data->music);
    data->where = 0;
    while (sfRenderWindow_isOpen(data->window->game_window)) {
        sub_display_window(data);
        sfRenderWindow_display(data->window->game_window);
    }
}
