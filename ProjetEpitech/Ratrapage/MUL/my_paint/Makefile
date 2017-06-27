##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Mon Jun 30 13:39:57 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

NORMEC  = python .norme.py -nocheat -verbose -score -libc src/*.c
NORMEH  = python .norme.py -nocheat -verbose -score -libc include/*.h

MINILX	= minilibx

EXEC	= $(MINILX)/minilibx

LNAME	= lib/libmy.a
NAME	= PimpmyPaint

CFLAGS	+= -Wall -Wextra -Wextra
CFLAGS	+= -I include/ -L lib -lmy
CFLAGS	+= -L /usr/lib64 -lmlx_$(HOSTTYPE) -L /usr/lib64/X11 -lXext -lX11 -lm

SRC	= src/main.c \
	src/option.c \
	src/my_put_pixel_to_image.c \
	src/color_win.c \
	src/color_click.c \
	src/draw.c \
	src/circle.c \
	src/square.c \
	src/brush.c \
	src/triangle.c \
	src/remp.c \
	src/menu.c \
	src/expose.c \
	src/bouton_brush.c \
	src/bouton_square.c \
	src/bouton_circle.c \
	src/bouton_triangle.c \
	src/bouton_remp.c \
	src/bouton_size.c \
	src/bouton_size_clean.c \
	src/bouton_size_remp.c \

LSRC	= lib/my/string/get_next_line.c \
        lib/my/string/my_strcat.c \
	lib/my/string/my_epur_str.c \
        lib/my/string/my_needposchar.c \
	lib/my/string/my_nmatch.c \
	lib/my/string/my_putchar.c \
        lib/my/string/my_putstr.c \
        lib/my/string/my_revstr.c \
        lib/my/string/my_strcmp.c \
        lib/my/string/my_strdup.c \
	lib/my/string/my_strlen.c \
        lib/my/string/my_str_to_wordtab.c \
        lib/my/number/my_put_nbr.c \
        lib/my/number/my_put_nbr_rec.c \
        lib/my/number/my_putnbr_base.c \
        lib/my/number/my_putnbr_base_rec.c \
        lib/my/number/my_put_nbru.c \
        lib/my/number/my_getnbr.c \
	lib/my/number/my_pow.c \
        lib/my/my_printf/my_printf.c \
        lib/my/my_printf/my_format.c \
        lib/my/my_printf/my_format2.c \
        lib/my/my_printf/my_format3.c \

OBJ	= $(SRC:.c=.o)

LOBJ	= $(LSRC:.c=.o)

all	: $(LNAME) $(NAME)

minilibx:
	@(cd $(MINILX) && $(MAKE))
	@echo -e "\033[32m<####################\033[36mCompilation minilibx\033[32m####################>\033[0m"

$(LNAME)	: $(LOBJ)
	@ar rc $(LNAME) $(LOBJ)
	@cp lib/my/my.h include/
	@echo -e "\033[32m<####################\033[36mCompilation lib\033[32m####################>\033[0m"

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@echo -e "\033[32m<####################\033[36mCompilation\033[32m####################>\033[0m"

clean	:
	@$(RM) $(OBJ)
	@$(RM) $(LOBJ)
	@echo -e "\033[32m<####################\033[36mmake clean\033[32m####################>\033[0m"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) $(LNAME)
	@echo -e "\033[32m<####################\033[36mmake fclean\033[32m####################>\033[0m"

re	: fclean all
	@echo -e "\033[32m<####################\033[36mmake re\033[32m####################>\033[0m"

exe	: all clean
	@$(NORMEC)
	@$(NORMEH)
	@echo -e "\033[32m<####################\033[36mmake exe\033[32m####################>\033[0m"
