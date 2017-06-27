##
## Makefile for Makefile in /home/grasla_r/rendu/CPE_2013_Pushswap
## 
## Made by grasla_r
## Login   <grasla_r@epitech.net>
## 
## Started on  Sun Jan  5 14:41:06 2014 grasla_r
## Last update Mon May 12 10:03:08 2014 daniel_d
##

CC	= gcc

RM	= rm -f

NAME	= rt

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include/ -lmy -Llib -Lminilibx -L/usr/lib64/X11 -lXext -lX11 -lm

SRC	= source/main.c \
	source/raytracer.c \
	source/my_pixel_put_to_image.c \
	source/intersections.c \
	source/tri_inter_k.c \
	source/luminosite.c \
	source/init_obj.c \
	source/rotation.c

OBJ	=$(SRC:.c=.o)

all	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	:clean
	$(RM) $(NAME)

re	: fclean all

exe	: all clean
