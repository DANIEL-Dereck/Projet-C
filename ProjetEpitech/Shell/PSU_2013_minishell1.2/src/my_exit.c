/*
** my_exit.c for my_exit in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Apr 21 10:04:54 2014 daniel_d
** Last update Thu Apr 24 15:36:46 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"

int	my_exit(char *buffer)
{
  char	*str;
  int	i;
  int	l;
  int	returnval;

  i = 0;
  l = 0;
  if ((str = malloc(sizeof(str) * (my_strlen(buffer) - 6))) == NULL)
    return (-1);
  if (my_strcmp("exit\n", buffer) == 2)
    returnval = 0;
  else
    {
      while (buffer[i] != ' ')
	i++;
      while (buffer[i] != '\0' && buffer[i] != '\n')
	str[l++] = buffer[i++];
      my_printf("%s\n", str);
      returnval = my_getnbr(str);
    }
  free(buffer);
  free(str);
  return (returnval);
}
