##
## Makefile for Makefile in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:09 2015 Antoine Plaskowski
## Last update Tue Jun 16 16:38:22 2015 Antoine Plaskowski
##

NAME		=	zappy

CC		?=	gcc

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=

INCLUDE		=	-I include

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

DPD		=	$(SRC:.c=.dpd)

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean		:
			@$(RM) -f $(OBJ)
			@$(RM) -f $(DPD)

fclean		:	clean
			@$(RM) -f $(NAME)

re		:	fclean all

%.dpd		:	%.c
			@$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c

-include		$(DPD)
