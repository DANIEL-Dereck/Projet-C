##
## Makefile for libmy in /home/bertho_d/rendu/Piscine-C-lib/my
## 
## Made by bertho_d
## Login   <bertho_d@epitech.net>
## 
## Started on  Mon Oct 21 15:39:41 2013 bertho_d
## Last update Sun Dec  1 21:37:35 2013 bertho_d
##

NAME		= my_tar

SRCDIR		= src/

SRC		= $(SRCDIR)my_tar.c \
		  $(SRCDIR)args.c \
		  $(SRCDIR)header.c \
		  $(SRCDIR)utils.c \
		  $(SRCDIR)create_archive.c \
		  $(SRCDIR)open_archive.c \
		  $(SRCDIR)disp_infos.c

OBJ		= $(SRC:.c=.o)

FLAGS		+= -Wall
FLAGS		+= -Wextra
FLAGS		+= -lmy
FLAGS		+= -Llib
FLAGS		+= -Iinclude
FLAGS		+= -Ilib/my/my_headers

CC		= gcc $(FLAGS)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
