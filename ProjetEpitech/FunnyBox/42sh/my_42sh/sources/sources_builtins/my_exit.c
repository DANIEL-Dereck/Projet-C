/*
** my_exit.c for my_exit in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Apr 21 10:04:54 2014 daniel_d
** Last update Sat May 24 18:41:45 2014 bouchard alexandre
*/

#include "../../include/sh.h"
#include "../../include/my.h"

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
  if (my_strcmp("exit", buffer) == 0)
    returnval = 0;
  else
    {
      while (buffer[i] != ' ')
	i++;
      i++;
      while (buffer[i] != '\0')
	str[l++] = buffer[i++];
      returnval = my_getnbr(str);
    }
  free(str);
  return (returnval);
}
