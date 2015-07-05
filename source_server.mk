##
## source.mk for source in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:34 2015 Antoine Plaskowski
## Last update Sun Jul  5 22:24:34 2015 Alaric
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/
PATH_GRAPHIC	=	$(PATH_SERVER)graphic/
PATH_MAP	=	$(PATH_SERVER)map/
PATH_NODE	=	$(PATH_SERVER)node/

SRC_SERVER	+=	$(PATH_SERVER)main.c
SRC_SERVER	+=	$(PATH_SERVER)int_handler.c
SRC_SERVER	+=	$(PATH_SERVER)accept_client.c
SRC_SERVER	+=	$(PATH_SERVER)create_binded_socket.c
SRC_SERVER	+=	$(PATH_SERVER)fd_set.c
SRC_SERVER	+=	$(PATH_SERVER)option.c
SRC_SERVER	+=	$(PATH_SERVER)circular_buffer.c
SRC_SERVER	+=	$(PATH_SERVER)manage_select.c
SRC_SERVER	+=	$(PATH_SERVER)client.c
SRC_SERVER	+=	$(PATH_SERVER)parser.c
SRC_SERVER	+=	$(PATH_SERVER)game.c
SRC_SERVER	+=	$(PATH_SERVER)utils.c
SRC_SERVER	+=	$(PATH_SERVER)player.c
SRC_SERVER	+=	$(PATH_SERVER)action.c
SRC_SERVER	+=	$(PATH_SERVER)command.c
SRC_SERVER	+=	$(PATH_SERVER)team.c
SRC_SERVER	+=	$(PATH_SERVER)num_client.c
SRC_SERVER	+=	$(PATH_SERVER)size_map.c
SRC_SERVER	+=	$(PATH_SERVER)kill_client.c
SRC_SERVER	+=	$(PATH_SERVER)food.c
SRC_SERVER	+=	$(PATH_SERVER)time_utils.c
SRC_SERVER	+=	$(PATH_SERVER)avance.c
SRC_SERVER	+=	$(PATH_SERVER)droite.c
SRC_SERVER	+=	$(PATH_SERVER)gauche.c
SRC_SERVER	+=	$(PATH_SERVER)voir.c
SRC_SERVER	+=	$(PATH_SERVER)inventaire.c
SRC_SERVER	+=	$(PATH_SERVER)prend.c
SRC_SERVER	+=	$(PATH_SERVER)pose.c
SRC_SERVER	+=	$(PATH_SERVER)expulse.c
SRC_SERVER	+=	$(PATH_SERVER)broadcast.c
SRC_SERVER	+=	$(PATH_SERVER)incantation.c
SRC_SERVER	+=	$(PATH_SERVER)egg.c
SRC_SERVER	+=	$(PATH_SERVER)connect_nbr.c

SRC_SERVER	+=	$(PATH_NODE)first_node.c
SRC_SERVER	+=	$(PATH_NODE)free_node.c
SRC_SERVER	+=	$(PATH_NODE)last_node.c
SRC_SERVER	+=	$(PATH_NODE)len_node.c
SRC_SERVER	+=	$(PATH_NODE)put_node.c
SRC_SERVER	+=	$(PATH_NODE)sup_node_at.c
SRC_SERVER	+=	$(PATH_NODE)sup_node.c

SRC_SERVER	+=	$(PATH_MAP)map.c
SRC_SERVER	+=	$(PATH_MAP)inv.c
SRC_SERVER	+=	$(PATH_MAP)player.c
SRC_SERVER	+=	$(PATH_MAP)player_see.c
SRC_SERVER	+=	$(PATH_MAP)player_see_coords.c
SRC_SERVER	+=	$(PATH_MAP)player_items.c
SRC_SERVER	+=	$(PATH_MAP)player_levelup.c
SRC_SERVER	+=	$(PATH_MAP)player_expulse.c
SRC_SERVER	+=	$(PATH_MAP)map_generate.c
SRC_SERVER	+=	$(PATH_MAP)map_coords.c
SRC_SERVER	+=	$(PATH_MAP)concat.c
SRC_SERVER	+=	$(PATH_MAP)see_find_squares.c

SRC_SERVER	+=	$(PATH_GRAPHIC)BmpLoader.c
SRC_SERVER	+=	$(PATH_GRAPHIC)init.c
SRC_SERVER	+=	$(PATH_GRAPHIC)draw.c
SRC_SERVER	+=	$(PATH_GRAPHIC)draw2.c
SRC_SERVER	+=	$(PATH_GRAPHIC)draw_ppl.c
SRC_SERVER	+=	$(PATH_GRAPHIC)draw_egg.c
SRC_SERVER	+=	$(PATH_GRAPHIC)valid_aff.c
SRC_SERVER	+=	$(PATH_GRAPHIC)input.c
