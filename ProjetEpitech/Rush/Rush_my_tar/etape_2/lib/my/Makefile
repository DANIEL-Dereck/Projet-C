##
## Makefile for libmy in /home/bertho_d/rendu/Piscine-C-lib/my
## 
## Made by bertho_d
## Login   <bertho_d@epitech.net>
## 
## Started on  Mon Oct 21 15:39:41 2013 bertho_d
## Last update Sun Nov 24 19:07:46 2013 bertho_d
##

NAME		= libmy.a

IOPATH		= my_io/
MATHPATH	= my_math/
STRPATH		= my_str/
UTILSPATH	= my_utils/
LISTSPATH	= my_lists/
PRINTFPATH	= $(IOPATH)my_printf/
HEADERSPATH	= my_headers/
TARGETPATH	= ../

SRC		= $(IOPATH)my_str_output.c \
		  $(IOPATH)my_int_output.c \
		  $(IOPATH)my_input.c \
		  $(IOPATH)my_getnbr.c \
		  $(IOPATH)my_numstr.c \
		  $(IOPATH)my_showmem.c \
		  $(PRINTFPATH)my_printf.c \
		  $(PRINTFPATH)params.c \
		  $(PRINTFPATH)conv_specs.c \
		  $(PRINTFPATH)padding.c \
		  $(MATHPATH)my_math.c \
		  $(STRPATH)my_str_alloc.c \
		  $(STRPATH)my_str_alter.c \
		  $(STRPATH)my_str_const.c \
		  $(STRPATH)my_str_parse.c \
		  $(STRPATH)my_str_cmp.c \
		  $(UTILSPATH)my_utils.c \
		  $(LISTSPATH)my_lists_base.c \
		  $(LISTSPATH)my_lists_alter.c

OBJ		= $(SRC:.c=.o)

FLAGS		+= -Wall
FLAGS		+= -Wextra
FLAGS		+= -I$(HEADERSPATH)

CC		= gcc $(FLAGS)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp libmy.a $(TARGETPATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
