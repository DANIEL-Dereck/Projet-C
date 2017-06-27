/*
** rectangles.c for rec in /home/daniel_d/rendu/110borwein/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Apr 16 15:35:18 2014 daniel_d
** Last update Sun Apr 20 19:11:41 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "borwein.h"
#include "my.h"

void	rectangles(double n)
{
  double	a;
  double	i;
  double	h;
  double	result;
  double	res;

  a = 0;
  h = (5000 - a) / 10000;
  i = a;
  result = 0;
  while (i <= 5000)
    {
      result = result + calc(n, (a + i * h));
      i++;
    }
  result = result * h;
  res = result - (M_PI / 2);
  printf("methode des rectangles:\n\tIO = %.10f\n\tdiff = %.10f\n", result, res);
}
