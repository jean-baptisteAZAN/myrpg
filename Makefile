##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

SRC	=	src/main.c \
		src/init_window.c \
		src/update_window.c \
		src/display_window.c \
		src/menu/menu_init.c \
		src/utils/generate_params.c \
		src/menu/animed_fond.c \
		src/menu/generate_buttons.c \
		src/menu/settings.c \
		src/menu/display_menu1.c \
		src/menu/init_sett_volume.c \
		src/menu/init_sett_frame.c \
		src/menu/display_frame_sett.c \
		src/menu/start_menu.c \
		src/update_start.c \
		src/display_start.c \
		src/game/init/init_home_game.c \
		src/game/init/init_vehicule.c \
		src/game/init/init_field.c \
		src/game/init/create_field.c \
		src/game/init/init_collision.c \
		src/game/periph/collision/home_collision.c \
		src/game/periph/collision/collision_player.c \
		src/game/periph/collision/collision_pickup.c \
		src/game/periph/collision/collision_tractor.c \
		src/game/periph/collision/collision_harvester.c \
		src/game/periph/collision/get_collision_vehicule.c \
		src/game/display/display_res.c \
		src/game/display/display_field.c \
		src/game/periph/periph_moove.c \
		src/game/periph/periph_vehicule.c \
		src/game/periph/vehicule/pickup/periph_pickup.c \
		src/game/periph/vehicule/pickup/move_pickup.c \
		src/game/periph/vehicule/pickup/turn_pickup.c \
		src/game/periph/vehicule/pickup/fonction_pickup.c \
		src/game/periph/vehicule/tractor/periph_tractor.c \
		src/game/periph/vehicule/tractor/move_tractor.c \
		src/game/periph/vehicule/tractor/turn_tractor.c \
		src/game/periph/vehicule/tractor/fonction_tractor.c \
		src/game/periph/vehicule/tractor/home_plowed.c \
		src/game/periph/vehicule/tractor/function_plowed_simple.c \
		src/game/periph/vehicule/harvester/periph_harvest.c \
		src/game/periph/vehicule/harvester/move_harvest.c \
		src/game/periph/vehicule/harvester/turn_harvest.c \
		src/game/periph/vehicule/harvester/fonction_harvest.c \
		src/game/periph/vehicule/harvester/home_harved.c \
		src/game/periph/vehicule/harvester/function_harved_simple.c \
		src/game/periph/vehicule/compter.c \
		src/game/periph/maturation.c \
		src/game/function_game.c \
		src/game/function_display_recolted.c \
		src/game/periph/home_periph.c \
		src/game/hunter/hunter.c \
		src/game/hunter/display_hunter.c \
		src/game/hunter/init_hunter.c \
		src/game/periph/player/home_periph_player.c \
		src/game/periph/player/moove_player.c \
		src/game/periph/player/animed_sprite_player.c \
		src/menu/help_button.c \
		src/menu/display_help.c \
		src/menu/init_menu_help.c \
		src/game/hunter/animated_duck.c \
		src/game/hunter/display_end_game.c \
		src/menu/ig_menu.c \
		src/menu/display_ig_men.c \
		src/menu/command_menu.c \
		src/menu/sound_but.c \
		src/free_all.c \
		src/menu/init_spec_ig_menu.c \
		src/game/inventory/inventory_init.c \
		src/game/go_hunt/ini_go.c \
		src/game/go_hunt/disp_go_hunt.c \
		src/menu/menu_loading/init_loading.c \
		src/menu/menu_loading/loading_display.c \
		src/menu/menu_loading/menu_loading.c \
		src/game/go_hunt/button_go_hunt.c \
		src/game/ennemy/init_enn.c \
		src/game/ennemy/display_opp.c \
		src/game/inventory/display_inv.c \
		src/game/tuto/update_tuto.c \
		src/game/tuto/display_tuto.c \
		src/game/tuto/init_tuto.c \
		src/game/inventory/disp_coin_txt.c \
		src/game/save_game/home_save_game.c \
		src/game/save_game/save_info.c \
		src/game/load_game/home_load_game.c \
		src/game/load_game/load_file_game.c \
		src/game/load_game/verif_info.c \
		src/handle_event.c \
		src/menu/load_but.c \
		src/game/inventory/update_inv.c \
		src/menu/cinematic.c \
		src/game/tuto/msg_voisin.c \
		src/free_all_sub.c \
		src/game/periph/player/movement_player.c \
		src/game/inventory/lvl_riffle.c \
		src/game/load_game/sub_load_the_game.c \
		src/game/happy_end_game/display_end_game.c \
		src/game/happy_end_game/update_end.c \
		src/verif_file/create_tab_file.c \
		src/verif_file/verif_file.c \
		src/free_vehicule_s.c \

NAME	=	my_rpg

OBJ	= $(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -L./lib/my/ -lmy -I./include/

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

all: $(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

debug:
	cd lib/my && make
	gcc -g $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) lib/my/libmy.a
	cd lib/my && make fclean
	rm -f libmy.a


re: fclean all
