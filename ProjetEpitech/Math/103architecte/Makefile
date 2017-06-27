##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Fri Dec 13 12:53:23 2013 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= 103architecte

CFLAGS	= -Wall -Wextra

LIB     = -I Lib/include/ -L Lib/lib -lmy -lm

SRC	= src/main.c \
	src/my_func.c \
	src/my_usage.c \
	src/my_calc.c \
	src/my_aff.c \
	src/my_coord.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

