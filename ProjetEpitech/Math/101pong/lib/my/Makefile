##
## Makefile for Makefile in /home/daniel_d/rendu/Piscine-C-lib/my
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 21 09:00:08 2013 daniel_d
## Last update Mon Nov 11 14:48:42 2013 daniel_d
##

NAME= libmy.a

SRC=	my_putchar.c \
	my_putstr.c \
	my_strlen.c \
	my_put_nbr.c \
	my_getnbr.c \

CC= cc

OBJ= $(SRC:.c=.o)

all:	$(NAME)
	ranlib $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm $(OBJ)

fclean:		clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
