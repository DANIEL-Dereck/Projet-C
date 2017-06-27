/*
** my_revstr.c for my_revstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 13:41:32 2013 daniel_d
** Last update Wed Feb 19 13:41:35 2014 daniel_d
*/

#include "my.h"

void	my_revstr(char *str)
{
  int	h;

  h = 0;
  while (str[h] != '\0')
    h = h + 1;
  while (h != 0)
    {
      h = h - 1;
      my_putchar(str[h]);
    }
  my_putchar('\n');
}
