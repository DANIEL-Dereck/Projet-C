/*
** my_func.c for func calc in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Dec 10 16:06:32 2013 daniel_d
** Last update Wed Dec 18 17:02:09 2013 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Lib/include/my.h"
#include "../Lib/include/architect.h"

float	*translation(float *tab, int param1, int param2)
{
  tab[2] = ((tab[0] + tab[1]) * param1) + tab[2];
  tab[5] = ((tab[3] + tab[4]) * param2) + tab[5];
  return (tab);
}

float	*homothetie(float *tab, int param1, int param2)
{
  tab[0] = (tab[0] * param1) + (tab[1] * 0) + (tab[2] * 0);
  tab[1] = (tab[0] * 0) + (tab[1] * param2) + (tab[2] * 0);
  tab[2] = (tab[0] * 0) + (tab[1] * 0) + (tab[2] * 1);

  tab[3] = (tab[3] * param1) + (tab[4] * 0) + (tab[5] * 0);
  tab[4] = (tab[3] * 0) + (tab[4] * param2) + (tab[5] * 0);
  tab[5] = (tab[3] * 0) + (tab[4] * 0) + (tab[5] * 1);

  tab[6] = (tab[6] * param1) + (tab[7] * 0) + (tab[8] * 0);
  tab[7] = (tab[6] * 0) + (tab[7] * param2) + (tab[8] * 0);
  tab[8] = (tab[6] * 0) + (tab[7] * 0) + (tab[8] * 1);
  return (tab);
}

float	*rotation(float *tab, int angle)
{
  float rad;
  float un;

  un = 1.000;
  rad = 180 / M_PI;
  if (tab[0] == 0.000)
    tab[0] = un;
  if (tab[1] == 0.000)
    tab[1] = un;
  if (tab[3] == 0.000)
    tab[3] = un;
  if (tab[4] == 0.000)
    tab[4] = un;
  tab[0] = tab[0] * cosf(angle / rad);
  tab[1] = tab[1] * (-sinf(angle / rad));
  tab[3] = tab[3] * sinf(angle / rad);
  tab[4] = tab[4] * cosf(angle / rad);
  return (tab);
}

float	*symetrie(float *tab, int angle)
{
  float	rad;

  rad = 180 / M_PI;
  tab[0] = (tab[0] * cosf(2 * angle / rad)) + (tab[1] * sinf(2 * angle / rad)) + (tab[2] * 0);
  tab[1] = (tab[0] * sinf(2 * angle / rad)) + (tab[1] * (-cosf(2 * angle / rad))) + (tab[2] * 0);
  tab[2] = (tab[0] * 0) + (tab[1] * 0) + (tab[2] * 1);
  tab[3] = (tab[3] * cosf(2 * angle / rad)) + (tab[4] * sinf(2 * angle / rad)) + (tab[5] * 0);
  tab[4] = (tab[3] * sinf(2 * angle / rad)) + (tab[4] * (-cosf(2 * angle / rad))) + (tab[5] * 0);
  tab[5] = (tab[3] * 0) + (tab[4] * 0) + (tab[5] * 1);
  tab[6] = (tab[6] * cosf(2 * angle / rad)) + (tab[7] * sinf(2 * angle / rad)) + (tab[8] * 0);
  tab[7] = (tab[6] * sinf(2 * angle / rad)) + (tab[7] * (-cosf(2 * angle / rad))) + (tab[8] * 0);
  tab[8] = (tab[6] * 0) + (tab[7] * 0) + (tab[8] * 1);
  return (tab);
}
