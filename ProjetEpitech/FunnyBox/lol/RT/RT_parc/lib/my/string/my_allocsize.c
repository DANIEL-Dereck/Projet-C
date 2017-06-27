/*
** my_allocsize.c for allocsize in /home/daniel_d/rendu/RT/RT_parc/lib/my/string
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri May 30 09:27:18 2014 daniel_d
** Last update Sat May 31 13:46:36 2014 daniel_d
*/

#include <stdlib.h>

int	my_allocsize(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}
