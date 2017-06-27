##
## Makefile for Makefile in /home/le-fra_g/lol/my_42sh
## 
## Made by le-franc
## Login   <le-fra_g@epitech.net>
## 
## Started on  Tue May 20 16:15:21 2014 le-franc
## Last update Sun May 25 22:06:31 2014 daniel_d
##

CC	= gcc -g

RM	= rm -f

NAME	= 42sh

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I ./include/

SRC	= sources/main.c \
	sources/42sh.c \
	sources/my_read.c \
	sources/my_exec_cmd.c \
	sources/my_env.c \
	sources/my_env_in_list.c \
	sources/my_signal.c \
	sources/sources_builtins/my_exit.c \
	sources/sources_builtins/my_setenv.c \
	sources/sources_builtins/put_tail_list.c \
	sources/sources_builtins/my_unsetenv.c \
	sources/sources_builtins/my_echo.c \
	sources/sources_builtins/my_echobis.c \
	sources/sources_builtins/my_cd.c \
	sources/sources_builtins/my_cdbis.c \
	sources/sources_builtins/check_builtins.c \
	sources/sources_redirection/my_parse.c \
	sources/sources_redirection/redirection_right.c \
	sources/sources_redirection/separator.c \
	sources/sources_redirection/pars_redir.c \
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

LIB	= lib/my_strcmp.c \
	lib/my_strdup.c \
	lib/my_strcpy.c \
	lib/my_needposchar.c \
	lib/my_strcat.c \
	lib/my_putchar.c \
	lib/my_putstr.c \
	lib/my_strlen.c \
	lib/my_getnbr.c \
	lib/my_nmatch.c \
	lib/my_str_to_wordtab.c \
	lib/my_get_nextline.c

OBJ	= $(SRC:.c=.o)

OBJ2	= $(LIB:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ2)
		$(CC) $(CFLAGS) $(OBJ) $(OBJ2) -o $(NAME)
clean:
	$(RM) $(OBJ) $(OBJ2)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
