/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <SFML/Window/Event.h>
#include "struct_all.h"

#pragma once


__attribute__((unused))static const char *text_inven[] = {
    " Le fusil est votre meilleur \n atout pour negocier ",
    "votre ble \n aupres du chasseur\n\n chaque amelioration coute\n 20000$",
    "L'argent que vous gagner en \nvendant",
    "votre ble peut vous\npermettre d'ameliorer votre \nfusil et de racheter\n",
    "l'exploitation de votre voisin",
    NULL
};

__attribute__((unused))static const char *path_tuto[] = {
    "./ressources/tuto/text_01.png",
    "./ressources/tuto/text_02.png",
    "./ressources/tuto/text_03.png",
    "./ressources/tuto/text_04.png",
    "./ressources/tuto/text_05.png",
    "./ressources/tuto/text_06.png",
    "./ressources/tuto/text_07.png",
    "./ressources/tuto/text_08.png",
    "./ressources/tuto/text_09.png",
    "./ressources/tuto/text_10.png",
    NULL
};

__attribute__((unused))static const char *txt_dialo[] = {
    " faut qu'on parle ...",
    "Mechante: Tu ne me suffis plus, \nje te quitte pour aller avec le voisin",
    ": OUIG",
    " : Je vais me venger et \n racheter la ferme du voisin !!!",
    ": OUIG OUIG",
    "Mechante: Mon herooo, veux tu redevenir mon mari ?",
    "NNNOOONNNGG !!! tu m'as quitte tant pis pour toi !",
    "Fin du jeu\nProjet realise par\nRomain, Jean-Baptiste et Theo",
    NULL
};

typedef struct {
    sfFont *font;
    sfVector2f position;
    sfColor color;
    const char *text;
    int size;
} text_create;

typedef struct {
    sfVector2f position;
    sfColor color;
    sfVector2f scale;
    float rotate;
    const sfTexture *texture;
    sfVector2f origine;
} sprite_create;

typedef struct {
    sfVector2f position;
    sfVector2f origine;
    int tickness;
    int rad;
    sfColor color;
} circle_create;

typedef struct {
    sfVector2f position;
    sfVector2f size;
    sfColor color;
} button_create;

typedef struct {
    sfRenderWindow *game_window;
    sfVideoMode mode;
    sfEvent event;
    sfTexture *text_useless;
    sfSprite *background_useless;
    sfBool fullscreen;
    int resolution_state;
} window_s;

typedef struct {
    sfSprite *img_back;
    sfSprite *bird;
    sfSprite *curs_sprite;
    sfSprite *coin_img;
    sfSprite * return_game;
    sfText *nb_coin;
    sfText * yes_return;
    sfText *perdu;
    sfText *degs;
    sfTexture *bird_text;
    sfTexture *cursor;
    sfClock *animate_clock;
    sfClock *y_clock;
    sfClock *text_clock;
    sfClock *display_end_time;
    int coin;
    int frame_duck;
    int health;
    bool dead;
    bool tuch;
    bool pass;
    bool finish;
    bool loose;
} hunter_s;

typedef struct {
    sfSprite *perso;
    sfSprite *presse;
    sfSprite *chat;
    sfSprite *button_yes;
    sfSprite *button_no;
    sfText *want_hunt;
    sfText *text_yes;
    sfText *text_no;
    sfText *need_gun;
    sfClock * draw_text_gun;
    bool chat_go_hunt;
    bool print_text;
} go_hunt_s;

typedef struct {
    sfImage *button;
    sfSprite *settings;
    sfSprite *resume;
    sfSprite *play;
    sfSprite *exit;
    sfSprite *button_help;
    sfTexture *texture_play;
    sfTexture *texture_pressed;
    sfTexture *texture_hover;
    int sett_state;
    sfText *play_txt;
    sfText *resume_txt;
    sfText *settings_txt;
    sfText *quit;
    sfText *help_txt;
} all_button_s;

