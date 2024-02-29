/*
** EPITECH PROJECT, 2023
** load_info_in_struct.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

int nb_line_is_good_load(char *str)
{
    int nb_line = 0;
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == '\n')
            nb_line++;
    }
    if (nb_line != 19)
        return -1;
    return 0;
}

void sub_load_lien_ten(main_s *data, char *str, int n)
{
    if (n == 0)
        data->where_vehicule = my_getnbr(str);
    if (n == 1)
        data->player_s->name = str;
    if (n == 2)
        data->player_s->exp = my_getnbr(str);
    if (n == 3)
        data->player_s->money = my_getnbr(str);
    if (n == 4)
        data->player_s->gun_xp = my_getnbr(str);
}

void load_line_ten(main_s *data, char *str, int n)
{
    if (n >= 0 && n <= 4)
        sub_load_lien_ten(data, str, n);
    if (n == 5)
        data->player_s->pos_p_x = my_getnbr(str);
    if (n == 6)
        data->player_s->pos_p_y = my_getnbr(str);
    if (n == 7)
        data->inv_s.nb_recolted = my_getnbr(str);
    if (n == 8)
        data->player_s->gun_xp = my_getnbr(str);
    if (n == 9) {
        if (str[0] == '1')
            data->inv_s.gun->find = true;
        else
            data->inv_s.gun->find = false;
    }
}

void load_line(main_s *data, char *str, int n)
{
    if (n >= 0 && n <= 9)
        load_line_ten(data, str, n);
    if (n >= 10 && n <= 19)
        load_line_eighteen(data, str, n);
}

int load_info_in_struct(main_s *data, char *file)
{
    if (nb_line_is_good_load(file) == -1)
        return -1;
    char **tab_file = my_str_to_word_array(file, '\n');
    for (int n = 0; n < 19; n++) {
        if (verif_info_in_load(tab_file[n], n) == -1) {
            my_printf("ERROR LOAD LINE %i -> %s\n", n, tab_file[n]);
            return -1;
        }
        load_line(data, tab_file[n], n);
    }
    return 0;
}
