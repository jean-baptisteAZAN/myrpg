/*
** EPITECH PROJECT, 2023
** free
** File description:
** fre
*/

#include "my.h"
#include "my_rpg.h"

void free_go_hun(main_s *data)
{
    sfSprite_destroy(data->go_hunt->perso);
    sfSprite_destroy(data->go_hunt->presse);
    sfSprite_destroy(data->go_hunt->chat);
    sfSprite_destroy(data->go_hunt->button_yes);
    sfSprite_destroy(data->go_hunt->button_no);
    sfText_destroy(data->go_hunt->text_yes);
    sfText_destroy(data->go_hunt->want_hunt);
    sfText_destroy(data->go_hunt->text_no);
    free(data->go_hunt);
    free(data->opps);
}

void free_ingame(main_s *data)
{
    sfImage_destroy(data->menu_ig->menu_ig_img);
    sfTexture_destroy(data->menu_ig->menu_ig_txt);
    sfSprite_destroy(data->menu_ig->ig_menu_spr);
    sfText_destroy(data->menu_ig->txt_sav);
    sfSprite_destroy(data->menu_ig->button_sav);
    sfSprite_destroy(data->menu_ig->button_load);
    sfText_destroy(data->menu_ig->txt_load);
    sfSprite_destroy(data->menu_ig->button_settings);
    sfText_destroy(data->menu_ig->txt_settings);
    sfSprite_destroy(data->menu_ig->piece_spr);
    sfText_destroy(data->menu_ig->money_compt);
    sfSprite_destroy(data->menu_ig->money_slot);
    sfSprite_destroy(data->menu_ig->exit_but);
    free(data->menu_ig);
}

void free_loading_bar(main_s *data)
{
    sfClock_destroy(data->load->time);
    sfFont_destroy(data->load->Font_txt_01);
    sfText_destroy(data->load->txt_load);
    sfText_destroy(data->load->txt_wait);
    sfText_destroy(data->load->txt_leave);
    sfRectangleShape_destroy(data->load->contour);
    sfRectangleShape_destroy(data->load->bar_load);
    free_ingame(data);
    free_harvest(data);
}

void free_menu(main_s *data)
{
    sfTexture_destroy(data->menu->texture_menu);
    sfTexture_destroy(data->menu->settings_texture);
    sfTexture_destroy(data->menu->texture_cmd);
    sfSprite_destroy(data->menu->sprite_cmd);
    sfSprite_destroy(data->menu->back_button);
    sfSprite_destroy(data->menu->fond_animed);
    sfText_destroy(data->menu->txt_back);
    free(data->menu);
}
