##
## Makefile for Makefile in /home/even_d/rendu/colle3-daniel_d
##
## Made by even_d
## Login   <even_d@epitech.net>
##
## Started on  Thu May 15 19:02:44 2014 even_d
## Last update Mon Jun  2 19:33:09 2014 daniel_d
##

RM	=	rm -f

SRC	=	src/main.c \
		src/part_one.c \
		src/part_two.c \
		src/part_three.c \

SRC	+=	lib/my_putchar.c \
		lib/my_put_nbr.c \
		lib/my_putstr.c \
		lib/my_strcat.c \
		lib/my_strcmp.c \
		lib/my_strlen.c

NAME	=	text_count

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -g
CFLAGS	+=	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
