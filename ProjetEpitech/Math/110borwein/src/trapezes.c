/*
** trapezes.c for trap in /home/daniel_d/rendu/110borwein/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Apr 16 15:35:32 2014 daniel_d
** Last update Sun Apr 20 19:18:21 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "borwein.h"
#include "my.h"

void	trapezes(double n)
{
  double	a;
  double	i;
  double	h;
  double	result;
  double	res;

  a = 0;
  i = 1;
  h = (5000 - a) / 10000;
  result = 0;
  while (i < 5000)
    {
      result = result + calc(n, (a + i * h));
      i++;
    }
  result = ((result * 2) + calc(n, a) + calc(n, 5000)) * ((5000 - a) / 20000);
  res = result - (M_PI / 2);
  printf("methode des trapezes :\n\tIO = %.10f\n\tdiff = %.10f\n", result, res);
}
