/*
** EPITECH PROJECT, 2023
** INIT
** File description:
** INIT
*/

#include "my.h"
#include "my_rpg.h"

void init_chat(main_s *data)
{
    data->go_hunt->chat = my_sprite((sprite_create) {
        .texture = sfTexture_createFromFile
        ("./ressources/hunter/chat.png", NULL),
        .position = (sfVector2f) {0, 0},
        .scale = (sfVector2f) {1, 1},
        .color = sfWhite,
    });
    data->go_hunt->want_hunt = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {400, 790},
        .size = 50,
        .text =
        "Tu veux negocier le prix de ton ble ?\non va regler cela a la chasse",
    });
}

void init_presse(main_s * data)
{
    data->go_hunt->presse = my_sprite((sprite_create) {
        .color = sfWhite,
        .scale = (sfVector2f) {0.1, 0.1},
        .texture = sfTexture_createFromFile
        ("./ressources/hunter/pressE.png", NULL),
        .position = (sfVector2f) {335, 78},
        .origine = (sfVector2f) {269.5, 53.5},
    });
    data->go_hunt->need_gun = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1000, 100},
        .size = 50,
        .text =
        "Pour chasser, tu dois d'abord\ntrouver un fusil, \
\nbalade toi pour le trouver",
    });
}

void init_button_hunt_no(main_s *data)
{
    data->go_hunt->button_no = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {1250, 970},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {0.5, 0.5},
    });
    data->go_hunt->text_no = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {1255, 935},
        .size = 20,
        .text = "NON !"
    });
}

void init_button_hunt_yes(main_s *data)
{
    data->go_hunt->button_yes = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {550, 970},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {0.5, 0.5},
    });
    data->go_hunt->text_yes = my_text((text_create) {
        .color = sfWhite,
        .font = sfFont_createFromFile("ressources/minecraft_font.ttf"),
        .position = (sfVector2f) {555, 935},
        .size = 20,
        .text = "Oui !"
    });
}

void init_go_hunt(main_s *data)
{
    init_presse(data);
    init_chat(data);
    init_button_hunt_yes(data);
    init_button_hunt_no(data);
    data->go_hunt->chat_go_hunt = false;
    data->go_hunt->print_text = false;
    data->go_hunt->draw_text_gun = sfClock_create();
    data->go_hunt->perso = my_sprite((sprite_create) {
        .color = sfWhite,
        .texture = sfTexture_createFromFile
        ("./ressources/hunter/chasseur.png", NULL),
        .scale = (sfVector2f) {0.1, 0.1},
        .position = (sfVector2f) {308, 72},
    });
}
