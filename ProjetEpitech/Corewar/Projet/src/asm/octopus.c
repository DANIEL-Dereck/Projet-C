/*
** octopus.c for octopus in /home/daniel_d/rendu/CPE_2014_Corewar/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Apr 10 16:21:55 2014 daniel_d
** Last update Sun Apr 13 15:36:15 2014 grasla_r
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	*binarisation(char **param, int *tab, int i, int c)
{
  if (param[c][0] == 'r')
    {
      tab[i] = 0;
      tab[i + 1] = 1;
    }
  else if (param[c][0] == '%')
    {
      tab[i] = 1;
      tab[i + 1] = 0;
    }
  else
    {
      tab[i] = 1;
      tab[i + 1] = 1;
    }
  return (tab);
}

int	decimalisation(int *tab)
{
  int	i;

  i = 0;
  i = tab[7] * 1 + i;
  i = tab[6] * 2 + i;
  i = tab[5] * 4 + i;
  i = tab[4] * 8 + i;
  i = tab[3] * 16 + i;
  i = tab[2] * 32 + i;
  i = tab[1] * 64 + i;
  i = tab[0] * 128 + i;
  return (i);
}

int	octalisation(char **param)
{
  int	c;
  int	i;
  int	*tab;

  c = 0;
  i = 0;
  if ((tab = malloc(sizeof(*tab) * 8)) == NULL)
    return (-1);
  while (c <= 2 && param[c] != NULL)
    {
      tab = binarisation(param, tab, i, c);
      c = c + 1;
      i = i + 2;
    }
  i = decimalisation(tab);
  return (i);
}
