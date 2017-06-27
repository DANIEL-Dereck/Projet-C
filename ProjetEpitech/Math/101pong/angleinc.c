/*
** angleinc.c for 101pong in /home/daniel_d/rendu/101pong
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 12 12:41:12 2013 daniel_d
** Last update Sun Nov 17 20:55:08 2013 daniel_d
*/

#include <math.h>
#include <stdio.h>
#include "my.h"
#include "pong.h"

int	angleinc(char *abst1, char *ordt1, char *lat1, char *abst, char *ordt, char *lat)
{
  float inc;
  int	k;
  int   x;
  int   y;
  int   l;

  l = my_getnbr(lat) - my_getnbr(lat1);
  y = my_getnbr(ordt) - my_getnbr(ordt1);
  x = my_getnbr(abst) - my_getnbr(abst1);


  k = (x * x) + (y * y);
  inc = acos(k / (sqrt(k + (l * l)) * sqrt(k)));
  inc = (inc * 180) / (M_PI);

  printf("L’angle d’incidence est de %.2f degrés.\n",inc);
  return (0);
}
