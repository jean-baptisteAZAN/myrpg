/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** function: display inv
*/

#include "my.h"
#include "my_rpg.h"

void display_gun_inv(main_s *data)
{
    sfSprite_setPosition(data->inv_s.gun->gun, (sfVector2f) {320, 430});
    sfSprite_setScale(data->inv_s.gun->gun, (sfVector2f) {0.3, 0.3});
    sfRenderWindow_drawSprite(data->window->game_window,
        data->inv_s.gun->gun, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
        data->inv_s.button_boost, NULL);
    if (data->inv_s.print_desc && !data->inv_s.print_coin_dsc &&
        !data->inv_s.prin_ble ) {
        sfRenderWindow_drawRectangleShape(data->window->game_window,
            data->inv_s.rect_lvl_riffle, NULL);
        sfRenderWindow_drawText(data->window->game_window,
            data->inv_s.nb_lvl_riffle, NULL);
        sfRenderWindow_drawText(data->window->game_window,
            data->inv_s.txt_desc_inv, NULL);
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.gun->gun_cpy, NULL);
    }
}

void display_coin_inv(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
        data->inv_s.coin, NULL);
    if (data->inv_s.print_coin_dsc && !data->inv_s.print_desc &&
        !data->inv_s.prin_ble ) {
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.coin_cpy, NULL);
        sfRenderWindow_drawText(data->window->game_window,
            data->inv_s.desc_coin, NULL);
        sfRenderWindow_drawText(data->window->game_window,
            data->inv_s.nb_coin_inv, NULL);
    }
}

void disp_ble(main_s *data)
{
    if (data->inv_s.prin_ble && !data->inv_s.print_coin_dsc &&
    !data->inv_s.print_coin_dsc) {
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.cpy_ble, NULL);
        sfRenderWindow_drawText(data->window->game_window, data->inv_s.nb_ble,
            NULL);
        sfRenderWindow_drawText(data->window->game_window, data->inv_s.text_ble,
            NULL);
    }
}

void display_inv(main_s *data)
{
    if (data->inv_s.gun->find == false) {
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.gun->gun, NULL);
        sfSprite_setScale(data->inv_s.gun->gun, (sfVector2f) {0.05, 0.05});
        sfSprite_setPosition(data->inv_s.gun->gun, (sfVector2f) {1200, 915});
    }
    if (data->inv_s.verif == true) {
        sfRenderWindow_setView(data->window->game_window,
            data->ress_s.view_map);
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.sprite_txt, NULL);
        sfRenderWindow_drawSprite(data->window->game_window,
            data->inv_s.sprite_ble, NULL);
        disp_ble(data);
        display_coin_inv(data);
        if (data->inv_s.gun->find == true)
            display_gun_inv(data);

    }
}
