##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Fri Mar 21 12:07:49 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAMEC	= client/client
NAMES	= server/server

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include/ -L lib -lmy

SRCS	= src/serveur/main.c \
	src/serveur/my_serv.c \

SRCC	= src/client/main.c \
	src/client/client.c \

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

OBJS	= $(SRCS:.c=.o)

OBJC	= $(SRCC:.c=.o)

LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME) $(NAMEC) $(NAMES)

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\E[33;32m<--------------------Compilation lib OK-------------------->\E[33;0m"

$(NAMEC)	: $(OBJC)
	@$(CC) $(OBJC) -o $(NAMEC) $(CFLAGS)
	@echo -e "\E[33;32m<--------------------Compilation client OK-------------------->\E[33;0m"

$(NAMES)	: $(OBJS)
	@$(CC) $(OBJS) -o $(NAMES) $(CFLAGS)
	@echo -e "\E[33;32m<--------------------Compilation serveur OK-------------------->\E[33;0m"

clean	:
	@$(RM) $(OBJC)
	@$(RM) $(OBJS)
	@$(RM) $(LOBJ)
	@echo -e "\E[33;32m<--------------------make clean OK-------------------->\E[33;0m"

fclean	: clean
	@$(RM) $(NAMEC)
	@$(RM) $(NAMES)
	@$(RM) $(LNAME)
	@echo -e "\E[33;32m<--------------------make fclean OK-------------------->\E[33;0m"

exe	: all clean
	@echo -e "\E[33;32m<--------------------make exe OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"