typedef struct {
    sfRectangleShape *sound_bar;
    sfSprite *plus_button;
    sfTexture *plus_select;
    sfSprite *minus_button;
    sfTexture *min_select;
    sfRectangleShape *framerate_bar;
    sfSprite *plus_button_frame;
    sfTexture *plus_select_frame;
    sfSprite *minus_button_frame;
    sfTexture *min_select_frame;
    sfText *volume_nb;
    sfText *nb_fps_txt;
    int nb_fps;
    sfRectangleShape *window_size;
    sfRectangleShape  *command_but;
    sfSprite *resume_button;
    sfRectangleShape *rect_res;
    sfSprite *plus_res;
    sfSprite *min_res;
    sfText *res_txt;
} set_s;

typedef struct {
    sfImage *before_start;
    sfTexture *before_txt;
    sfSprite *before_sprite;
    char *name;
    sfRectangleShape *zone_name;
    sfText *text_zone;
    sfSprite *button_start;
    sfText *txt_strt;
    sfSprite *button_back;
    sfText *txt_back;
    sfSprite *visu_sprite;
} perso_s;

typedef struct {
    sfTexture *back_txt;
    sfSprite *sprite_back;
    sfSprite *back_button;
    sfText *txt_back;
} help_s;

typedef struct {
    sfImage *my_menu;
    sfTexture *texture_menu;
    sfTexture *settings_texture;
    sfTexture *texture_cmd;
    sfSprite *sprite_menu;
    sfSprite *sprite_cmd;
    sfSprite *back_button;
    sfSprite *fond_animed; // 5 frames
    all_button_s *but; // free done
    set_s *settings;
    perso_s *perso;
    help_s *help;
    sfText *txt_back;
    int pos_fond_animed; // De 0 à 5
    sfClock *time_fond_animed;
} menu_s;

//////////////////////////////////////////////////////////
////////////////////////// GAME //////////////////////////
//////////////////////////////////////////////////////////

    ////////////////////////////////////////
    /////////////// VEHICULE ///////////////
    ////////////////////////////////////////

    typedef struct harvest_s{
        sfSprite *harvest;
        sfTexture *texture_harvest;
        int pos_x;
        int pos_y;
        float speed_x;
        float speed_y;
        float speed; // vitesse
        float speed_limit; // Vitesse MAX
        sfClock *t_rotate;
        sfClock *t_speed;
        int sens; // 1 - 7 (7 possibilities)
    } c_s;

    typedef struct pickup_s{
        sfSprite *pickup;
        sfTexture *texture_pickup;
        float pos_x;
        float pos_y;
        float speed_x;
        float speed_y;
        float speed; // vitesse
        float speed_limit; // Vitesse MAX
        sfClock *t_rotate;
        sfClock *t_speed;
        int sens; // 1 - 7 (7 possibilities)
    } pi_s;

    typedef struct tractor_s{
        sfSprite *tractor;
        sfTexture *texture_tractor;
        int pos_x;
        int pos_y;
        float speed_x;
        float speed_y;
        float speed; // vitesse
        float speed_limit; // Vitesse MAX
        sfClock *t_rotate;
        sfClock *t_speed;
        int sens; // 1 - 7 (7 possibilities)
    } t_s;


typedef struct player_s{
    sfSprite *player;
    sfClock *time_sprite;
    sfClock *time_moove;
    int frame_player; // 1 - 3
    int sens; // 1 - 4 (4 possibilities)
    int moove_on_off;
    float pos_p_x;
    float pos_p_y;
    float speed;
    int exp; // INFO
    char *name; // INFO
    int money; // INFO
    int gun_xp; // 1 à 3
} pl_s;

typedef struct {
    sfSprite *gun;
    sfSprite *gun_cpy;
    int lvl;
    bool find;
} gun_s;

