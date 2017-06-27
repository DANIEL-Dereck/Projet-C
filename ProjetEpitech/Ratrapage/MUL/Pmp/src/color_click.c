/*
** color_click.c for color in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Jun 24 12:07:06 2014 daniel_d
** Last update Thu Jun 26 12:22:37 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

t_window	*color_select(t_window *win)
{
  t_coord_square coord;

  coord.x1 = 250;
  coord.y1 = 0;
  coord.x2 = 350;
  coord.y2 = 100;
  color_square(coord, win, win->paint->color);
  mlx_put_image_to_window(win->mlx_ptr, win->win_color , win->img_color, 0, 0);
  return (win);
}

t_window        *color_top(t_window *win, int x)
{
  if (x >= 0 && x <= 50)
    win->paint->color = RED;
  else if (x >= 51 && x <= 100)
    win->paint->color = BLUE;
  else if (x >= 101 && x <= 150)
    win->paint->color = CYAN;
  else if (x >= 151 && x <= 200)
    win->paint->color = BROWN;
  else if (x >= 201 && x <= 250)
    win->paint->color = WHITE;
  return (win);
}

t_window        *color_down(t_window *win, int x)
{
  if (x >= 0 && x <= 50)
    win->paint->color = GREEN;
  else if (x >= 51 && x <= 100)
    win->paint->color = PURPLE;
  else if (x >= 101 && x <= 150)
    win->paint->color = YELLOW;
  else if (x >= 151 && x <= 200)
    win->paint->color = ORANGE;
  else if (x >= 201 && x <= 250)
    win->paint->color = BLACK;
  return (win);
}

int     take_color(int keycode, int x, int y, t_window *win)
{
  if (keycode == 1)
    {
      if (y >= 0 && y <= 50)
        win = color_top(win, x);
      else if (y >= 51 && y <= 100)
        win = color_down(win, x);
      color_select(win);
    }
  return (0);
}

void    color_key(t_window *win)
{
  if (win->paint->color_mode == 0)
    {
      win->paint->color_mode = 1;
      win = color_win(win);
    }
  else if (win->paint->color_mode == 1)
    {
      win->paint->color_mode = 0;
      mlx_destroy_window(win->mlx_ptr, win->win_color);
    }
}
