##
## Makefile for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
## 
## Made by Alaric
## Login   <degand@epitech.net>
## 
## Started on  Thu Jun 18 16:31:54 2015 Alaric
## Last update Thu Jun 25 16:28:14 2015 Alaric
##

CC=		gcc

SRC=		main.c		\
		colorPixel.c	\
		BmpLoader.c	\
		init.c		\
		draw.c		\
		../source/server/map/map.c	\
		../source/server/map/map_generate.c	\

INCLUDE         =       -I include -I ../include/server

CFLAGS          +=      $(INCLUDE)

NAME=		zappy

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRC) -o $(NAME) -lSDL2-2.0 -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean	all

.PHONY:		all	clean	fclean	re