typedef struct inv_s{
    sfSprite *coin;
    sfText *nb_coin;
    gun_s *gun;
    sfImage *img_inv;
    sfTexture *txt_inv;
    sfSprite *sprite_txt;
    bool verif;
    sfText *txt_desc_inv;
    bool print_desc;
    sfSprite *coin_cpy;
    sfText *desc_coin;
    sfText *nb_coin_inv;
    bool print_coin_dsc;
    int nb_recolted; // Blée de récolté
    sfText *text_nb_recolted;
    sfRectangleShape *back_text_recolted;
    sfSprite *icon_recolted;
    sfSprite *button_boost;

    int recolted_is_max; // If = 1 -> display: time_recolted_max
    sfClock *time_recolted_max;
    sfText *recolted_max;
    sfRectangleShape *rect_lvl_riffle;
    sfText *nb_lvl_riffle;
    sfSprite *sprite_ble;
    sfSprite *cpy_ble;
    sfText *text_ble;
    sfText *nb_ble;
    sfBool prin_ble;
} i_s;

typedef struct npc_s{
    int price_wheat;
    int price_rapeseed;
    int price_oarley;
    int pickup_is_buy;
    int tractor_is_buy;
    sfText *name;
    sfText *msg_voisin_money_good;
    sfSprite *button_voisin;
    sfText *msg_voisin;
    sfSprite *bloc_msg_voisin;
} n_s;

typedef struct ress_s {
    sfView *view_p;
    sfView *view_resize;
    sfImage *img_map_01;
    sfTexture *textu_map_01;
    sfSprite *map_01;
    sfSprite *map_02;
    sfSprite **noise;
    sfColor dirt; // terre
    sfColor plowed; // planté
    sfColor plowed_p; // planté +
    sfColor harvest; // prêt a récolé
    sfColor harvest_f; // Fini de récolté
    int **size_fied;
    int nb_fields;
    sfClock *time;
    sfClock *colddown_enter_vehicule;
    sfClock *clock_open_map;
    int open_map; // if == 1 map is open
    sfView *view_map;
    float x_view;
    float y_view;
    sfClock *saison; // Time for maturation culture
    int time_saison; // Time for pass maturation culture
    sfColor color_tmp; // Color tmp for no allocation memoire
    sfText *text_block; // Text impossible leave vehicule
    int display_text_block; // 1 for display and 0 for not display
    sfClock *time_text_block;
    sfSprite *compter; // Compter + compte all vehicule
    sfRectangleShape *rect_compter; // Eguille de compter
    sfClock *could_down_save;
    int load; // If = 1 is load;
    sfClock *could_downn_tab;
} r_s;

typedef struct {
    sfImage *menu_ig_img;
    sfTexture *menu_ig_txt;
    sfSprite *ig_menu_spr;
    sfSprite *button_sav;
    sfText *txt_sav;
    sfSprite *button_load;
    sfText *txt_load;
    sfSprite *button_settings;
    sfText *txt_settings;
    sfSprite *piece_spr;
    sfText *money_compt;
    sfSprite *money_slot;
    sfSprite *exit_but;
} ingame;

typedef struct collis_s {
    sfImage *map_collis;
    sfSprite *sprite_map_collis; // For DEBUG
    sfColor is_good;
    int *pickup;
    int *tractor;
    int *harvest;
} col_s;

typedef struct {
    sfSprite *opp;
}enn_s;

typedef struct {
    bool new;
    bool plant;
    bool ready;
    bool recolt;
    sfSprite *panneau;
    sfTexture ** tab_text;
    int statement;
    sfClock *timing_display;
} tuto_s;

typedef struct {
    sfTexture *text_dialogue_women;
    sfTexture *text_dialogue_opp;
    sfSprite *sp_dialogue;
    sfText *dialo;
    int display_cine;
    sfSprite *button_next;
} cine_s;

typedef struct {
    sfSprite *background;
} end_s;

//////////////////////////////////////////////////////////
////////////////////////// MAIN //////////////////////////
//////////////////////////////////////////////////////////

