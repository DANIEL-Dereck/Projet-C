##
## Makefile for makefile in /home/daniel_d/rendu/Piscine-C-Test
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sat Oct 26 20:24:12 2013 daniel_d
## Last update Sat Oct 26 20:28:40 2013 daniel_d
##

CC	= gcc

RM	= rm -f

NAME	= nom

SRC	= main.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)
	$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
