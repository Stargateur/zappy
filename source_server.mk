##
## source.mk for source in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:34 2015 Antoine Plaskowski
## Last update Thu Jun 18 21:18:10 2015 Antoine Plaskowski
##

PATH_SRC	=	source/
PATH_SERVER	=	$(PATH_SRC)server/

SRC_SERVER	+=	$(PATH_SERVER)main.c
SRC_SERVER	+=	$(PATH_SERVER)accept_client.c
SRC_SERVER	+=	$(PATH_SERVER)create_binded_socket.c
SRC_SERVER	+=	$(PATH_SERVER)fd_set.c
SRC_SERVER	+=	$(PATH_SERVER)parse_opt.c
SRC_SERVER	+=	$(PATH_SERVER)cbuf.c
