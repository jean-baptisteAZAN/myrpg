/*
** EPITECH PROJECT, 2023
** home_save_game.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

int save_map(main_s *data)
{
    if (data->ress_s.img_map_01 == NULL)
        return -1;
    if (!sfImage_saveToFile(data->ress_s.img_map_01, "./save/map.png"))
        return -1;
    return 0;
}

int create_file(void)
{
    FILE *file = fopen("./save/save", "r+");
    if (file == NULL) {
        file = fopen("./save/save", "w+");
        if (file == NULL)
            return -1;
        fclose(file);
    } else {
        fclose(file);
    }
    return 0;
}

int load_info_file(main_s *data, int nbytes, int fd)
{
    char *line;
    for (int i = 1; i <= 19; i++) {
        line = get_information_save(data, i);
        if (line == NULL) {
            close(fd);
            return -1;
        }
        nbytes = my_strlen(line);
        if (write(fd, line, nbytes) != nbytes) {
            close(fd);
            return -1;
        }
        if (write(fd, "\n", 1) != 1) {
            close(fd);
            return -1;
        }
    }
    close(fd);
    return 0;
}

int save_info(main_s *data)
{
    if (create_file() == -1)
        return -1;
    int fd;
    int nbytes = 0;
    fd = open("./save/save", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return -1;
    if (load_info_file(data, nbytes, fd) == -1)
        return -1;
    return 0;
}

// return 0 if no error and -1 if error OR 2 if the time is too short
int save_the_game(main_s *data)
{
    if (sfClock_getElapsedTime(data->ress_s.could_down_save).microseconds <
        20000)
        return 2;
    if (save_map(data) == -1)
        return -1;
    if (save_info(data) == -1)
        return -1;
    sfClock_restart(data->ress_s.could_down_save);
    return 0;
}
