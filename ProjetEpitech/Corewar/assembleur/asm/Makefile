##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Sun Apr 13 20:58:48 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAME	= asm

NORME	= python ./../../.norme.py -nocheat -verbose -score -libc src/*.c

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I include/ -L lib -lmy

SRC	= src/main.c \
	src/asm.c \
	src/op.c \
	src/init.c \
	src/header.c \
	src/funk1.c \
	src/funk2.c\
	src/funk3.c \
	src/funk4.c \
	src/octopus.c \
	src/val.c \
	src/verifligne.c \

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
	lib/my/my_epur_str.c \

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
	@$(NORME)
	@echo -e "\E[33;32m<--------------------make exe OK-------------------->\E[33;0m"

tmp	: all clean
	@echo -e "\E[33;32m<--------------------make tmp OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"

test	:
	@touch autres/plop.s
	@touch autres/plop.plop.s	
	@touch autres/file
	@touch autres/exec.sa
	@touch autres/toto.l
	@echo -e "\E[33;32m<--------------------fichier de test OK-------------------->\E[33;0m"
