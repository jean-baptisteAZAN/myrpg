/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-romain.collignon
** File description:
** menu
*/

#include "my.h"
#include "my_rpg.h"

bool init_button(main_s *data)
{
    data->menu->but->button =
    sfImage_createFromFile("ressources/bouton_vierge.jpg");
    data->menu->but->texture_play =
    sfTexture_createFromImage(data->menu->but->button, NULL);
    data->menu->but->texture_pressed =
    sfTexture_createFromFile("ressources/bouton_vierge2.png", NULL);
    generate_sprite_buttons(data);
    data->menu->but->texture_hover =
    sfTexture_createFromFile("ressources/bouton_vierge3.png", NULL);
    return (true);
}

void init_retour_but(main_s *data)
{
    data->menu->back_button = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {100, 1000},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu->txt_back = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {70, 920},
        .size = 60,
        .text = "Retour",
    });

}

void init_desc_coin(main_s *data)
{
    data->inv_s.desc_coin = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1100, 450},
        .size = 30,
        .text = my_strcat(text_inven[2],
        my_strcat(text_inven[3], text_inven[4])),
    });
    data->inv_s.nb_coin_inv = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1320, 320}, .size = 50,
        .text = my_put_nbr_int(data->player_s->money),
    });
}

void init_cmd_menu(main_s *data)
{
    data->menu->texture_cmd =
    sfTexture_createFromFile("ressources/cmd_img.png", NULL);
    data->menu->sprite_cmd = my_sprite((sprite_create) {
        .color = sfWhite, .origine = (sfVector2f) {0, 0},
        .position = (sfVector2f) {0, 0},
        .texture = data->menu->texture_cmd,
        .scale = (sfVector2f) {1, 1},
    });
    data->menu_ig->txt_settings = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1300, 270},
        .size = 55,
        .text = "Settings",
    });
    init_retour_but(data);
}

bool init_menu(main_s *data)
{
    if ((data->menu->my_menu =
    sfImage_createFromFile("ressources/menu_modif.png")) == NULL)
        return (false);
    data->menu->texture_menu = sfTexture_createFromImage(data->menu->my_menu,
    NULL);
    if ((data->menu->settings_texture =
    sfTexture_createFromFile("ressources/settings_wlp.png", NULL)) == NULL)
        return (false);
    data->menu->sprite_menu = sfSprite_create();
    data->volume = (float) 50;
    data->menu->settings->nb_fps = 60;
    if ((data->music = sfMusic_createFromFile("ressources/music.ogg")) == NULL)
        return (false);
    sfMusic_setVolume(data->music, data->volume);
    if (!init_button(data))
        return (false);
    if (!init_help_menu(data))
        return (false);
    init_txt(data);
    return (true);
}
