/*
** my_strlen.c for strlen in /home/daniel_d/colle3-daniel_d/lib
**
** Made by daniel_d
** Login   <daniel_d@epitech.net>
**
** Started on  Thu May 15 19:12:41 2014 daniel_d
** Last update Thu May 15 19:49:01 2014 even_d
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i++] != '\0');
  i--;
  return (i);
}
