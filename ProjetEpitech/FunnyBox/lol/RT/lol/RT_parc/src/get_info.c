/*
** get_info.c for rt in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun  2 09:57:18 2014 daniel_d
** Last update Mon Jun  2 10:01:35 2014 daniel_d
*/

#include <stdlib.h>
#include "rt_pars.h"
#include "my.h"

char	*get_info_cpy(char *src, char *dest, char s, char e)
{
  int	i;
  int	l;

  i = 0;
  l = 0;
  while (src[i] != s && src[i] != '\0')
    i++;
  i++;
  while (src[i] != e && src[i] != '\0')
    dest[l++] = src[i++];
  dest[l] = '\0';
  return (dest);
}

char    *get_info(char *src, char s, char e)
{
  char  *dest;
  int   l;
  int   i;

  i = 0;
  l = 0;
  while (src[i] != '\0')
    {
      while (src[i] != s && src[i] != '\0')
        i++;
      if (src[i] == '\0')
        return (NULL);
      i++;
      while (src[i] != e && src[i] != '\0')
        {
          i++;
          l++;
        }
      i++;
    }
  if ((dest = malloc(sizeof(*dest) * (l + 1))) == NULL)
    return (NULL);
  dest = get_info_cpy(src, dest, s, e);
  return (dest);
}
