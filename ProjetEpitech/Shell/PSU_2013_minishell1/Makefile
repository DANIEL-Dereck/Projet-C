##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Mon Jan  6 20:50:51 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra

NAME	= mysh

LIB     = -I Lib/include/ -L Lib/lib -lmy

SRC	= src/main.c \
	src/my_prompt.c \
	src/my_signal.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB) $(CFLAGS)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

