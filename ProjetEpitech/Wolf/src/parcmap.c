/*
** parcmap.c for wolf in /home/daniel_d/rendu/MUL_2013_wolf3d/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan 11 10:42:21 2014 daniel_d
** Last update Sun Jan 12 23:26:39 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "wolf.h"

int   map[YMAP][XMAP] =
  {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

void	affshellmap()
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (i <= 9)
    {
      my_putchar('\t');
      while (j <= 9)
        {
	  if (map[i][j] == 1)
	    my_printf("[]");
	  else if (map[i][j] == 0)
	    my_printf("  ");
	  else
	    my_printf("()");
	  j++;
        }
      my_putchar('\n');
      j = 0;
      i++;
    }
}

t_tr	my_calc_wolfx(t_tr all)
{
  t_myimg image;
  int	x;
  int	y;

  x = all.x;
  y = all.y;
  while (x <= XMAP && y <= YMAP)
    {
      x = all.xpp + all.k * all.x1;
      y = all.ypp + all.k * all.y1;
      all.k = all.k + 0.01;
      if (map[y][x] == 1)
	{
	  image = aff_wall_line(image , all.k, all.y1);
	}
    }
  return (all);
}

void	my_wolf_wall()
{
  t_tr	all;
  int	a;

  a = 1.047;
  all.d = 0.5;
  all.p = 1.0;
  all.x1 = all.d;
  all.y1 = (all.p * ((WSX / 2) - all.x) / WSX);
  all.xp = ((all.x * cos(a)) - (all.y * sin(a)));
  all.yp = ((all.x * sin(a)) + (all.y * cos(a)));
  all.xpp = all.xp + 0.5;
  all.ypp = all.yp + 0.5;
  while (all.y1 <= WSY)
    {
      all.y1 = (all.p * ((WSX / 2) - all.x) / WSX);
      all = my_calc_wolfx(all);
      all.y1 = all.y1 - 0.01;
      all.k = 0;
    }
}