typedef struct main_t {
    int verif_ig;
    window_s *window; // free fait
    pi_s pickup_s; // free fait
    c_s *harvest_s; // free fait
    t_s *tractor_s; // free fait
    pl_s *player_s; // free fait
    col_s *collis_s; // free fait
    hunter_s *hun; // free fait
    r_s ress_s; // free fait
    i_s inv_s; // free commences
    n_s npc_s; // free fait
    enn_s *opps; // free fait
    go_hunt_s *go_hunt; // free fait
    menu_s *menu; // free fait
    ingame *menu_ig; // free fait
    sfVector2f mouse_pos;
    sfMusic *music; // free fait
    end_s *endd; // free fait
    float volume;
    int where; // 0 -> game | 1 -> map | 2 -> fight | ??? // -1 -> LEAVE
    int where_vehicule; // -1 -> spec|0 -> perso|1 -> pick|2 -> tract|3 -> harv
    sfFont *police; // free fait
    info_game *info_load; // free fait
    i_m_l *load; // free fait
    tuto_s *tuto; // free fait
    cine_s *cinematic; // free fait
    int i;
    int loaded;
    sfText *error_message; // free fait
    sfClock *clock_error_load; // free fait
    int check_load;
    int verif_loading;
} main_s;


bool init_window(main_s *data);
void update_window(main_s *data);
void display_window(main_s *data);
bool init_menu(main_s *data);
sfSprite *my_sprite(sprite_create sprite);
sfText *my_text(text_create text);
sfCircleShape *my_circle(circle_create circle);
sfRectangleShape *my_rectangle(button_create button);
void get_name(main_s *data);
void generate_sprite_buttons(main_s *data);
void init_txt(main_s *data);
void is_in_settings(main_s *data);
void display_buttons_status(main_s *data);
void display_settings(main_s *data);
void init_settings_frame(main_s *data);
void init_settings_params(main_s *data);
void min_button_fps(main_s *data);
void plus_button_frame(main_s *data);
void init_start_menu(main_s *data);
void is_in_start(main_s *data);
void display_start_menu(main_s *data);
void display_all(main_s *data, sfRenderWindow* window);
void display_res(main_s *data, sfRenderWindow* window);
void change_display_window(main_s *data);
int sub_verif_info_in_load(char *str, int n);

// Verif_file:
    int verif_file(void);
    char **create_tab_file(void);

// Message voisin:
    int init_msg_voisin(main_s *data);
    void display_msg_voisin(main_s *data);

// Function save/load party:
    int save_the_game(main_s *data);
    int load_the_game(main_s *data);
    int save_info(main_s *data);
    char *get_information_save(main_s *data, int line);
    int load_info_in_struct(main_s *data, char *file);
    int verif_info_in_load(char *str, int n);
    int suite_verif_info_where_name(char *str);
    void load_line_ten(main_s *data, char *str, int n);
    void load_line_eighteen(main_s *data, char *str, int n);
    void finish_load(main_s *data);
    int load_info(main_s *data);
    int verif_file_is_good(void);
    int load_map(main_s *data);

// Recolted:
    void init_display_recolted(main_s *game_s);
    void display_recolted(main_s *data);
    void change_position_display_recolted(main_s *data);

// Animed fond home:
    void init_animed_fond(main_s *data);
    void pass_frame_animed_fond(main_s *data);
    void draw_frame_animed_fond(main_s *data);

// Collision:
    void init_collision(main_s *data);
    int home_collision(main_s *date, int y, int x);
    int collision_player_map(main_s *data, int y, int x);
    // Vehicule:
        int collision_player(main_s *data, int y, int x);
        int collision_pickup(main_s *data, int y, int x);
        int collision_tractor(main_s *data, int y, int x);
        int collision_harvest(main_s *data, int y, int x);
    // Get collision vehicule:
        int *get_collision_pickup(main_s *data);
        int *get_collision_tractor(main_s *data);
        int *get_collision_harvest(main_s *data);

// Periph:
    void periph_basic(main_s *game_s);

