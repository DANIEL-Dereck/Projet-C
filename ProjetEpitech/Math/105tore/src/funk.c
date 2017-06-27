/*
** funk.c for 105 in /home/daniel_d/rendu/105tore/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 22 09:09:34 2014 daniel_d
** Last update Wed Jan 22 17:13:50 2014 daniel_d
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "tore.h"

double   derive_f(double x, double *tab)
{
  double	result;

  result = ((tab[4] * pow(x, 3) * 4) + (tab[3] * pow(x, 2) * 3) + (tab[2] * x * 2) + tab[1]);
  return (result);
}

double	f(double x, double *tab)
{
  double	result;

  result = ((tab[4] * pow(x, 4)) + (tab[3] * pow(x, 3)) + (tab[2] * pow(x, 2)) + (tab[1] * x) + (tab[0]));
  return (result);
}

double	*tabinit(char **av)
{
  double	*tab;

  if ((tab = malloc(sizeof(*tab) * 5)) == NULL)
    return (0);
  tab[0] = atoi(av[2]);
  tab[1] = atoi(av[3]);
  tab[2] = atoi(av[4]);
  tab[3] = atoi(av[5]);
  tab[4] = atoi(av[6]);
  return (tab);
}

int	my_bis(char **av)
{
  double	eps;
  double	*tab;
  double	x;
  double	y;
  double	xm;
  int	l;
  int	i;
  int	a;

  l = 1;
  i = 1;
  x = 0;
  y = 1;
  a = 0;
  tab = tabinit(av); 
  eps = pow(10, -(atoi(av[7])));
  while (a < 101)
    {
      if ((fabs(x - y) / (2 * fabs(xm))) < eps && fabs(xm) != 0)
        {
          printf("f(x) = %e\n", f(xm, tab));
          return (0);
        }
      xm = ((x + y) / 2);
      printf("itération %d\tx = %.*f\n", l++, i++, xm);
      if (((f(x, tab) * f(xm, tab))) < 0)
	y = xm;
      else
	x = xm;
      a++;
    }
  printf("f(x) = %e\n", f(xm, tab));
  return (0);
}

int	my_newton(char **av)
{
  double	*tab;
  double	eps;
  double	x1;
  double	x0;
  int	a;
  int	i;

  a = 0;
  x0 = 0.5;
  x1 = 1;
  i = 1;
  eps = pow(10, -(atoi(av[7])));
  tab = tabinit(av);
  printf("point initial : %.1f\n", x0);
  while (a < 101)
    {
      if (derive_f(x0, tab) == 0)
        {
          my_printf("Dérivée égale à 0\n");
          return (0);
        }
      x1 = (x0 - (f(x0, tab) / derive_f(x0, tab)));    
      if ((fabs(x1 - x0) / fabs(x1)) < eps)
        {
          printf("f(x) = %e\n", f(x0, tab));
          return (0);
        }
      x0 = x1;
      printf("itération %d\tx = %.20f\n", i++, x1);
      a++;
    }
  return (0);
}

int	my_sec(char **av)
{
  double	*tab;
  double	eps;
  double	x1;
  double	xn;
  double	x0;
  int	i;
  int	a;

  i = 1;
  xn = 0.4;
  x0 = 0.8;
  x1 = 0.8;
  a = 0;
  tab = tabinit(av);
  eps = pow(10, -(atoi(av[7])));
  printf("point initial 1 : %.1f\n", xn);
  printf("point initial 2 : %.1f\n", x1);
  while (a < 101)
    {
      //x0 = ((f(xn, tab) - f(x0, tab)) / (xn - x0));
      if (derive_f(xn, tab) == 0)
        {
          my_printf("Dérivée égale à 0\n");
	  return (0);
        }
      x1 = xn - ((f(xn, tab) * (xn - x0)) / (f(xn, tab) - f(x0, tab)));
      if ((fabs(x1 - xn) / fabs(x1)) < eps)
        {
          printf("f(x) = %e\n", f(xn, tab));
          return (0);
        }
      printf("itération %d\tx = %.20f\n", i++, x1);
      a++;
    }
  return (0);
}
