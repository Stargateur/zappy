##
## source.mk for source in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:34 2015 Antoine Plaskowski
## Last update Wed Jul  1 07:47:34 2015 Antoine Plaskowski
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/
PATH_GRAPHIC	=	tmpGraph/
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
SRC_SERVER	+=	$(PATH_SERVER)broadcast.c

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
SRC_SERVER	+=	$(PATH_MAP)map_generate.c
SRC_SERVER	+=	$(PATH_MAP)map_coords.c

SRC_SERVER	+=	$(PATH_GRAPHIC)BmpLoader.c
SRC_SERVER	+=	$(PATH_GRAPHIC)init.c
SRC_SERVER	+=	$(PATH_GRAPHIC)draw.c
SRC_SERVER	+=	$(PATH_GRAPHIC)input.c