// Periph vehicule:
    int periph_vehicule(main_s *data);

// Pickup:
    int periph_pickup(main_s *game_s);
    void move_back_pickup(main_s *data, sfRenderWindow *window);
    void turn_pickup_right(main_s *data);
    void turn_pickup_left(main_s *data);

// Fonction CSFML:
    sfSprite* init_fond(char *image);
    int verif_zone(int* zone, sfRenderWindow* window_r);
    int verif_zone_point(int* zone, int x, int y);
// HUNTER function
    void anime_duck(main_s *date);
    void is_in_hunter(main_s *data);
    void init_hunter(main_s *data);
    void display_hunter_game(main_s *data);
    void reset_all(main_s *data);
    void sub_display_chat_hunt(main_s *data);


// Fonction display:
    void display_field(main_s *game_s);

// Init struct:
    void init_res(main_s *data);
    void init_vehicule(main_s *data);
    void home_init_field(main_s *data);
    void resume_but_rect(main_s *data);
    void home_create_field(main_s *data);

// Periph:
    void periph_home(main_s *game_s, sfEvent act);
    int periph_moove(main_s *data, sfEvent act);

// Periph vehicule:
    int periph_vehicule(main_s *data);

// Compter vehicule:
    void init_compter(main_s *data);
    void display_compter(main_s *data);

// Pickup:
    void mooving_pickup(main_s *game_s, int y, int x);
    void move_forward_pickup(main_s *data, float speed, int sens);
    void suite_move_forward_pickup(main_s *game_s, float speed);
    void brake_forward_pickup(main_s *data, float speed_m);
    void suite_brake_forward_pickup(main_s *game_s, float speed);
    void move_back_pickup(main_s *data, sfRenderWindow *window);
    void turn_pickup_right(main_s *data);
    void turn_pickup_left(main_s *data);
    void turn_sprite(main_s *game_s);
    void turn_01(main_s *game_s);
    void turn_02(main_s *game_s);
    void turn_03(main_s *game_s);
    void home_plowed(main_s *data);

// Tractor:
    void mooving_tractor(main_s *game_s, int y, int x);
    int periph_tractor(main_s *data);
    void move_forward_tractor(main_s *data, float speed, int sens);
    void suite_move_forward_tractor(main_s *game_s, float speed);
    void brake_forward_tractor(main_s *data, float speed_m);
    void suite_brake_forward_tractor(main_s *game_s, float speed);
    void move_back_tractor(main_s *data, sfRenderWindow *window);
    void turn_tractor_right(main_s *data);
    void turn_tractor_left(main_s *data);
    void turn_sprite_tractor(main_s *game_s);
    void turn_01_tractor(main_s *game_s);
    void turn_02_tractor(main_s *game_s);
    void turn_03_tractor(main_s *game_s);
    // Plowed:
        void plowed_tractor(main_s *data, int x, int y);
        void plowed_0(main_s *data);
        void plowed_1(main_s *data);
        void plowed_2(main_s *data);
        void plowed_3(main_s *data);
        void plowed_4(main_s *data);
        void plowed_6(main_s *data);
        void display_max_recolted(main_s *data);
        void init_max_field(main_s *data);

// Harvester:
    void mooving_harvest(main_s *game_s, int y, int x);
    int periph_harvest(main_s *data);
    void move_forward_harvest(main_s *data, float speed, int sens);
    void suite_move_forward_harvest(main_s *game_s, float speed);
    void brake_forward_harvest(main_s *data,
    float speed_m);
    void suite_brake_forward_harvest(main_s *game_s, float speed);
    void move_back_harvest(main_s *data, sfRenderWindow *window);
    void turn_harvest_right(main_s *data);
    void turn_harvest_left(main_s *data);
    void turn_sprite_harvest(main_s *game_s);
    void turn_01_harvest(main_s *game_s);
    void turn_02_harvest(main_s *game_s);
    void turn_03_harvest(main_s *game_s);
    // Harved:
        void harved_harvest(main_s *data, int x, int y);
        void harved_0(main_s *data);
        void harved_1(main_s *data);
        void harved_2(main_s *data);
        void harved_3(main_s *data);
        void harved_4(main_s *data);
        void harved_6(main_s *data);
        void home_harved(main_s *data);

