##
## Makefile for makefile in /home/daniel_d/Name_Prog
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sun Mar  9 23:33:38 2014 daniel_d
## Last update Sat May 10 18:11:24 2014 cordon_b
##

CC 	= gcc

RM	= rm -f

NAME	= epic_editor

CFLAGS	+= -I ../include/

DIR	= generator

SRC	= $(DIR)/creat_file.c \
	$(DIR)/remp_file.c \
	$(DIR)/gestion_error.c \
	$(DIR)/gestion_struct.c \
	$(DIR)/init_struct.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME) 

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo -e "\E[33;32m<--------------------Compilation OK-------------------->\E[33;0m"

clean	:
	@$(RM) $(OBJ)
	@echo -e "\E[33;32m<--------------------make clean OK-------------------->\E[33;0m"

fclean	: clean
	@$(RM) $(NAME)
	@echo -e "\E[33;32m<--------------------make fclean OK-------------------->\E[33;0m"

re	: fclean all
	@echo -e "\E[33;32m<--------------------make re OK-------------------->\E[33;0m"

