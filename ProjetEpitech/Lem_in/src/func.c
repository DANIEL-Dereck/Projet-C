/*
** func.c for lem-in in /home/daniel_d/rendu/prog_elem/lem_in/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May  3 20:52:00 2014 daniel_d
** Last update Sun May  4 17:26:51 2014 besnie_b
*/

#include <stdlib.h>
#include "lem_in.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != '\0');
  i--;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int b;
  int c;

  b = my_strlen(s1);
  c = my_strlen(s2);
  if (s1 == NULL || s2 == NULL)
    return (-1);
  if (b != c)
    return (-1);
  b = 0;
  while (s1[b] != '\0')
    {
      if (s1[b] != s2[b])
        return (-1);
      b++;
    }
  return (0);
}

int	my_com(char *tab)
{
  if (my_strcmp(tab, "##start") == 0)
    return (1);
  else if (my_strcmp(tab, "##end") == 0)
    return (2);
  else
    return (0);
}
