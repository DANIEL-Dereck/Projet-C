##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Sun Jun  8 23:11:51 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

LNAME	= lib/libmy.a
NAME	= rt

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include/ -L lib -lmy
CFLAGS	+= -lm -L minilibx/ -lmlx -L /usr/lib64/X11 -lXext -lX11

SRC	= src/parsing/main.c \
	src/parsing/parsing.c \
	src/parsing/get_info.c \
	src/parsing/check_tab.c \
	src/parsing/remp_data.c \
	src/parsing/remp_list.c \
	src/parsing/remp_item.c \
	src/parsing/remp_spot.c \
	src/parsing/init_tab.c \
	src/parsing/remp_eye.c \
	src/parsing/my_strcmpv2.c \
	src/parsing/my_display_engine.c \
	src/calc/main.c \
	src/calc/ombre.c \
        src/calc/init_obj.c \
        src/calc/raytracer.c \
        src/calc/tri_inter_k.c \
        src/calc/intersections.c \
        src/calc/my_pixel_put_to_image.c \
        src/calc/lum_normale.c \
        src/calc/luminosite.c \
        src/calc/rotation.c \
	src/calc/calc_ombre.c \
	src/calc/lum_all.c \
	src/calc/lumi.c \

LSRC	= lib/my/string/get_next_line.c \
        lib/my/string/my_concat_str.c \
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
	lib/my/string/my_strcpy.c \
	lib/my/string/my_allocsize.c \
	lib/my/string/my_print_tab.c \
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
