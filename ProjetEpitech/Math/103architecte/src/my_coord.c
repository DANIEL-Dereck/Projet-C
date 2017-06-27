/*
** my_coord.c for 103 in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec 13 12:21:57 2013 daniel_d
** Last update Wed Dec 18 10:51:09 2013 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../Lib/include/my.h"
#include "../Lib/include/architect.h"

float   *coord_t(float *matrix, int param1, int param2)
{
  matrix[0] = (matrix[0] + param1);
  matrix[1] = (matrix[1] + param2);
  return (matrix);
}

float   *coord_h(float *matrix, int param1, int param2)
{
  matrix[0] = matrix[0] * param1;
  matrix[1] = matrix[1] * param2;
  return (matrix);
}

float   *coord_r(float *matrix, int param)
{
  float	temp;

  while (param >= 360)
    param = param - 360;
  if (param >= 90 && param <= 270)
    {
      temp = matrix[0];
      matrix[0] = matrix[1];
      matrix[1] = temp;
      return (matrix);
    }
  else
    return (matrix);
}

float   *coord_s(float *matrix, int param)
{
  float rad;
  float result;

  rad = 180 / M_PI;
  result = cosf(2 * param / rad);
  while (param >= 360)
    param = param - 360;
  matrix[0] = matrix[0] * result;
  return (matrix);
}

float	*my_coord(float *matrix, int *verif, char **av)
{
  int	i;

  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'T' && av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
        if (verif[0] >= 1)
          matrix = coord_t(matrix, my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'H' && av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
        if (verif[1] >= 1)
          matrix = coord_h(matrix, my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'R' && av[i][1] == '\0' && av[i + 1] != NULL)
        if (verif[2] >= 1)
          matrix = coord_r(matrix, my_getnbr(av[i + 1]));
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'S' && av[i][1] == '\0' && av[i + 1] != NULL)
	if (verif[3] >= 1)
	  matrix = coord_s(matrix, my_getnbr(av[i + 1]));
      i++;
    }
  return (matrix);
}