// Player:
    int home_periph_player(main_s *game_s);
    void next_sprite_player(main_s *game_s);
    // Periph:
        void moove_player_up(main_s *game_s);
        void moove_player_down(main_s *game_s);
        void moove_player_right(main_s *game_s);
        void moove_player_left(main_s *game_s);
        void verif_moove_is_good_player(main_s *game_s, int y, int x);

        void anime_sprite_player_up(main_s *game_s);
        void anime_sprite_player_down(main_s *game_s);
        void anime_sprite_player_right(main_s *game_s);
        void anime_sprite_player_left(main_s *game_s);
        void movement_player(main_s *data);

// My_fonction CSFML:
    int verif_zone(int* zone, sfRenderWindow* window_r);
    int verif_zone_point(int* zone, int x, int y);
    void mooving_view(main_s *game_s, int y, int x);

// Fonction:
    void muration(main_s *data);
    char* int_pass_char(int nbr);
    char *int_to_char(int n);
    int	my_getnbr(char const *str);


/////////////// FONCTION JB MENU ///////////////
    // help
        void display_help(main_s *data);
        void is_in_help_one(main_s *data);
        bool init_help_menu(main_s *data);
        void help_button(main_s *data);

    //ig menu
        void init_ig_menu(main_s *data);
        void display_ig_menu(main_s *data);
        void change_display_window(main_s *data);
        void command_menu(main_s *data);
        void cmd_but(main_s *data);
        void ig_menu_but(main_s *data);
        void button_command(main_s *data);
        void plus_button_sound(main_s *data);
        void free_all(main_s *data);
        void init_spec(main_s *data);

    //loading_screen
        void menu_loading(main_s *data, sfRenderWindow *window);
        void menu_loading_display(sfRenderWindow *window, main_s *data,
            i_m_l *info_menu_loading);
        void init_struct_menu_load(i_m_l *info_menu_loading);

    //go hunt
        void sub_go_hunt(main_s *data);
        void inventory_init(main_s *data);
        void verif_inven(main_s *data);
        void disp_go_hun(main_s *data);
        void status_button_yes(main_s *data);
        void status_button_no(main_s *data);
        void end_game_win(main_s *data);
        void end_game_loose(main_s *data);
        void init_go_hunt(main_s *data);

    //ennemy
        void init_ennemy(main_s *data);
        void disp_opps(main_s *data);

    //inv
        void display_inv(main_s *data);
        void check_coin_press_inv(main_s *data);
        void update_inv(main_s *data);

    // tuto
    void display_all_tuto(main_s *data);
    void update_all_tuto(main_s *data);
    void init_tuto(main_s *data);
    void take_gun(main_s *data);

//handle event
void init_cmd_menu(main_s *data);
void handle_pressed(main_s *data);
void update_mouse_position(main_s *data);
void handle_released(main_s *data);
void load_game_but(main_s *data);
void save_game_but(main_s *data);
void exit_but_ig(main_s *data);
// cinematic
void display_cinematic(main_s *data);
void init_but_next(main_s *data);
void update_dialo(main_s *data);
void free_menu(main_s *data);
void free_go_hun(main_s *data);
//slider
void init_slider_rgb(main_s *data);
void update_sliders(main_s *data);
void free_loading_bar(main_s *data);
void init_lvl_inven(main_s *data);
void init_desc_coin(main_s *data);

//end
void happy_end(main_s *data);
void update_end(main_s *data);
void sub_display_msg(main_s *data);
void free_harvest(main_s *data);
void sub_sprite_gene(main_s *data);
char *get_information_harvest(main_s *data, int line);
