##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Tue Apr 22 17:07:01 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAME	= mysh

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include/
CFLAGS	+= -L lib/ -lmy

SRC	= src/main.c \
	src/my_prompt.c \
	src/my_signal.c \
	src/my_builtin.c \
	src/my_path.c \
	src/my_execcmd.c \
	src/my_exit.c \

LSRC	= lib/my/my_putchar.c \
        lib/my/my_strlen.c \
        lib/my/my_putstr.c \
        lib/my/my_put_nbr.c \
        lib/my/my_put_nbr_rec.c \
        lib/my/my_putnbr_base.c \
        lib/my/my_putnbr_base_rec.c \
        lib/my/my_put_nbru.c \
        lib/my/my_getnbr.c \
        lib/my/my_revstr.c \
        lib/my/my_strcmp.c \
        lib/my/my_strdup.c \
        lib/my/my_str_to_wordtab.c \
        lib/my/my_format.c \
        lib/my/my_format2.c \
        lib/my/my_format3.c \
        lib/my/my_printf.c \
        lib/my/my_strdup.c \
        lib/my/my_needposchar.c \
        lib/my/get_next_line.c \
        lib/my/my_concat_str.c \
	lib/my/my_strncmp.c \
	lib/my/my_epur_str.c \
	lib/my/my_nmatch.c \

OBJ	= $(SRC:.c=.o)

LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME) $(NAME) 

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\E[33;32m<--------------------Compilation lib OK-------------------->\E[33;0m"

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo -e "\E[33;32m<--------------------Compilation OK-------------------->\E[33;0m"

clean	:
	@$(RM) $(OBJ)
	@$(RM) $(LOBJ)
	@echo -e "\E[33;32m<--------------------make clean OK-------------------->\E[33;0m"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) $(LNAME)
	@echo -e "\E[33;32m<--------------------make fclean OK-------------------->\E[33;0m"

exe	: all clean
	@echo -e "\E[33;32m<--------------------make exe OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"
