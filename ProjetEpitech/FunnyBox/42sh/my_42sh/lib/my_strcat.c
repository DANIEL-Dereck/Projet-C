/*
** my_strcat.c for char *my_strcat(char *dest, char *src) in /home/boucha_q/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Tue Oct  8 09:33:20 2013 boucha_q
** Last update Sat May 24 11:26:13 2014 bouchard alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char	*my_strcat(char *dest, char *src)
{
  char	*tmp;
  int	i;
  int	j;

  if (src == NULL || dest == NULL)
    return (NULL);
  i = my_strlen(dest);
  j = my_strlen(src);
  if ((tmp = malloc(sizeof(*tmp) *(i + j + 1))) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (dest[++j] != '\0')
    tmp[++i] = dest[j];
  j = -1;
  while (src[++j] != '\0')
    tmp[++i] = src[j];
  tmp[++i] = '\0';
 return (tmp);
}
