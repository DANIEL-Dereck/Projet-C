##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Wed Jan  8 15:09:33 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= 104intersection

CFLAGS	= -Wall -Wextra

LIB     = -I Lib/include/ -L Lib/lib -lmy -lm

SRC	= src/main.c \
	src/my_usage.c \
	src/instersection.c \

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

