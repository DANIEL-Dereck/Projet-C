/*
** my_strdup.c for my_strdup.c in /home/daniel_d/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 11:04:29 2013 daniel_d
** Last update Tue Oct 22 16:00:50 2013 daniel_d
*/

#include <stdlib.h>

int	my_strdup(char *src)
{
  int a;
  int b;
  char *srcs;

  a = 0;
  b = 0;
  srcs = src;

  while (src[a] != '\0')
    {
      my_putchar(src[a]);
      a = a + 1;
      b = b + 1;
    }
  src = malloc(b);
  src = srcs;
  a = 0;

  while (srcs[a] != '\0')
    {
      my_putchar(srcs[a]);
      a = a + 1;
    }
}
