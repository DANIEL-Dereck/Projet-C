/*
** brush.c for brush in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 22:10:03 2014 daniel_d
** Last update Wed Jun 25 14:21:56 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	brush_mode(t_window *win)
{
  if (win->paint->ep == EP1)
    win->paint->ep = EP2;
  else if (win->paint->ep == EP2)
    win->paint->ep = EP3;
  else if (win->paint->ep == EP3)
    win->paint->ep = EP1;
}

void	brush_size(t_window *win)
{
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x + 1,
			win->paint->coord.y + 1, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x - 1,
			win->paint->coord.y - 1, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x - 1,
			win->paint->coord.y + 1, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x + 1,
			win->paint->coord.y - 1, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x + 2,
			win->paint->coord.y, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x - 2,
			win->paint->coord.y, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x,
			win->paint->coord.y + 2, win->paint->color);
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x,
			win->paint->coord.y - 2, win->paint->color);
}

void	brush(t_window *win)
{
  my_pixel_put_to_image(win->img_paint, win->paint->coord.x,
			win->paint->coord.y, win->paint->color);
  if (win->paint->ep == EP2 || win->paint->ep == EP3)
    {
      my_pixel_put_to_image(win->img_paint, win->paint->coord.x + 1,
			    win->paint->coord.y, win->paint->color);
      my_pixel_put_to_image(win->img_paint, win->paint->coord.x - 1,
			    win->paint->coord.y, win->paint->color);
      my_pixel_put_to_image(win->img_paint, win->paint->coord.x,
			    win->paint->coord.y + 1, win->paint->color);
      my_pixel_put_to_image(win->img_paint, win->paint->coord.x,
			    win->paint->coord.y - 1, win->paint->color);
      if (win->paint->ep == EP3)
	brush_size(win);
    }
}
