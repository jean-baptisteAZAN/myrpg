/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** init_tuto
*/

#include "my.h"
#include "my_rpg.h"

void create_tab_text(main_s *data)
{
    int i = 0;
    data->tuto->tab_text = malloc(sizeof(sfTexture *) * 11);
    for (; path_tuto[i]; i++) {
        data->tuto->tab_text[i] = sfTexture_createFromFile
        (path_tuto[i], NULL);
    }
    data->tuto->tab_text[i] = NULL;
    data->error_message = my_text((text_create){
        .color = sfWhite,
        .font = data->police,
        .text = "Zut, on dirait que votre fichier est corrompus !",
        .position = (sfVector2f) {225, 950},
        .size = 50,
    });
}

void init_tuto(main_s *data)
{
    data->tuto->new = true;
    data->tuto->statement = 0;
    data->tuto->plant = false;
    data->tuto->ready = false;
    data->tuto->recolt = false;
    data->tuto->timing_display = sfClock_create();
    create_tab_text(data);
    data->tuto->panneau = my_sprite((sprite_create) {
        .texture =
        sfTexture_createFromFile(path_tuto[data->tuto->statement], NULL),
        .position = (sfVector2f) {1600, 100},
        .origine = (sfVector2f) {100, 100},
        .color = sfColor_fromRGB(255, 255, 255),
        .rotate = 0,
        .scale = (sfVector2f) {0.3, 0.3},
    });
}
