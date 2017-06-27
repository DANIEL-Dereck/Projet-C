/*
** my_strdup.c for my_strdup.c in /home/le-fra_g/minishel
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Sat May 17 10:40:44 2014 le-franc
** Last update Sat May 17 10:41:20 2014 le-franc
*/

#include "../include/my.h"

char    *my_strdup(char *src)
{
  char  *dest;
  int   i;

  if (src == NULL)
    return (NULL);
  i = 0;
  while (src[i++] != '\0');
  dest = malloc(sizeof(*dest) * i + 3);
  if (dest == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
