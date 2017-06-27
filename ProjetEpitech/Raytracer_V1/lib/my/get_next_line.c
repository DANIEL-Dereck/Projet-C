/*
** get_next_line.c for get_next_line in /home/daniel_d/rendu/get_next_line-2018-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 19 11:43:10 2013 daniel_d
** Last update Wed Feb 19 14:16:59 2014 daniel_d
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char    *get_next_line(const int fd)
{
  static char   buffer[BUFFER_SIZE];
  static int    i;
  static int    c;
  int   r;
  char  *result;

  c = 0;
  i = 0;
  r = 0;
  if (fd <= -1)
    return (0);
  if ((result = malloc(sizeof(result) * (BUFFER_SIZE + 1))) == NULL)
    return (0);
  if (r == 0)
    r = read(fd, buffer, BUFFER_SIZE);
  if (i == r)
    return (0);
  while (i < r && buffer[i] != '\n')
    result[c++] = buffer[i++];
  if (buffer[i++] == '\n')
  result[c++] = '\0';
  return (result);
}
