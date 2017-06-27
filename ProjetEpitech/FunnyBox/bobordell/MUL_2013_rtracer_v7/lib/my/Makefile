##
## Makefile for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
## 
## Made by jouana_j
## Login   <jouana_j@epitech.net>
## 
## Started on  Mon Oct 21 07:13:03 2013 jouana_j
## Last update Sat Dec  7 18:01:13 2013 jouana_j
##

SRC	= my_putchar.c \
	  my_putstr.c \
	  my_put_nbr.c \
	  my_getnbr.c \
	  my_find_prime_sup.c \
          my_isneg.c \
          my_is_prime.c \
          my_power_rec.c \
          my_revstr.c \
          my_showmem.c \
          my_sort_int_tab.c \
          my_square_root.c \
          my_strcapitalize.c \
          my_strcat.c \
          my_strcmp.c \
          my_strcpy.c \
          my_str_isalpha.c \
          my_str_islower.c \
          my_str_isnum.c \
          my_str_isprintable.c \
          my_str_isupper.c \
          my_strlcat.c \
          my_strlen.c \
          my_strlowcase.c \
          my_strncat.c \
	  my_strncmp.c \
          my_strncpy.c \
          my_strstr.c \
          my_strupcase.c \
          my_swap.c \
	  my_putnbr_base.c \
	  my_getnbr_base.c \
	  my_putnbr_base_long.c \
	  my_put_nbr_u_rec.c \
	  my_printf.c \
	  my_printf_function.c \
	  my_printf_ofunction.c \
	  my_printf_s.c \
	  my_tb_ptr.c \
	  my_get_nextline.c \
	  my_realloc.c

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

FLAG	= -Wall \
	  -Wextra

all: $(NAME)

$(NAME): $(SRC)
	 cc -c $(SRC) $(FLAG)
	 ar rc $(NAME) $(OBJ)
	 cp libmy.a ../
	 cp my.h ../../include/

clean:	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
