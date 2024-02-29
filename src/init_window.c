/*
** EPITECH PROJECT, 2023
** init
** File description:
** window
*/

#include "my.h"
#include "my_rpg.h"

void alloc_all(main_s *data)
{
    data->player_s = malloc(sizeof(pl_s));
    data->tractor_s = malloc(sizeof(t_s));
    data->menu = malloc(sizeof(menu_s));
    data->menu->but = malloc(sizeof(all_button_s));
    data->menu->settings = malloc(sizeof(set_s));
    data->menu->perso = malloc(sizeof(perso_s));
    data->hun = malloc(sizeof(hunter_s));
    data->menu->help = malloc(sizeof(help_s));
    data->menu_ig = malloc(sizeof(ingame));
    data->info_load = malloc(sizeof(info_game));
    data->load = malloc(sizeof(i_m_l));
    data->go_hunt = malloc(sizeof(go_hunt_s));
    data->inv_s.gun = malloc(sizeof(gun_s));
    data->opps = malloc(sizeof(enn_s));
    data->tuto = malloc(sizeof(tuto_s));
    data->cinematic = malloc(sizeof(cine_s));
    data->endd = malloc(sizeof(end_s));
    data->collis_s = malloc(sizeof(col_s));
}

void init_cinematic(main_s *data)
{
    data->cinematic->display_cine = 0;
    data->cinematic->text_dialogue_women =
    sfTexture_createFromFile("ressources/dialogues/plan_femme.png", NULL);
    data->cinematic->text_dialogue_opp =
    sfTexture_createFromFile("ressources/dialogues/plan_opps.png", NULL);
    data->cinematic->sp_dialogue = sfSprite_create();
    sfSprite_setTexture(data->cinematic->sp_dialogue,
    data->cinematic->text_dialogue_women, sfFalse);
    sfSprite_setScale(data->cinematic->sp_dialogue, (sfVector2f) {1, 0.97});
    data->cinematic->dialo = my_text((text_create) {
        .color = sfWhite,
        .font = data->police,
        .position = (sfVector2f) {200, 800},
        .size = 90,
        .text = "NULL",
    });
    init_but_next(data);
}

bool init_all(main_s *data)
{
    data->info_load->env = -1;
    data->i = 0;
    data->loaded = 0;
    data->verif_loading = 0;
    data->where = 0;
    init_struct_menu_load(data->load);
    if (!init_menu(data))
        return (false);
    init_res(data);
    init_hunter(data);
    init_ig_menu(data);
    inventory_init(data);
    init_go_hunt(data);
    init_ennemy(data);
    init_tuto(data);
    init_animed_fond(data);
    init_cinematic(data);
    return (true);
}

bool init_window(main_s *data)
{
    data->window->background_useless = sfSprite_create();
    data->window->mode = (sfVideoMode) {1920, 1080, 32};
    data->window->game_window = sfRenderWindow_create(data->window->mode,
    "My_Farmer", sfClose, NULL);
    data->window->fullscreen = true; data->verif_ig = 0;
    if ((data->police =
    sfFont_createFromFile("ressources/minecraft_font.ttf")) == NULL)
        return (false);
    sfRenderWindow_setFramerateLimit(data->window->game_window, 60);
    alloc_all(data);
    data->clock_error_load = sfClock_create();
    data->check_load = 0;
    data->player_s->money = 0;
    data->inv_s.verif = false;
    data->inv_s.print_desc = false;
    data->inv_s.print_coin_dsc = false;
    if (init_all(data) == false)
        return (false);
    return (true);
}
