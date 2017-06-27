##
## Makefile for makefile in /home/marrec_k/Colle
##
## Made by marrec_k
## Login   <marrec_k@epitech.net>
##
## Started on  Wed May 21 14:04:35 2014 marrec_k
## Last update Wed May 21 17:06:07 2014 marrec_k
##

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./includes/

NAME	=	my_boogle

SRC	=	src/main.c \
		src/utils.c \
		src/my_getnbr.c \
		src/my_puterror.c \
		src/get_next_line.c \
		src/data.c \
		src/check.c \
		src/generate.c \
		src/my_show_grid.c \
		src/my_check_word_in_grid.c \
		src/check_pos.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC)  $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
