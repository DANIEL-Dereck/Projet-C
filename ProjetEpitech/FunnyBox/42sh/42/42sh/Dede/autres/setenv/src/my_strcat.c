/*
** my_strcat.c for Concat Strings in /home/aubry_f/rendu/Piscine-C-Jour_07
**
** Made by aubry_f
** Login   <aubry_f@epitech.net>
**
** Started on  Tue Oct  8 10:26:50 2013 aubry_f
** Last update Fri May 16 16:18:26 2014 aubry_f
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	a;

  i = 0;
  a = my_strlen(dest);
  while (src[i] != '\0')
    dest[a++] = src[i++];
  dest[a] = '\0';
  return (dest);
}
