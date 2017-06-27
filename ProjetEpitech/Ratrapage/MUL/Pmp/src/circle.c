/*
** circle.c for circle in /home/daniel_d/rendu/MUL/src/forme
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 18:01:57 2014 daniel_d
** Last update Thu Jun 26 17:18:06 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	circle(t_window *win)
{
  int	i;
  t_coord coord;

  i = 0;
  coord.x = win->paint->coord.x;
  coord.y = win->paint->coord.y;
  while (i <= 360)
    {
      win->paint->coord.x = coord.x + CIRCLE_S * cos(i);
      win->paint->coord.y = coord.y + CIRCLE_S * sin(i);
      if (coord.x <= WINX && coord.y <= WINY)
	brush(win);
      i++;
    }
}

void	circle_remp(t_window *win)
{
  int	l;
  int	i;
  int	r;
  t_coord coord;

  l = 0;
  coord.x = win->paint->coord.x;
  coord.y = win->paint->coord.y;
  while (l <= CIRCLE_S)
    {
      i = 0;
      r = CIRCLE_S - l;
      while (i <= 360)
	{
	  win->paint->coord.x = coord.x + r * cos(i);
	  win->paint->coord.y = coord.y + r * sin(i);
	  if (coord.x <= WINX && coord.y <= WINY)
	    brush(win);
	  i++;
	}
      l++;
    }
}
