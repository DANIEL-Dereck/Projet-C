/*
** my_strcat.c for char *my_strcat(char *dest, char *src) in /home/boucha_q/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Tue Oct  8 09:33:20 2013 boucha_q
** Last update Tue May 13 16:42:43 2014 bouchard alexandre
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *src, char *src1)
{
  char	*dest;
  int	i;
  int	j;

  j = -1;
  i = -1;
  dest = malloc(sizeof(*dest) * (my_strlen(src) + my_strlen(src) + 1));
  while (src[++j] != '\0')
    dest[++i] = src[j];
  j = -1;
  while (src1[++j] != '\0')
    dest[++i] = src1[j];
  dest[++i] = '\0';
  return (dest);
}
