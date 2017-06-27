##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Sun Apr 13 21:58:59 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAMEASM	= bin/asm
NAMECOR	= bin/corewar

NORMEASM	= python ./.norme.py -nocheat -verbose -score -libc src/asm/*.c
NORMECOR	= python ./.norme.py -nocheat -verbose -score -libc src/corewar/*.c

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I include/ -L lib -lmy

SRCASM	= src/asm/main.c \
	src/asm/asm.c \
	src/asm/op.c \
	src/asm/init.c \
	src/asm/header.c \
	src/asm/funk1.c \
	src/asm/funk2.c\
	src/asm/funk3.c \
	src/asm/funk4.c \
	src/asm/octopus.c \
	src/asm/val.c \
	src/asm/my_str_cpy.c \
	src/asm/my_label.c \
	src/asm/init_oct.c \
	src/asm/verifligne.c \
	src/asm/separation.c \

SRCCOR	= src/corewar/main.c \
	src/corewar/vm.c \

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

OBJASM	= $(SRCASM:.c=.o)
OBJCOR	= $(SRCCOR:.c=.o)
LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME) $(NAMEASM) $(NAMECOR)

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\E[33;32m<--------------------Compilation lib OK-------------------->\E[33;0m"

$(NAMEASM)	: $(OBJASM)
	@$(CC) $(OBJASM) -o $(NAMEASM) $(CFLAGS)
	@echo -e "\E[33;32m<--------------------Compilation asm OK-------------------->\E[33;0m"

$(NAMECOR)	: $(OBJCOR)
	@$(CC) $(OBJCOR) -o $(NAMECOR) $(CFLAGS)
	@echo -e "\E[33;32m<--------------------Compilation corewar OK-------------------->\E[33;0m"

clean	:
	@$(RM) $(OBJASM)
	@$(RM) $(OBJCOR)
	@$(RM) $(LOBJ)
	@echo -e "\E[33;32m<--------------------make clean OK-------------------->\E[33;0m"

fclean	: clean
	@$(RM) $(NAMEASM)
	@$(RM) $(NAMECOR)
	@$(RM) $(LNAME)
	@echo -e "\E[33;32m<--------------------make fclean OK-------------------->\E[33;0m"

exe	: all clean
	@$(NORMEASM)
	@echo -e "\E[33;32m<--------------------norme asm-------------------->\E[33;0m"
	@$(NORMECOR)
	@echo -e "\E[33;32m<--------------------norme corewar-------------------->\E[33;0m"	
	@echo -e "\E[33;32m<--------------------make exe OK-------------------->\E[33;0m"

tmp	: all clean
	@echo -e "\E[33;32m<--------------------make tmp OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"
