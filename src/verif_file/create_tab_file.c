/*
** EPITECH PROJECT, 2023
** create_tab_file.c
** File description:
** create_tab_file
*/

#include "my.h"
#include "my_rpg.h"

char **init_tab_file_one(char **tab_file)
{
    tab_file[0] = "./ressources/dialogues/plan_femme.png";
    tab_file[1] = "./ressources/dialogues/plan_opps.png";
    tab_file[2] = "./ressources/help/help1.png";
    tab_file[3] = "./ressources/hunter/chasseur.png";
    tab_file[4] = "./ressources/hunter/chat.png";
    tab_file[5] = "./ressources/hunter/coin.png";
    tab_file[6] = "./ressources/hunter/hunter_back.png";
    tab_file[7] = "./ressources/hunter/oiseau.png";
    tab_file[8] = "./ressources/hunter/pressE.png";
    tab_file[9] = "./ressources/hunter/viseur.png";
    tab_file[10] = "./ressources/object_inv/gun.png";
    tab_file[11] = "./ressources/res/game/bloc_msg.png";
    tab_file[12] = "./ressources/res/game/compter.png";
    tab_file[13] = "./ressources/res/game/farmer.jpg";
    tab_file[14] = "./ressources/res/game/harvest.png";
    tab_file[15] = "./ressources/res/game/icon_wheat.png";
    tab_file[16] = "./ressources/res/game/map_all.png";
    tab_file[17] = "./ressources/res/game/map_collision.png";
    tab_file[18] = "./ressources/res/game/map_void.png";
    return tab_file;
}

char **init_tab_file_two(char **tab_file)
{
    tab_file[19] = "./ressources/res/game/noise_texture.png";
    tab_file[20] = "./ressources/res/game/pickup.png";
    tab_file[21] = "./ressources/res/game/tractor.png";
    tab_file[22] = "./ressources/tuto/text_01.png";
    tab_file[23] = "./ressources/tuto/text_02.png";
    tab_file[24] = "./ressources/tuto/text_03.png";
    tab_file[25] = "./ressources/tuto/text_04.png";
    tab_file[26] = "./ressources/tuto/text_05.png";
    tab_file[27] = "./ressources/tuto/text_06.png";
    tab_file[28] = "./ressources/tuto/text_07.png";
    tab_file[29] = "./ressources/tuto/text_08.png";
    tab_file[30] = "./ressources/tuto/text_09.png";
    tab_file[31] = "./ressources/tuto/text_10.png";
    tab_file[32] = "./ressources/animed_fond.png";
    tab_file[33] = "./ressources/bouton_backup.png";
    tab_file[34] = "./ressources/bouton_min_selected.png";
    tab_file[35] = "./ressources/bouton_moins.png";
    return tab_file;

}

char **init_tab_file_three(char **tab_file)
{
    tab_file[36] = "./ressources/bouton_plus_selected.png";
    tab_file[37] = "./ressources/bouton_plus.png";
    tab_file[38] = "./ressources/bouton_vierge.jpg";
    tab_file[39] = "./ressources/bouton_vierge2.png";
    tab_file[40] = "./ressources/bouton_vierge3.png";
    tab_file[41] = "./ressources/cmd_img.png";
    tab_file[42] = "./ressources/farmer.png";
    tab_file[43] = "./ressources/fleche_droite.png";
    tab_file[44] = "./ressources/ig_menu.png";
    tab_file[45] = "./ressources/inventaire.png";
    tab_file[46] = "./ressources/menu_modif.png";
    tab_file[47] = "./ressources/minecraft_font.ttf";
    tab_file[48] = "./ressources/music.ogg";
    tab_file[49] = "./ressources/perso_menu.png";
    tab_file[50] = "./ressources/piece.png";
    tab_file[51] = "./ressources/settings_wlp.png";
    tab_file[52] = "./ressources/skin1.png";
    return tab_file;
}

char **create_tab_file(void)
{
    char **tab_file = malloc(sizeof(char *) * 53);
    tab_file = init_tab_file_one(tab_file);
    tab_file = init_tab_file_two(tab_file);
    tab_file = init_tab_file_three(tab_file);
    return tab_file;
}
