##
## Makefile for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
## 
## Made by cordon_b
## Login   <cordon_b@epitech.net>
## 
## Started on  Sat May 10 10:33:20 2014 cordon_b
## Last update Sat May 10 16:38:22 2014 cordon_b
##

CC	= gcc

RM	= rm -f

NAME	= parse

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	= -I../../include/

SRCS	= parsing_map.c \
	  fill_the_list.c \
	  fill_champ.c \
	  fill_header.c \
	  look_magic_number.c \
	  fill_monster.c \
	  fill_link.c \
	  str_to_wordtab.c \
	  ../get_next_line.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
