##
## Makefile for 102 in 
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Thu Nov 28 13:53:20 2013 daniel_d
## Last update Wed Dec  4 14:21:51 2013 daniel_d
##

CC	= gcc

RM	= rm -f

NAME	= 102chiffrement

OBJ	= $(SRC:.c=.o)

SRC	= main.c \
	kkk.c \

CFLAGS	= -I Lib/include -L Lib/lib/ -lmy

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

exe	: all clean
