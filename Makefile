##
## Makefile for Makefile in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:09 2015 Antoine Plaskowski
## Last update Tue Jun 16 17:17:20 2015 Antoine Plaskowski
##

SERVER		=	server

CLIENT_AI	=	client_ai

CLIENT_GUI	=	client_gui

CC		?=	gcc

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=

INCLUDE		=	-I include -I include/server -I include/client_ai -I include/client_gui

CFLAGS		+=	-Wall -Wextra -O$(LEVEL)
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS		+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CFLAGS		+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS		+=	-f diagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source.mk
include			source_server.mk
include			source_client_ai.mk
include			source_client_gui.mk

DPD		=	$(SRC:.c=.dpd)

OBJ		=	$(SRC:.c=.o)

DPD_SERVER	=	$(SRC_SERVER:.c=.dpd)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

DPD_CLIENT_AI	=	$(SRC_CLIENT_AI:.c=.dpd)

OBJ_CLIENT_AI	=	$(SRC_CLIENT_AI:.c=.o)

DPD_CLIENT_GUI	=	$(SRC_CLIENT_GUI:.c=.dpd)

OBJ_CLIENT_GUI	=	$(SRC_CLIENT_GUI:.c=.o)

all		:	$(SERVER) $(CLIENT_AI) $(CLIENT_GUI)

$(SERVER)	:	$(OBJ) $(OBJ_SERVER)
			$(CC) $(OBJ) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT_AI)	:	$(OBJ) $(OBJ_CLIENT_AI)
			$(CC) $(OBJ) $(OBJ_CLIENT_AI) -o $(CLIENT_AI) $(LDFLAGS)

$(CLIENT_GUI)	:	$(OBJ) $(OBJ_CLIENT_GUI)
			$(CC) $(OBJ) $(OBJ_CLIENT_GUI) -o $(CLIENT_GUI) $(LDFLAGS)

clean		:
			@$(RM) -f $(OBJ)
			@$(RM) -f $(OBJ_SERVER)
			@$(RM) -f $(OBJ_CLIENT_AI)
			@$(RM) -f $(OBJ_CLIENT_GUI)
			@$(RM) -f $(DPD)
			@$(RM) -f $(DPD_SERVER)
			@$(RM) -f $(DPD_CLIENT_AI)
			@$(RM) -f $(DPD_CLIENT_GUI)

fclean		:	clean
			@$(RM) -f $(SERVER)
			@$(RM) -f $(CLIENT_AI)
			@$(RM) -f $(CLIENT_GUI)

re		:	fclean all

%.dpd		:	%.c
			@$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c

-include		$(DPD)
