##
## Makefile for Makefile in /home/daniel_d/rendu/Piscine-C-lib/my
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 21 09:00:08 2013 daniel_d
## Last update Sun Nov 17 21:21:16 2013 daniel_d
##

NAME	= libmy.a

SRC	= my_putchar.c \
	my_isneg.c \
	my_put_nbr.c \
	my_swap.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_strcpy.c \
	my_strncpy.c \
	my_revstr.c \
	my_strstr.c \
	my_strcmp.c \
	my_strcat.c \
	my_strdup.c \
	my_str_to_wordtab.c \

CC	= cc

OBJ	= $(SRC:.c=.o)

all	: $(NAME)
	ranlib $(NAME)
	cp $(NAME) ../
	cp my.h ../../Piscine-C-include/

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean	:
	rm $(OBJ)

fclean	: clean
	rm $(NAME)

re	: fclean all

.PHONY	: all clean fclean re

exe	: all clean
