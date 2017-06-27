/*
** square.c for square in /home/daniel_d/rendu/MUL/src/forme
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 18:02:07 2014 daniel_d
** Last update Thu Jun 26 15:15:49 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	square_1(t_window *win, t_coord_square cor)
{
  int	i;

  i = cor.x1;
  while (i <= cor.x2 && i <= WINX)
    {
      win->paint->coord.x = i++;
      win->paint->coord.y = cor.y1;
      brush(win);
    }
  i = cor.x1;
  while (i <= cor.x2 && i <= WINX)
    {
      win->paint->coord.x = i++;
      win->paint->coord.y = cor.y2;
      brush(win);
    }
}

void	square_2(t_window *win, t_coord_square cor)
{
  int	i;

  i = cor.y1;
  while (i <= cor.y2 && i <= WINY)
    {
      win->paint->coord.x = cor.x1;
      win->paint->coord.y = i++;
      brush(win);
    }
  i = cor.y1;
  while (i <= cor.y2 && i <= WINY)
    {
      win->paint->coord.x = cor.x2;
      win->paint->coord.y = i++;
      brush(win);
    }
}

void	square(t_window *win)
{
  t_coord_square cor;

  cor.x1 = win->paint->coord.x - SQUARE_S;
  cor.x2 = win->paint->coord.x + SQUARE_S;
  cor.y1 = win->paint->coord.y - SQUARE_S;
  cor.y2 = win->paint->coord.y + SQUARE_S;
  square_1(win, cor);
  square_2(win, cor);
}

void    square_remp(t_window *win)
{
  t_coord_square cor;
  int	l;
  int	i;

  cor.x1 = win->paint->coord.x - SQUARE_S;
  cor.x2 = win->paint->coord.x + SQUARE_S;
  cor.y1 = win->paint->coord.y - SQUARE_S;
  cor.y2 = win->paint->coord.y + SQUARE_S;
  l = cor.x1;
  while (l <= cor.x2)
    {
      win->paint->coord.x = l;
      i = cor.y1;
      while (i <= cor.y2)
	{
	  win->paint->coord.y = i;
	  brush(win);
	  i++;
	}
      l++;
    }
}
