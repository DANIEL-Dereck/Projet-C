##
## Makefile for colle1 in /home/thepatriot/rendu/colle1
## 
## Made by bertho_d
## Login   <bertho_d@epitech.net>
## 
## Started on  Tue Apr 29 14:11:11 2014 bertho_d
## Last update Tue Apr 29 17:42:13 2014 bertho_d
##

NAME		= pi

SRCDIR		= src/
INCLDIR		= include/

SRC		= $(SRCDIR)main.c \
		  $(SRCDIR)calc.c \
		  $(SRCDIR)div.c \
		  $(SRCDIR)nb.c \
		  $(SRCDIR)utils.c \
		  $(SRCDIR)parsing.c

OBJ		= $(SRC:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS		+= -I$(INCLDIR)
CFLAGS		+= -g
CFLAGS		+= -Wall
CFLAGS		+= -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
