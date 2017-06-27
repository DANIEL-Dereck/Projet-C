##
## Makefile for Rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
## 
## Made by decouf_m
## Login   <decouf_m@epitech.net>
## 
## Started on  Sat May 10 09:23:25 2014 decouf_m
## Last update Sun May 11 03:45:50 2014 decouf_m
##

CC      =       cc

RM      =       rm -rf

NAME    =       js_server

SRC     =       src/js_server.c \
		src/my_perror.c \
		src/string.c \
		src/client.c \
		src/client2.c

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
