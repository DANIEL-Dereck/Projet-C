##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Wed Jan 22 11:31:26 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= 105tore

CFLAGS	= -Wall -Wextra

CFLAGS	+= -I ./Lib/include/ -L ./Lib/lib -lmy -lm

SRC	= src/main.c \
	src/toretue.c \
	src/my_usage.c \
	src/funk.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

