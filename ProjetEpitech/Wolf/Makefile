##
## Makefile for makefile in /home/daniel_d/Downloads/projet/Bistro/code
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Mon Oct 28 10:34:58 2013 daniel_d
## Last update Sun Jan 12 16:25:00 2014 daniel_d
##

CC 	= gcc

RM	= rm -f

NAME	= wolf3d

CFLAGS	+= -Wall -Wextra

CFLAGS	+= -I ./Lib/include/ -L ./Lib/lib -lmy -L /usr/lib64 -lmlx_$(HOSTTYPE) -L /usr/lib64/X11 -lXext -lX11 -lm

SRC	= src/main.c \
	src/my_put_pixel_to_image.c \
	src/wolff.c \
	src/wolfkey.c \
	src/wolfwiew.c \
	src/parcmap.c \

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean	: 
	@$(RM) $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

exe	: all clean

re	: fclean all

