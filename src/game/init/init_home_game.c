/*
** EPITECH PROJECT, 2023
** init_menu_home.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void init_ress_view(main_s *game_s)
{
    game_s->ress_s.view_p = sfView_create();
    game_s->ress_s.x_view = 400;
    game_s->ress_s.y_view = 320;
    sfView_setCenter(game_s->ress_s.view_p,
        (sfVector2f){(int)game_s->ress_s.x_view, (int)game_s->ress_s.y_view});
    sfView_setSize(game_s->ress_s.view_p, (sfVector2f){1920, 1080});
    sfView_zoom(game_s->ress_s.view_p, 0.15);

    game_s->ress_s.view_map = sfView_create();
    game_s->ress_s.view_resize = sfView_create();
    sfView_setSize(game_s->ress_s.view_map, (sfVector2f){1920, 1080});
    sfView_setSize(game_s->ress_s.view_resize, (sfVector2f){1920, 1000});
    sfView_setCenter(game_s->ress_s.view_map, (sfVector2f){960, 540});
    sfView_setCenter(game_s->ress_s.view_resize, (sfVector2f){960, 500});
}

void init_ress_text_block(main_s *game_s)
{
    game_s->ress_s.text_block = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/minecraft_font.ttf");
    sfText_setString(game_s->ress_s.text_block,
        "Impossible de sortir du vehicule !");
    sfText_setPosition(game_s->ress_s.text_block, (sfVector2f){125, 480});
    sfText_setFont(game_s->ress_s.text_block, font);
    sfText_setCharacterSize(game_s->ress_s.text_block, 20);
    sfText_setScale(game_s->ress_s.text_block, (sfVector2f){0.1, 0.1});
    sfText_setColor(game_s->ress_s.text_block, sfWhite);
    game_s->ress_s.time_text_block = sfClock_create();
    game_s->ress_s.display_text_block = 0;
}

void init_ress(main_s *game_s)
{
    game_s->ress_s.map_01 = init_fond("./ressources/res/game/map_all.png");
    game_s->ress_s.map_02 = init_fond("./ressources/res/game/map_void.png");
    game_s->ress_s.img_map_01 =
        sfImage_createFromFile("./ressources/res/game/map_all.png");
    init_ress_view(game_s);
    game_s->ress_s.time = sfClock_create();
    game_s->ress_s.clock_open_map = sfClock_create();
    game_s->ress_s.open_map = 0;
    game_s->ress_s.saison = sfClock_create();
    game_s->ress_s.time_saison = 30000000;
    game_s->ress_s.color_tmp = sfRed;
    init_ress_text_block(game_s);
    game_s->ress_s.could_down_save = sfClock_create();
    game_s->ress_s.could_downn_tab = sfClock_create();
}

sfSprite* init_fond(char *image)
{
    sfTexture* texture = sfTexture_createFromFile(image, NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void init_res(main_s *game_s)
{
    game_s->where = 0;
    game_s->where_vehicule = -1;
    game_s->npc_s.pickup_is_buy = 1;
    game_s->npc_s.tractor_is_buy = 1;
    game_s->player_s->exp = 0;
    game_s->player_s->money = 0;
    game_s->player_s->gun_xp = 1;
    init_ress(game_s);
    init_max_field(game_s);
    init_vehicule(game_s);
    home_init_field(game_s);
    init_collision(game_s);
    init_display_recolted(game_s);
    init_msg_voisin(game_s);
    game_s->ress_s.load = 0;
}
