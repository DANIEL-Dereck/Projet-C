/*
** my_strcat.c for my_strcat in /home/mulot_i/rendu/CPE_2014_corewar
**
** Made by mulot_i
** Login   <mulot_i@epitech.net>
**
** Started on  Thu Apr  3 17:29:39 2014 mulot_i
** Last update Thu Apr  3 17:35:51 2014 mulot_i
*/

#include "corewar.h"

char	*my_strcat(char *from, char *with)
{
  int	i;
  int	n;
  char	*str;

  if ((str = malloc(sizeof(str) * my_strlen(from) + my_strlen(with) + 1)) == NULL)
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
