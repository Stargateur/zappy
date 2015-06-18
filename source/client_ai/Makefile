##
## Makefile for make in /home/mantez/Projet_2014-2015/PSU/MYIRC
## 
## Made by mantez paul
## Login   <mantez@epitech.net>
## 
## Started on  Tue Apr  7 15:39:46 2015 mantez paul
## Last update Mon Jun 15 12:41:44 2015 amoure_a
##

CPP	=	g++ #-std=gnu -ansi -pedantic

NAME	=	client

SRC	=	main.cpp		\
		Client/Client.cpp	\

OBJ	=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
