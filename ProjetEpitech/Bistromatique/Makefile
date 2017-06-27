##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Mon Nov 11 11:08:41 2013 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= calc

CFLAGS	= -Llib -lmy -Iinclude/ -Wall -Wextra

SRC	= main.c \
	my_oper.c \
	my_addinf.c \
	my_sousinf.c \
	my_multinf.c \
	my_aff.c \
	my_remptab.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	: 
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

exe	: all clean

re	: fclean all

