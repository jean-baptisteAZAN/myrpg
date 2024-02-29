/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** function : display_all
*/

#include "my.h"
#include "my_rpg.h"

void sub_display_text(main_s *game_s, sfRenderWindow* window)
{
    if (game_s->where_vehicule == -1)
        sfText_setPosition(game_s->ress_s.text_block,
            (sfVector2f){game_s->ress_s.x_view - 20,
                game_s->ress_s.y_view - 40});
    if (game_s->where_vehicule == 1)
        sfText_setPosition(game_s->ress_s.text_block,
            (sfVector2f){game_s->pickup_s.pos_x - 20,
                game_s->pickup_s.pos_y - 40});
    if (game_s->where_vehicule == 2)
        sfText_setPosition(game_s->ress_s.text_block,
            (sfVector2f){game_s->tractor_s->pos_x - 20,
                game_s->tractor_s->pos_y - 40});
    if (game_s->where_vehicule == 3)
        sfText_setPosition(game_s->ress_s.text_block,
            (sfVector2f){game_s->harvest_s->pos_x - 20,
                game_s->harvest_s->pos_y - 40});
    sfRenderWindow_drawText(window, game_s->ress_s.text_block, NULL);
}

void display_text(main_s *game_s, sfRenderWindow* window)
{
    if (game_s->ress_s.display_text_block == 1 && game_s->ress_s.open_map != 1
    && sfClock_getElapsedTime(game_s->ress_s.time_text_block).microseconds <
            700000) {
        sub_display_text(game_s, window);
    }
}

void display_res(main_s *game_s, sfRenderWindow* window)
{
    if (game_s->ress_s.open_map == 0)
        sfRenderWindow_setView(window, game_s->ress_s.view_p);
    else
        sfRenderWindow_setView(window, game_s->ress_s.view_map);
    sfRenderWindow_drawSprite(window, game_s->ress_s.map_01, NULL);
    display_field(game_s);
    sfRenderWindow_drawSprite(window,
        game_s->pickup_s.pickup, NULL);
    sfRenderWindow_drawSprite(window,
        game_s->tractor_s->tractor, NULL);
    sfRenderWindow_drawSprite(window,
        game_s->harvest_s->harvest, NULL);
    if (game_s->where_vehicule == 0)
        sfRenderWindow_drawSprite(window, game_s->player_s->player, NULL);
    sfRenderWindow_drawSprite(window, game_s->ress_s.map_02, NULL);
    display_text(game_s, window);
    display_msg_voisin(game_s);
    display_compter(game_s);
    display_max_recolted(game_s);
}
