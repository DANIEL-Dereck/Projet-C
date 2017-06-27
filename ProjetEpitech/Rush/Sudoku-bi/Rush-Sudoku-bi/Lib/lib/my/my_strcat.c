/*
** my_strcat.c for my_strcat.c in /home/daniel_d/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct  8 11:20:36 2013 daniel_d
** Last update Wed Feb 19 13:48:35 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr_cat(char *dest, int v)
{
  v = 0;

  while (dest[v] != '\0')
    {
      v = v + 1;
    }
  return (v);
}

char	*my_strcat(char *dest, char *src)
{
  int v;
  int k;
  int j;
  int a;

  v = 0;
  k = 0;
  a = 0;
  v = my_putstr_cat(dest, v);
  j = v;
  k = my_putstr_cat(src, k);
  k = k + v;
  k = k + 1;
  if ((dest = malloc( sizeof(char) * k)) == NULL)
    return (0);
  while (src[a] != '\0')
    {
      dest[j] = src[a];
      j = j + 1;
      a = a + 1;
    }
  my_putchar('\n');
  return (dest);
}

