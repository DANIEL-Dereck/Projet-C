/*
** get_next_line.c for get_next_line in /home/daniel_d/rendu/get_next_line-2018-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 19 11:43:10 2013 daniel_d
** Last update Mon Apr 14 15:29:35 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int     my_size(const int fd)
{
  char *buffer;
  int ret;
  int size;

  ret = 1;
  size = 0;
  buffer = malloc(sizeof(*buffer) * 2);
  if (buffer == NULL)
    return (-1);
  while (ret != 0)
    {
      ret = read(fd, buffer, 2);
      if (ret == -1)
        return (-1);
      size = size + ret;
    }
  free(buffer);
  return (size);
}

char	*my_get_line(const int fd, int len)
{
  static int i;
  char *buffer;
  int x;
  char *line;
  int ret;

  if ((buffer = malloc(sizeof(*buffer) * len + 1)) == NULL)
    return (NULL);
  if ((ret = read(fd, buffer, len)) == -1)
    return (NULL);
  x = i;
  while (buffer[x] != '\n' && buffer[x] != '\0')
    x++;
  if ((line = malloc(sizeof(*line) * (x - i))) == NULL)
    return (NULL);
  x = 0;
  while (buffer[i] != '\n' && buffer[i] != '\0')
    line[x++] = buffer[i++];
  line[x] = '\0';
  if (buffer[i++] == '\0')
    {
      i = 0;
      return (NULL);
    }
  return (line);
}

char	*get_next_line(const int fd)
{
  int	fds;
  char	*str;
  int	size;

  fds = fd;
  size = my_size(fd);
  str = my_get_line(fds, size);
  return (str);
}
