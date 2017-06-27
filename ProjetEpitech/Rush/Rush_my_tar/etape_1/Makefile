##
## Makefile for libmy in /home/bertho_d/rendu/Piscine-C-lib/my
## 
## Made by bertho_d
## Login   <bertho_d@epitech.net>
## 
## Started on  Mon Oct 21 15:39:41 2013 bertho_d
## Last update Fri Dec  6 14:02:57 2013 daniel_d
##

NAME		= my_tar

SRC	= main.c \

OBJ		= $(SRC:.c=.o)

FLAGS		+= -Wall
FLAGS		+= -Wextra
FLAGS		+= -lmy
FLAGS		+= -L lib
FLAGS		+= -I include
FLAGS		+= -I lib/my/my_headers

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
