##
## source.mk for source in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:34 2015 Antoine Plaskowski
## Last update Thu Jun 18 23:55:56 2015 Antoine Plaskowski
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/
PATH_MAP	=	$(PATH_SERVER)map/
PATH_NODE	=	$(PATH_SERVER)node/

SRC_SERVER	+=	$(PATH_SERVER)main.c
SRC_SERVER	+=	$(PATH_SERVER)accept_client.c
SRC_SERVER	+=	$(PATH_SERVER)create_binded_socket.c
SRC_SERVER	+=	$(PATH_SERVER)fd_set.c
SRC_SERVER	+=	$(PATH_SERVER)opt.c
SRC_SERVER	+=	$(PATH_SERVER)cbuf.c
SRC_SERVER	+=	$(PATH_SERVER)manage_select.c
SRC_SERVER	+=	$(PATH_SERVER)client.c
SRC_SERVER	+=	$(PATH_SERVER)parser.c

SRC_SERVER	+=	$(PATH_NODE)first_node.c
SRC_SERVER	+=	$(PATH_NODE)free_node.c
SRC_SERVER	+=	$(PATH_NODE)last_node.c
SRC_SERVER	+=	$(PATH_NODE)len_node.c
SRC_SERVER	+=	$(PATH_NODE)put_node.c
SRC_SERVER	+=	$(PATH_NODE)sup_node_at.c
SRC_SERVER	+=	$(PATH_NODE)sup_node.c

SRC_SERVER	+=	$(PATH_MAP)map.c
