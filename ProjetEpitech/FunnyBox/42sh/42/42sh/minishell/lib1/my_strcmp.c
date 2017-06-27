/*
** my_strcmp.c for my_strcmp.c in /home/le-fra_g/minishel/lib
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 17:22:26 2014 le-franc
** Last update Mon May 19 14:23:41 2014 le-franc
*/

#include "../include/my.h"

int	my_strcmp(char *to_cmp, char *with)
{
  int	i;
  int	n;

  i = 0;
  while (with[i] != 0)
    {
      if (to_cmp[i] == with[i])
        n = 1;
      else
        n = 0;
      i++;
    }
  return (n);
}
