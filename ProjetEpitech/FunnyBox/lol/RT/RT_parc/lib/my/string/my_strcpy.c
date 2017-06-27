/*
** my_strcpy.c for strcpy in /home/daniel_d/rendu/RT/RT_parc/lib/my/string
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri May 30 09:19:21 2014 daniel_d
** Last update Fri May 30 10:18:36 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char	*dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
