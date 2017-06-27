/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Wed Apr 23 16:40:15 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "borwein.h"
#include "my.h"

double  calc(double n, double x)
{
  double        res;
  int   k;

  res = 1;
  k = 0;
  while (k <= n)
    {
      if (x != 0 && ((2*k) + 1) != 0)
	res = res * (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
      k++;
    }
  return (res);
}

int	main(int ac, char **av)
{
  double	n;

  if (ac <= 1)
    {
      printf("%s [n]\n", av[0]);
      return (-1);
    }
  n = atof(av[1]);
  if ((n <= 9999999 && n >= 0) && (av[1][0] >= '0' && av[1][0] <= '9'))
    {
      rectangles(n);
      trapezes(n);
      simpson(n);
    }
  else
    printf("ERROR : Invalid number\n");
  return (0);
}
