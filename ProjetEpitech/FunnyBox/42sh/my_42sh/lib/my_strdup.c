/*
** my_strdup.c for char *my_strdup(char *src) in /home/boucha_q/rendu/Piscine-C-Jour_08
**
** Made by boucha_q
** Login   <boucha_q@epitech.net>
**
** Started on  Wed Oct  9 08:36:51 2013 boucha_q
** Last update Fri May 23 18:48:50 2014 bouchard alexandre
*/

#include <../include/sh.h>
#include <../include/my.h>

char	*my_strdup(char *src)
{
  int	taillec;
  char	*dest;

  taillec = my_strlen(src);
  dest = malloc(taillec);
  my_strcpy(dest, src);
  return (dest);
}
