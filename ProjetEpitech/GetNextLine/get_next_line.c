/*
** get_next_line.c for get_next_line in /home/daniel_d/rendu/get_next_line-2018-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 19 11:43:10 2013 daniel_d
** Last update Sat Nov 30 22:35:02 2013 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(const int fd)
{
  static char	*unnom;
  char	*buffer;
  char	*str;
  int	i;
  int	a;

  i = 0;
  a = 0;
  str = malloc(sizeof(str) * BUFFER_SIZE);
  if (str == NULL)
    return (NULL);
  buffer = malloc(sizeof(buffer) * BUFFER_SIZE);
  if (buffer == NULL)
    return (NULL);
  if (read(fd, buffer, BUFFER_SIZE) == 0)
    return (NULL);
  while (buffer[i] != '\n')
    str[a++] = buffer[i++];
  while (buffer[i] != '\0')
    unnom[a++] = buffer[i++];
  free(buffer);
  return (str);
}

