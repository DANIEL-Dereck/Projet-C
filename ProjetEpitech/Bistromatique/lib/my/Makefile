##
## Makefile for Makefile in /home/daniel_d/rendu/Piscine-C-lib/my
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 21 09:00:08 2013 daniel_d
## Last update Tue Nov  5 12:15:00 2013 daniel_d
##

NAME= libmy.a

SRC=	my_putchar.c \
	my_putstr.c \
	my_strlen.c \

CC= cc

OBJ= $(SRC:.c=.o)

all:	$(NAME)
	ranlib $(NAME)
	cp $(NAME) ../
	cp my.h ../../include/

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean:		clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
