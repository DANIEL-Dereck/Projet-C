##
## Makefile for Makefile in /home/le-fra_g/minishel
## 
## Made by le-franc
## Login   <le-fra_g@epitech.net>
## 
<<<<<<< HEAD
## Started on  Thu Jan 30 04:53:51 2014 bouchard alexandre
## Last update Tue May 20 14:08:36 2014 bouchard alexandre
=======
## Started on  Fri May 16 16:31:08 2014 le-franc
## Last update Mon May 19 16:28:18 2014 le-franc
>>>>>>> e44ba8d01bc9228e584b223ca750246bc6958e14
##

CC	= gcc

RM	= rm -f

NAME	= 42sh

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I./include/

SRC	= sources/42sh.c \
	sources/my_read.c \
	sources/sources_check_alias/my_tmp_alias.c \
	sources/sources_check_alias/my_check_sh.c \
	sources/sources_check_alias/my_check_alias.c \
	sources/sources_check_alias/my_check_equal.c \
	sources/sources_check_alias/my_check_name_alias.c \
	sources/sources_check_alias/my_check_cmd_alias.c \
	sources/sources_check_alias/my_write_alias_in_tmp.c \
	sources/sources_exec_alias/my_alias.c \
	sources/sources_exec_alias/my_realloc_tab.c \
	sources/sources_exec_alias/my_cmd_buff_for_alias.c \
	sources/sources_exec_alias/my_put_alias_in_buff.c \
	sources/sources_path/get_path.c \
	sources/sources_path/my_path.c \
	sources/sources_path/my_path_to_wordtab.c \
	sources/sources_path/fill_func_path.c \
	sources/main.c

LIB	= lib/my_putchar.c \
	lib/my_putstr.c \
<<<<<<< HEAD
	lib/my_put_nbr.c \
	lib/my_strlen.c \
	lib/my_str_to_wordtab.c \
	my_get_nextline.c
OBJ=	$(SRC:.c=.o)

CC=	gcc -g

CFLAGS=	-I./include/
CFLAGS += -Wall -Wextra
RM=	rm -f
=======
	lib/my_strlen.c \
	lib/my_strcat.c \
	lib/my_strcmp.c \
	lib/my_strncmp.c \
	lib/my_strdup.c \
	lib/my_nmatch.c \
	lib/my_str_to_wordtab.c \
	lib/my_get_nextline.c \
	lib/my_getnbr.c \
	lib/my_putnbr.c \
>>>>>>> e44ba8d01bc9228e584b223ca750246bc6958e14

OBJ	= $(SRC:.c=.o)

OBJ2	= $(LIB:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ2)
		$(CC) $(OBJ) $(OBJ2) -o $(NAME)

clean:
		$(RM) $(OBJ) $(OBJ2)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
