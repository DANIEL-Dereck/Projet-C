##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Sun Feb 16 21:52:47 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LIB     = Lib

EXEC    =$(LIB)/Lib

NAME	= allum1

CFLAGS	+= -Wall -Wextra

CFLAGS	+= -I ./Lib/include/ -L ./Lib/lib -lmy

SRC	= src/main.c \
	src/alumain.c \
	src/alumplay.c \
	src/alumcounteur.c \
	src/alumintel.c \
	src/alumbrain.c \

OBJ	= $(SRC:.c=.o)

all	: $(EXEC) $(NAME)

$(EXEC)	: 
	@(cd $(LIB) && $(MAKE))

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

.PHONY	: all clean fclean re
