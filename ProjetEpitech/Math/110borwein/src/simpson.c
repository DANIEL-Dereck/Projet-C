/*
** simpson.c for sim in /home/daniel_d/rendu/110borwein/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Apr 16 15:35:41 2014 daniel_d
** Last update Sun Apr 20 19:14:03 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "borwein.h"
#include "my.h"

void	simpson(double n)
{
  double	a;
  double	i;
  double	h;
  double	result;
  double	res;
  double	final;
  double	fin;

  a = 0;
  i = a;
  h = (5000 - a) / 10000;
  result = 0;
  res = 0;
  final = 0;
  while (i < 5000)
    {
      result = result + calc(n, (a + i * h) + (h / 2));
      i++;
    }
  i = 1;
  while (i < 5000)
    {
      res = res + calc(n, (a + i * h));
      i++;
    }
  final = ((result * 4) + (res * 2) + calc(n, a) + calc(n, 5000)) * ((5000 - a) / 60000);
  fin = final - (M_PI / 2);
  printf("methode de Simpson:\n\tIO = %.10f\n\tdiff = %.10f\n", final, fin);
}
