##
## Makefile for Makefile in /home/mulot_i/rendu/ex_tmp
##
## Made by mulot_i
## Login   <mulot_i@epitech.net>
##
## Started on  Mon Oct 21 09:08:05 2013 mulot_i
## Last update Thu Dec 12 10:53:27 2013 boucha_q
##

SRC	= my_isneg.c \
	  my_strcat.c \
	  my_strncat.c \
	  my_strcmp.c \
	  my_strncpy.c \
	  my_strcpy.c \
	  my_putchar.c \
	  my_strdup.c \
	  my_put_nbr.c \
	  my_str_isalpha.c \
	  my_swap.c \
	  my_putstr.c \
	  my_getnbr.c \
	  my_revstr.c \
	  my_strlen.c \

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CC	= cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	cp $(NAME) ../
	cp my.h ../
	@echo -e "\033[31mSUCCES\033[0m"
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
