##
## Makefile for colle2 in /home/daniel_d/colle2-daniel_d
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Tue May  6 14:02:58 2014 daniel_d
## Last update Tue May  6 17:39:05 2014 gautie_a
##

CC	= gcc

RM	= rm -f

NAME	= calculator

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I include/ -g3

SRC	= src/main.c \
	src/colle2.c \
	src/my_lib.c \
	src/colle_op.c \
	src/verif.c \
	src/my_str_contains.c \
	src/funk.c

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
