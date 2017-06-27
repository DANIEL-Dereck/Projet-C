/*
** val.c for jesus part in /home/daniel_d/rendu/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Apr 11 00:54:21 2014 daniel_d
** Last update Sun Apr 13 23:25:11 2014 daniel_d
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

void    my_value_write(int fdnf, char **plop, union1 *u, t_oct *oct)
{
  int i;
  int k;
  int x;

  i = 0;
  k = 0;
  x = 0;
  while (plop[i] != NULL && i <= 2)
    {
      if (plop[i][0] == 'r')
        {
	  jesus1(k, plop, i++, u);
	  jesus2(fdnf, u, oct);
        }
      else if (plop[i][0] == '%')
        {
	  jesus1(k, plop, i++, u);
	  jesus_back1(fdnf, x, oct, u);
	}
      else
        {
	  jesus1(k, plop, i++, u);
	  jesus_back2(fdnf, x, oct, u);
	}
    }
}
