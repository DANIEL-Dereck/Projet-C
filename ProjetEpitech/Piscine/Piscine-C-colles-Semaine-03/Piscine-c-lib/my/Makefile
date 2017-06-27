##
## Makefile for Makefile in /home/daniel_d/rendu/Piscine-C-lib/my
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 21 09:00:08 2013 daniel_d
## Last update Sat Oct 26 22:59:14 2013 daniel_d
##

NAME	= libmy.a

SRC	=my_putchar.c \
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
	my_strdup.c 

CC	= gcc

RM	= rm -f

OBJ= $(SRC:.c=.o)

all:	$(NAME)
	ranlib $(NAME)
	cp $(NAME) ../
	cp my_colle3.h ../../Piscine-C-include/

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

