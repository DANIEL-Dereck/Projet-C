/*
** my_revstr.c for my_revstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 13:41:32 2013 daniel_d
** Last update Sat Apr 26 15:50:55 2014 daniel_d
*/

#include "my.h"

void	my_revstr(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != '\0');
  i--;
  while (i != 0)
    my_putchar(str[i--]);
  my_putchar('\n');
}
