/*
** my_strcat.c for my_strcat.c in /home/le-fra_g/minishel/lib
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 17:14:26 2014 le-franc
** Last update Mon May 19 14:24:17 2014 le-franc
*/

#include "../include/my.h"

char	*my_strcat(char *from, char *with)
{
  int	i;
  int	n;
  char *str;

  if ((str = malloc(sizeof(str) * my_strlen(from)
		    + my_strlen(with) + 1)) == NULL)
    return (NULL);
  i = 0;
  n = 0;
  while (from[i] != 0)
    str[n++] = from[i++];
  i = 0;
  while (with[i] != 0)
    str[n++] = with[i++];
  str[n + 1] = '\0';
  return (str);
}
