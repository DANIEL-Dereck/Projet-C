/*
** my_strdup.c for char *my_strdup(char *src) in /home/boucha_q/rendu/Piscine-C-Jour_08
**
** Made by boucha_q
** Login   <boucha_q@epitech.net>
**
** Started on  Wed Oct  9 08:36:51 2013 boucha_q
** Last update Thu Dec 12 11:00:34 2013 boucha_q
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	taillec;
  char	*dest;

  taillec = my_strlen(src);
  dest = malloc(taillec);
  my_strcpy(dest, src);
  return (dest);
}
