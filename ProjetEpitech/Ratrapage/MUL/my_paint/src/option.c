/*
** option.c for pimp_my_paint in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 13:09:08 2014 daniel_d
** Last update Mon Jun 30 11:04:16 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

int	gere_mouse(int	keycode, int x, int y, t_window *win)
{
  win->paint->coord.x = x;
  win->paint->coord.y = y;
  win->paint->keycode = keycode;
  if (win->paint->remp == 0)
    {
      if (win->paint->mode == BRUSH && keycode == LC)
	brush(win);
      else if (win->paint->mode == SQUARE && keycode == LC)
	square(win);
      else if (win->paint->mode == CIRCLE && keycode == LC)
	circle(win);
      else if (win->paint->mode == TRIANGLE && keycode == LC)
	triangle(win);
    }
  else
    remp_tri(keycode, win);
  mlx_put_image_to_window(win->mlx_ptr, win->win_paint
			  , win->img_paint, 0, 0);
  return (0);
}

int	gere_end(int keycode, t_window *win)
{
  if (keycode == ECHAP)
    {
      free(win->paint);
      free(win);
      exit(0);
    }
  return (0);
}

int     gere_key(int keycode, t_window *win)
{
  if (keycode == FOUR)
    init_background(win);
  else if (keycode == ECHAP)
    gere_end(ECHAP, win);
  return (0);
}
