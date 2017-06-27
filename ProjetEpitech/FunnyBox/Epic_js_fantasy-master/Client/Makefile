##
## Makefile for Rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
## 
## Made by decouf_m
## Login   <decouf_m@epitech.net>
## 
## Started on  Sat May 10 09:23:25 2014 decouf_m
## Last update Sun May 11 03:58:05 2014 decouf_m
##

CC      =       cc

RM      =       rm -rf

NAME    =       fantasy_client

SRC     =       src/fantasy_client.c \
		src/string.c \

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -I ./include/ -Wall -Wextra

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all
