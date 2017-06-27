##
## Makefile for Makefile in /home/daniel_d/rendu/Piscine-C-lib/my
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 21 09:00:08 2013 daniel_d
## Last update Tue Nov 19 16:46:44 2013 daniel_d
##

NAME	= libmy.a

SRC	= lib/my/my_putchar.c \
	lib/my/my_isneg.c \
	lib/my/my_put_nbr.c \
	lib/my/my_swap.c \
	lib/my/my_putstr.c \
	lib/my/my_strlen.c \
	lib/my/my_getnbr.c \
	lib/my/my_strcpy.c \
	lib/my/my_strncpy.c \
	lib/my/my_revstr.c \
	lib/my/my_strstr.c \
	lib/my/my_strcmp.c \
	lib/my/my_strcat.c \
	lib/my/my_strdup.c \
	lib/my/my_str_to_wordtab.c \
	lib/my/my_put_nbru.c \
	lib/my/my_format.c \
	lib/my/my_format2.c \
	lib/my/my_format3.c \
	lib/my/my_printf.c \
	lib/my/my_putnbr_base.c \

CC	= cc

OBJ	= $(SRC:.c=.o)

RM	= rm -f

all	: $(NAME)
	@ranlib $(NAME)
	@cp $(NAME) lib/my/../
	@cp lib/my/my.h include/
	@$(RM) $(NAME)

$(NAME)	: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean	:
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) lib/$(NAME)
	@$(RM) include/my.h

re	: fclean all

.PHONY	: all clean fclean re

exe	: all clean
