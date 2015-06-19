##
## Makefile for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
## 
## Made by Alaric
## Login   <degand@epitech.net>
## 
## Started on  Thu Jun 18 16:31:54 2015 Alaric
## Last update Fri Jun 19 15:22:33 2015 Alaric
##

CC=		gcc

SRC=		main.c		\
		colorPixel.c	\
		BmpLoader.c	\

NAME=		zappy

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRC) -o $(NAME) `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_ttf -Wall -Wextra

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean	all

.PHONY:		all	clean	fclean	re
