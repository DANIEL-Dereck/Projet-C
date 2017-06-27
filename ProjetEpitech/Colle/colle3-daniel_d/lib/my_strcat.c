/*
** my_strcat.c for strcatchar in /home/daniel_d/colle3-daniel_d/lib
**
** Made by daniel_d
** Login   <daniel_d@epitech.net>
**
** Started on  Thu May 15 19:29:02 2014 daniel_d
** Last update Thu May 15 19:55:55 2014 even_d
*/

#include <stdlib.h>

#include "text.h"

char	*my_strcat(char *str, char c)
{
  int	i;
  char	*tmp;

  i = 0;
  if (str == NULL)
    {
      if ((tmp = malloc(sizeof(*tmp) * 2)) == NULL)
	return (NULL);
      tmp[0] = c;
      tmp[1] = '\0';
      return (tmp);
    }
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  free(str);
  tmp[i] = c;
  tmp[++i] = '\0';
  return (tmp);
}
