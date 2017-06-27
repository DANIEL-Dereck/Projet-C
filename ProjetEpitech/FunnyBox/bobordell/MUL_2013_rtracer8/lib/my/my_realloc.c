/*
** my_realloc.c for lib in /home/jouana_j/rendu/MUL_2013_fdf/lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Sat Dec  7 17:54:22 2013 jouana_j
** Last update Sun Dec  8 11:49:47 2013 jouana_j
*/

#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * size)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i = i + 1;
    }
  i =  0;
  if ((str = malloc(sizeof(*str) * (size + 1))) == NULL)
      return (NULL);
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i = i + 1;
    }
  free(tmp);
  return (str);
}
