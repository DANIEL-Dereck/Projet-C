/*
** my_strcat.c for my_strcat.c in /home/daniel_d/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct  8 11:20:36 2013 daniel_d
** Last update Sun Oct 27 00:23:42 2013 daniel_d
*/

#include <stdlib.h>

int	my_putstrcat(char *dest, int v)
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

  a = 0;
  v = my_putstrcat(dest, v);
  j = v;
  k = my_putstrcat(src, k);
  k = k + v;
  k = k + 1;
  dest = malloc( sizeof(char) * k);

  while (src[a] != '\0')
    {
      dest[j] = src[a];
      j = j + 1;
      a = a + 1;
    }
  my_putchar('\n');
}

