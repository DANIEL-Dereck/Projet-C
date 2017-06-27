##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Sun Dec  8 11:43:14 2013 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= BSQ

CFLAGS	= -Wall -Wextra

LIB     = -I Lib/include/ -L Lib/lib -lmy -L /usr/lib64 -lmlx_$(HOSTTYPE) -L /usr/lib64/X11 -lXext -lX11

SRC	= main.c \

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

