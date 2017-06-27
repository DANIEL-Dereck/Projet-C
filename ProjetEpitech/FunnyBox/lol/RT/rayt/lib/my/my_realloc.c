/*
** my_realloc.c for my_realloc.c in /home/julien_t/rendu/MUL_2013_fdf/lib/my
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Dec  7 18:04:22 2013 julien_t
** Last update Sat Dec  7 18:21:25 2013 julien_t
*/

#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(sizeof(*tmp) * (size));
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i = i + 1;
    }
  i = 0;
  str = malloc(sizeof(*str) * (size + 1));
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i = i + 1;
    }
  free(tmp);
  return (str);
}
