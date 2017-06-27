##
## Makefile for makefile in /home/daniel_d/rendu/Piscine-C-colles-Semaine-03
## 
## Made by daniel_d
## Login   <daniel_d@epitech.net>
## 
## Started on  Sat Oct 26 23:02:59 2013 daniel_d
## Last update Sat Oct 26 23:22:31 2013 daniel_d
##

CC	= gcc

NAME	= colle3

CFLAGS	+= -I../../Piscine-C-include/ 
	-L../../Piscine-C-lib/my/ -o  -lmy

SRCS	= main.c \
	mastermind.c \
	show.c \

RM	= rm -f

all	: $(NAME)
	$(CC) $(NAME) $(SRCS) $(CFLAGS)

clean	: 
	$(RM) $(NAME)

re	: all clean
