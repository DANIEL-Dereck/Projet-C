/*
** my.h for my.h in /home/le-fra_g/minishel/include
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 16:43:39 2014 le-franc
<<<<<<< HEAD
** Last update Tue May 20 14:11:58 2014 bouchard alexandre
=======
** Last update Mon May 19 15:07:18 2014 le-franc
>>>>>>> e44ba8d01bc9228e584b223ca750246bc6958e14
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/* my_putchar.c */
void	my_putchar(char);

/* my_putstr.c */
void	my_putstr(char *);

/* my_strlen.c */
int	my_strlen(char *);

/* my_strcat.c */
char	*my_strcat(char *, char *);

/* my_strcmp.c */
int	my_strcmp(char *, char *);

/* my_strncmp.c */
int	my_strncmp(char *, char *, int);

/* my_strdup.c */
char	*my_strdup(char *);

/* my_str_to_wordtab.c */
int	count_line_str(char *);
int	count_long_line_str(char *, int);
int	count_long_line_str(char *, int);
char	**my_str_to_wordtab(char *);

/* my_get_nbr.c */
int	nbrlen(char *);
int	my_pow(int);
int	my_getnbr(char *);

/* my_putnbr.c */
int	my_abs(int);
int	my_putnbr(int);

/* my_get_next_line.c */
char	*my_get_nextline(int);

#endif
