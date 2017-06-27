/*
** triangle.c for triangle in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 22:11:13 2014 daniel_d
** Last update Thu Jun 26 23:48:02 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	triangle_line(t_window *win, int i, int l, t_coord coord)
{
  while (i <= (coord.x + l))
    {
      win->paint->coord.x = i++;
      win->paint->coord.y = coord.y;
      brush(win);
    }
}

void	triangle(t_window *win)
{
  int	l;
  int	i;
  t_coord coord;

  l = 0;
  i = TRIANGLE_S * 2;
  coord.x = win->paint->coord.x;
  coord.y = win->paint->coord.y - TRIANGLE_S;
  while (i-- >= 0)
    {
      win->paint->coord.x = coord.x - l;
      win->paint->coord.y = coord.y;
      brush(win);
      l += 1;
      win->paint->coord.x = coord.x + l;
      win->paint->coord.y = coord.y;
      brush(win);
      coord.y += 1;
    }
  i = coord.x - l;
  triangle_line(win, i, l, coord);
}

void	draw_triangle_line(t_window *win)
{
  int	i;

  i = win->paint->coord.x;
  while (i <= win->paint->cor.x)
    {
      my_pixel_put_to_image(win->img_paint, i++,
			    win->paint->coord.y, win->paint->color);
    }
}

void	triangle_remp(t_window *win)
{
  int	l;
  int	i;
  t_coord coord;

  l = 0;
  i = TRIANGLE_S * 2;
  coord.x = win->paint->coord.x;
  coord.y = win->paint->coord.y - TRIANGLE_S;
  while (i-- >= 0)
    {
      win->paint->coord.x = coord.x - l;
      win->paint->coord.y = coord.y;
      win->paint->cor.x = coord.x + l;
      l += 1;
      draw_triangle_line(win);
      coord.y += 1;
    }
}
