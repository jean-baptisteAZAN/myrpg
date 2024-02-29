/*
** EPITECH PROJECT, 2023
** home_collision.c
** File description:
** function : home_collision
*/

#include "my.h"
#include "my_rpg.h"

// If return 0 is good or 1 is not good
int home_collision(main_s *data, int y, int x)
{
    if (data->where_vehicule == 0)
        return collision_player(data, y, x);
    if (data->where_vehicule == 1)
        return collision_pickup(data, y, x);
    if (data->where_vehicule == 2)
        return collision_harvest(data, y, x);
    return 0;
}
