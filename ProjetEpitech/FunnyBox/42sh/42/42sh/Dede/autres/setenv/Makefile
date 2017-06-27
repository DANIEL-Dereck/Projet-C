##
## Makefile for Make in /home/aubry_f/rendu/42sh/setenv
## 
## Made by aubry_f
## Login   <aubry_f@epitech.net>
## 
## Started on  Wed Apr 23 20:12:16 2014 aubry_f
## Last update Fri May 16 16:15:08 2014 aubry_f
##

SRC=	src/my_setenv.c \
	src/my_setenv_fct.c\
	src/my_strcpy.c \
	src/my_strcat.c \
	src/my_getnbr.c \
	src/my_strlen.c

OBJ=	$(SRC:.c=.o)

NAME=	setenv

RM=	rm -f

CFLAGS=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(OBJ)

re:	fclean all
