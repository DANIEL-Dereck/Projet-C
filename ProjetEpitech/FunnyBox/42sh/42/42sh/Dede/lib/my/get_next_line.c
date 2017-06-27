/*
** get_next_line.c for get_next_line in /home/daniel_d/rendu/get_next_line-2018-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 19 11:43:10 2013 daniel_d
** Last update Fri May 16 10:07:52 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;
  int	len;

  if (str == NULL)
    return (NULL);
  len = my_strlen(str);
  if ((tmp = malloc(sizeof(*tmp) * len)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  free(str);
  if ((str = malloc(sizeof(*str) * (len + size))) == NULL)
    return (NULL);
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i++;
    }
  free(tmp);
  return (str);
}

char	*get_next_line(const int fd)
{
  char	*str;
  char	*buffer;
  int	i;

  i = 0;
  if ((buffer = malloc(sizeof(*buffer) * 1)) == NULL)
    return (NULL);
  if ((str = malloc(sizeof(*str) * 1)) == NULL)
    return (NULL);
  while (buffer[0] != '\n' && read(fd, buffer, 1) != -1)
    {
      str[i] = buffer[0];
      if (buffer[0] != '\n')
	my_realloc(str, 1);
    }
  return (str);
}

