/*
** get_next_line.c for my_get_next_line in /home/cordon_b/rendu/CPE_2013_getnextline
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Wed Nov 20 18:31:40 2013 cordon_b
** Last update Sat Nov 23 15:31:13 2013 cordon_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*my_realloc(char *ptr, unsigned int size)
{
  char	*tmp;
  unsigned int	i;

  i = 0;
  tmp = malloc((size + 1) * sizeof (*tmp));
  if (tmp == NULL)
    return (NULL);
  while (i < size + 1)
    tmp[i++] = 0;
  i = 0;
  while (ptr && i < size && ptr[i])
    {
      tmp[i] = ptr[i];
      i++;
    }
  tmp[i] = '\0';
  if (ptr != NULL)
    free(ptr);
  return (tmp);
}

char	*my_get_line(const int fd, char *str, int i, int size)
{
  static char   buffer[READ + 1];
  static int    a;
  static int    ret;

  while (1)
    {
      if (a == 0 || buffer[a] == 0)
        {
          if ((ret = read(fd, buffer, READ)) <= 0)
            return (str);
          buffer[ret] = '\0';
          a = 0;
        }
      str = my_realloc(str, (size += ret));
      while (str && buffer[a])
        {
          if (buffer[a] == '\n')
            {
              a++;
              return (str);
            }
          str[i++] = buffer[a++];
        }
    }
  return (str);
}

char	*get_next_line(const int fd)
{
  char	*str;
  int	i;
  int	size;

  str = NULL;
  size = 0;
  i = 0;
  return (my_get_line(fd, str, i, size));
}
