##
## Makefile for Makefile in /home/grasla_r/rendu/CPE_2013_Pushswap
## 
## Made by grasla_r
## Login   <grasla_r@epitech.net>
## 
## Started on  Sun Jan  5 14:41:06 2014 grasla_r
## Last update Wed Jun  4 17:09:26 2014 jouana_j
##

SRC=	source/main.c \
	source/raytracer.c \
	source/my_pixel_put_to_image.c \
	source/intersections.c \
	source/tri_inter_k.c \
	source/luminosite.c \
	source/init_obj.c \
	source/rotation.c \
	source/lum_normale.c \
	source/ombre.c

CC=	cc

NAME=	rt

LIB= 	-lm \
	-lmy \
	-Llib/ \
	-Lminilibx/ \
	-lmlx \
	-L/usr/lib64/X11 \
	-lXext \
	-lX11

OBJ=	$(SRC:.c=.o)

CFLAGS += 	-I include/ \
		-Wall \
		-Wextra

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
