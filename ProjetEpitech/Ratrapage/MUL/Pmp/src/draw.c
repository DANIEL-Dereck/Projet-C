/*
** draw.c for draw in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 15:34:34 2014 daniel_d
** Last update Thu Jun 26 14:45:08 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

t_painter	*init_paint(t_painter *paint)
{
  paint->color = BLACK;
  paint->mode = SQUARE;
  paint->ep = EP1;
  paint->remp = 0;
  paint->coord.x = 0;
  paint->coord.y = 0;
  my_printf("Square mode   size 1 remp OFF");
  return (paint);
}

t_window	*draw(t_window *win)
{
  win->paint = init_paint(win->paint);
  mlx_mouse_hook(win->win_paint, gere_mouse, win);
  return (win);
}
