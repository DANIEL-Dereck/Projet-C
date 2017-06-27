##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Sat Mar 15 16:01:11 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAME	= rtv1

NORME	= python ../.norme.py -nocheat -verbose -score -libc src/*.c

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I include/ -L lib -lmy
CFLAGS	+= -L /usr/lib64 -lmlx_$(HOSTTYPE) -L /usr/lib64/X11 -lXext -lX11 -lm

SRC	= src/main.c \
	src/init.c \
	src/my_put_pixel_to_image.c \
	src/gere_all.c \
	src/rtm.c \
	src/my_sphere.c \
	src/my_plan.c \
	src/lumos.c \

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
	@echo -e "\E[33;32m<--------------------Make clean OK-------------------->\E[33;0m"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) $(LNAME)
	@echo -e "\E[33;32m<--------------------Make fclean OK-------------------->\E[33;0m"

exe	: all clean
	@$(NORME)
	@echo -e "\E[33;32m<--------------------Norme OK-------------------->\E[33;0m"
	@echo -e "\E[33;32m<--------------------Make exe OK-------------------->\E[33;0m"

tmp	: all clean
	@echo -e "\E[33;32m<--------------------Make tmp OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"

