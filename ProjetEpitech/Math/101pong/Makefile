##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Tue Nov 19 16:57:32 2013 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= 101pong

CFLAGS	= -L lib -lmy -I include/ -Wall -Wextra -lm

SRC	= main.c \
	coorvec.c \
	angleinc.c \
	instantk.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

