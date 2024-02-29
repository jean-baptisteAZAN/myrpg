/*
** EPITECH PROJECT, 2023
** hini
** File description:
** init
*/

#include "my.h"
#include "my_rpg.h"


void init_buton_return(main_s *data)
{
    data->hun->return_game = my_sprite((sprite_create) {
        .texture = data->menu->but->texture_play,
        .position = (sfVector2f) {865, 765},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {0.8, 0.8},
    });
    data->hun->yes_return = my_text((text_create) {
        .color = sfWhite,
        .font = sfFont_createFromFile("ressources/minecraft_font.ttf"),
        .position = (sfVector2f) {850, 700},
        .size = 50,
        .text = "quitter"
    });
    data->hun->pass = false;
}

void init_coin(main_s  *data)
{
    data->hun->frame_duck = 1;
    data->hun->coin = 0;
    init_buton_return(data);
    data->hun->animate_clock = sfClock_create();
    data->hun->y_clock = sfClock_create();
    data->hun->text_clock = sfClock_create();
    data->hun->health = 4 - data->player_s->gun_xp;
    data->hun->dead = false;
    data->hun->tuch = false;
    data->hun->finish = false;
    data->hun->nb_coin = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .text = "0",
        .size = 35,
        .position = (sfVector2f) {1550, 70},
    });
}

void init_hunter(main_s *data)
{
    data->hun->img_back = init_fond("./ressources/hunter/hunter_back.png");
    data->hun->bird = sfSprite_create();
    data->hun->loose = false;
    data->hun->bird = my_sprite((sprite_create) {
        .color = sfWhite,
        .origine = (sfVector2f) {100, 100},
        .position = (sfVector2f) {-50, rand() % 880},
        .texture =
        sfTexture_createFromFile("./ressources/hunter/oiseau.png", NULL),
        .scale = (sfVector2f) {1, 1},
    });
    data->hun->curs_sprite = my_sprite((sprite_create){
        .color = sfWhite,
        .texture =
        sfTexture_createFromFile("./ressources/hunter/viseur.png", NULL),
        .origine = (sfVector2f) {331, 163},
        .position = (sfVector2f) {100, 100}, .scale = (sfVector2f) {0.2, 0.2},
    });
    init_coin(data);
}
