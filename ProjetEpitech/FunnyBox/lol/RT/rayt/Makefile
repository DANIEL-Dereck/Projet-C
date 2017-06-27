##
## Makefile for Makefile in /home/julien_t/Desktop/rayt
## 
## Made by julien_t
## Login   <julien_t@epitech.net>
## 
## Started on  Thu May  8 17:25:08 2014 julien_t
## Last update Mon May 26 11:34:07 2014 julien_t
##

CC      =	gcc

CFLAGS  += 	-I include/ \
		-Wall \
		-Wextra

LDFLAGS	=	-lncurses

RM      = 	rm -rf

NAME    = 	my_reader

SRC     = 	src/main.c

OBJ     = 	$(SRC:.c=.o)

LIB	=	-lm \
		-lmy \
		-Llib \

all:    	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:     	fclean all
