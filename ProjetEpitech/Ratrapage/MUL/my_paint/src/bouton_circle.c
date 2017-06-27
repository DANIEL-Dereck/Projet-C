/*
** bouton_circle.c for circle in /home/daniel_d/rendu/Pmp/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 03:00:08 2014 daniel_d
** Last update Mon Jun 30 13:04:59 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void    clean_bouton_circle(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 5;
  while (cor.y <= 145)
    {
      cor.x = 5;
      while (cor.x <= 97)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, BLACK);
        }
      cor.y++;
    }
}

void    remp_bouton_circle(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 5;
  while (cor.y <= 145)
    {
      cor.x = 5;
      while (cor.x <= 97)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}

void	bouton_circle(t_window *win, int x, int y)
{
  if (x >= 0 && x <= 102 && y >= 0 && y <= 150)
    {
      clean_bouton_triangle(win);
      remp_bouton_circle(win);
      clean_bouton_brush(win);
      clean_bouton_square(win);
      win->paint->mode = CIRCLE;
    }
  bouton_square_aff(win);
  bouton_circle_aff(win);
  bouton_brush_aff(win);
  bouton_triangle_aff(win);
}

void	bouton_circle_aff(t_window *win)
{
  int   i;
  t_coord coord;

  i = 0;
  win->paint->coord.x = 51;
  win->paint->coord.y = 75;
  while (i <= 360)
    {
      coord.x = win->paint->coord.x + CR * cos(i);
      coord.y = win->paint->coord.y + CR * sin(i);
      if (coord.x <= WINX && coord.y <= WINY)
	my_pixel_put_to_image(win->img_menu, coord.x, coord.y, RED);
      i++;
    }
}
