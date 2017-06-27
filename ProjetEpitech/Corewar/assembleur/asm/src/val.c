/*
** val.c for jesus part in /home/daniel_d/rendu/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Apr 11 00:54:21 2014 daniel_d
** Last update Sat Apr 12 15:28:10 2014 daniel_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"

char    **my_param(char *str, char **params)
{
  int i;
  int k;
  int x;

  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      x = 0;
      params[k] = malloc(sizeof(*params) * 256);
      while (str[i] != ',' && str[i] != '\0')
        params[k][x++] = str[i++];
      k = k + 1;
      i = i + 1;
    }
  return (params);
}

int     my_value(char *str)
{
  int i;
  char *nbr;
  int k;

  nbr = malloc(sizeof(*nbr) * 10);
  k = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
        {
          nbr[k] = str[i];
          k = k + 1;
        }
      i = i + 1;
    }
  i = my_getnbr(nbr);
  return (i);
}

void	my_registe(char *plop, union1 *u, int fdnf)
{
  int	k;

  k = my_value(plop);
  u->a = k;
  write(fdnf, &u->tab[0], 1);
}

void	my_modulo(char *plop, union1 *u, int fdnf)
{
  int	k;
  int	x;

  k = my_value(plop);
  u->a = k;
  x = DIR_SIZE - 1;
  while (x >= 0)
    write(fdnf, &u->tab[x--], 1);
}

void    my_value_write(int fdnf, char **plop, union1 *u)
{
  int i;
  int k;
  int x;

  i = 0;
  while (plop[i] != NULL && i <= 3)
    {
      if (plop[i][0] == 'r')
	my_registe(plop[i], u, fdnf);
      else if (plop[i][0] == '%')
	my_modulo(plop[i], u, fdnf);
      else
        {
          k = my_value(plop[i]);
          u->a = k;
          x = IND_SIZE - 1;
          while (x >= 0)
            write(fdnf, &u->tab[x--], 1);
        }
      i = i + 1;
    }
}
