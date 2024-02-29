################################################################################
############################# 📁 DOCUMENTATION 📁 ##############################
################################################################################


Documentation pour la sauvegarde et chargement des parties.
  2 fichiers obligatoire:
    - ./save/map.png
    - ./save/save


Information dans save:
________________________________________________________________________________
Lin| valeur dans la structure   | Commentaire valeur                  | TYPE

    # INFO PLAYER
1  | data->where_vehicule;      ## Position où es le joeur de (0 à 3) # INT
2  | data->player_s->name;      ## Nom du joeur                       # char *
3  | data->player_s->exp;       ## Nombre d'xp du joeur               # INT > 0
4  | data->player_s->money;     ## Argent du joeur                    # INT >= 0
5  | data->player_s->gun_xp;    ## XP joeur chasseur                  # INT >= 0
6  | data->player_s->pos_p_x;   ## Position joeur X (size map)        # FLOAT
7  | data->player_s->pos_p_y;   ## Position joeur X (size map)        # FLOAT
8  | data->inv_s->nb_recolted;  ## Nombre de blée récolté (nb >= 10)  # INT
9  | data->player_s->gun_xp;    ## Niveau du fusil (1, 2 ou 3)        # INT
10 | data->inv_s->gun_s->find;  ## Si le fusil a été trouvé           # INT


    # INFO PICKUP
11 | data->pickup_s.pos_x;     ## Position pickup (size map)         # FLOAT
12 | data->pickup_s.pos_y;     ## Position pickup (size map)         # FLOAT
13 | data->pickup_s.sens;      ## Sens pickup (0 à 7)                # INT

    # INFO HARVEST
14 | data->harvest_s->pos_x;    ## Position tracteur (size map)       # FLOAT
15 | data->harvest_s->pos_y;    ## Position tracteur (size map)       # FLOAT
16 | data->harvest_s->sens;      ## Sens tracteur (0, 2, 4, 6)        # INT

    # INFO TRACTOR
17 | data->tractor_s->pos_x;    ## Position moissoneuse (size map)    # FLOAT
18 | data->tractor_s->pos_y;    ## Position moissoneuse (size map)    # FLOAT
19 | data->tractor_s->sens;     ## Sens moissoneuse (0, 2, 4, 6)      # INT
