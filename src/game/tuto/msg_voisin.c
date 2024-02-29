/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** display_tuto
*/

#include "my.h"
#include "my_rpg.h"

int init_msg_voisin_win(main_s *data)
{
    data->npc_s.msg_voisin_money_good = sfText_create();
    sfFont *font =
    sfFont_createFromFile("./ressources/minecraft_font.ttf");
    sfText_setString(data->npc_s.msg_voisin_money_good,
    "Salut\nJe vois que tu as gagne beaucoup d'argent\n \
depuis notre derniere discussion.\nVeux-tu racheter ma ferme ?\n \
(Appuie sur R pour valider)");
    sfText_setPosition(data->npc_s.msg_voisin_money_good,
    (sfVector2f){305, 315});
    sfText_setFont(data->npc_s.msg_voisin_money_good, font);
    sfText_setCharacterSize(data->npc_s.msg_voisin_money_good, 10);
    sfText_setScale(data->npc_s.msg_voisin_money_good, (sfVector2f)
    {0.25, 0.25});
    sfText_setPosition(data->npc_s.name, (sfVector2f){313, 315});
    sfText_setColor(data->npc_s.msg_voisin_money_good, sfBlack);
    data->npc_s.bloc_msg_voisin =
        init_fond("./ressources/res/game/bloc_msg.png");
    sfSprite_setPosition(data->npc_s.bloc_msg_voisin, (sfVector2f){300, 322});
    sfSprite_setScale(data->npc_s.bloc_msg_voisin, (sfVector2f){0.08, 0.08});
    return 0;
}

void init_button_voisin(main_s * data)
{
    sfTexture *texture = sfTexture_createFromFile("./ressources/yes.png", NULL);
    data->npc_s.button_voisin = my_sprite((sprite_create) {
        .color = sfColor_fromRGB(255, 255, 255),
        .position = (sfVector2f) {310, 330},
        .scale = (sfVector2f) {0.05, 0.05},
        .origine = (sfVector2f) {0, 0},
        .texture = texture,
    });
    sfTexture_destroy(texture);
}

int init_msg_voisin(main_s *data)
{
    data->npc_s.msg_voisin = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/minecraft_font.ttf");
    sfText_setString(data->npc_s.msg_voisin, "Tu te prends pour qui ?\n \
Reviens me voir quand tu auras assez\nd'argent pour racheter ma ferme.\n \
Ton ex-femme te passe le bonjour. Bisous <3");
    sfText_setPosition(data->npc_s.msg_voisin, (sfVector2f){305, 325});
    sfText_setFont(data->npc_s.msg_voisin, font);
    sfText_setCharacterSize(data->npc_s.msg_voisin, 10);
    sfText_setScale(data->npc_s.msg_voisin, (sfVector2f){0.25, 0.25});
    sfText_setColor(data->npc_s.msg_voisin, sfBlack);
    data->npc_s.name = sfText_create();
    sfText_setString(data->npc_s.name, "Error");
    sfText_setPosition(data->npc_s.name, (sfVector2f){315, 325});
    sfText_setFont(data->npc_s.name, font);
    sfText_setCharacterSize(data->npc_s.name, 10);
    sfText_setScale(data->npc_s.name, (sfVector2f){0.25, 0.25});
    sfText_setColor(data->npc_s.name, sfBlack);
    init_button_voisin(data);
    return init_msg_voisin_win(data);
}

void display_yes(main_s *data)
{
    sfVector2f pos = sfSprite_getPosition(data->player_s->player);
    if ((pos.x > 290 && pos.x < 360) && (pos.y > 300 && pos.y < 380) &&
    data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyR) {
        sfRenderWindow_setView(data->window->game_window,
        data->ress_s.view_map);
        data->where = 8;
    }
}

void display_msg_voisin(main_s *data)
{
    if (data->ress_s.open_map == 1)
        return;
    if (data->player_s->money > 140000) {
        sfSprite_setScale(data->npc_s.bloc_msg_voisin,
            (sfVector2f){0.08, 0.15});
        sfSprite_setPosition(data->npc_s.bloc_msg_voisin,
        (sfVector2f){300, 310});
        sfRenderWindow_drawSprite(data->window->game_window,
            data->npc_s.bloc_msg_voisin, NULL);
        sfRenderWindow_drawText(data->window->game_window,
            data->npc_s.msg_voisin_money_good, NULL);
        sfText_setString(data->npc_s.name, data->player_s->name);
        sfRenderWindow_drawText(data->window->game_window,
            data->npc_s.name, NULL);
        display_yes(data);
    } else {
        sub_display_msg(data);
    }
}
