##
## Makefile for Makefile in /home/bidard_v/matos
## 
## Made by bidard_v
## Login   <bidard_v@epitech.net>
## 
## Started on  Thu Feb 20 21:35:57 2014 bidard_v
## Last update Sun Mar  2 14:20:02 2014 daniel_d
##

SRC	= src/main.c \
	src/sudoku-pars.c \
	src/my_init.c \
	src/my_free.c \
	src/my_res.c \

SRC_LIB	= lib/my_putchar.c \
	lib/my_putstr.c \
	lib/my_format.c \
	lib/my_format2.c \
	lib/my_format3.c \
	lib/my_putnbr_base.c \
	lib/my_put_nbr.c \
	lib/my_put_nbru.c \
	lib/my_strcmp.c \
	lib/my_strlen.c \
	lib/my_printf.c \
	lib/my_wordnbr.c \
	lib/my_str_to_wordtab.c \

NAME	= sudoki-bi
NAME_LI	= lib/libmy.a

OBJ	= $(SRC:.c=.o)
OBJ_LIB	= $(SRC_LIB:.c=.o)

CC	= cc

RM	= rm -f

DEBUG	= -g -g3 -pedantic -ansi

CFLAGS	+= -I include/
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -L lib/ -lmy -g3


all	: $(NAME_LI) $(NAME)

$(NAME_LI)	: $(OBJ_LIB)
	@ar rc $(NAME_LI) $(OBJ_LIB)
	@echo ">----- Compilation Lib terminée -----<"

$(NAME)	: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo ">----- Compilation terminée -----<"

debug	:
	@$(CC) -o $(NAME) $(DEBUG) $(SRC) $(SRC_LIB) $(CFLAGS)
	@echo ">----- Debug terminée -----<"

clean	:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_LIB)
	@echo ">----- Clean  terminée -----<"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_LI)
	@echo ">----- Fclean terminée -----<"

re	: fclean all

exe	: all clean

run	: all	clean
	@./$(NAME)
