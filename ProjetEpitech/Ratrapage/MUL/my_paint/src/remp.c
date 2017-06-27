/*
** remp.c for remp in /home/daniel_d/rendu/Pmp/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Jun 26 14:58:57 2014 daniel_d
** Last update Mon Jun 30 12:50:42 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	remp_tri(int keycode, t_window *win)
{
  if (win->paint->remp == 1)
    {
      if (win->paint->mode == BRUSH && keycode == LC)
        brush(win);
      else if (win->paint->mode == SQUARE && keycode == LC)
        square_remp(win);
      else if (win->paint->mode == CIRCLE && keycode == LC)
        circle_remp(win);
      else if (win->paint->mode == TRIANGLE && keycode == LC)
        triangle_remp(win);
    }
}
