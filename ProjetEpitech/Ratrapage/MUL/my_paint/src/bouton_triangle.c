/*
** bouton_triangle.c for triangle in /home/daniel_d/rendu/Pmp/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 03:02:10 2014 daniel_d
** Last update Mon Jun 30 13:04:37 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void    clean_bouton_triangle(t_window *win)
{
  t_coord cor;

  cor.x = 108;
  cor.y = 156;
  while (cor.y <= 295)
    {
      cor.x = 108;
      while (cor.x <= 199)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, BLACK);
        }
      cor.y++;
    }
}

void    remp_bouton_triangle(t_window *win)
{
  t_coord cor;

  cor.x = 108;
  cor.y = 156;
  while (cor.y <= 295)
    {
      cor.x = 108;
      while (cor.x <= 199)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}

void    bouton_triangle(t_window *win, int x, int y)
{
  if (x >= 103 && x <= 204 && y >= 151 && y <= 300)
    {
      remp_bouton_triangle(win);
      clean_bouton_circle(win);
      clean_bouton_brush(win);
      clean_bouton_square(win);
      win->paint->mode = TRIANGLE;
    }
  bouton_square_aff(win);
  bouton_circle_aff(win);
  bouton_brush_aff(win);
  bouton_triangle_aff(win);
}

void	  bouton_triangle_line(t_window *win, int i, int l, t_coord coord)
{
  while (i <= (coord.x + l))
    {
      win->paint->coord.x = i++;
      win->paint->coord.y = coord.y;
      my_pixel_put_to_image(win->img_menu, win->paint->coord.x
			    , win->paint->coord.y, ORANGE);
    }
}

void    bouton_triangle_aff(t_window *win)
{
  int   l;
  int   i;
  t_coord coord;

  l = 0;
  i = TR * 2;
  coord.x = 152;
  coord.y = 225 - TR;
  while (i-- >= 0)
    {
      win->paint->coord.x = coord.x - l;
      win->paint->coord.y = coord.y;
      my_pixel_put_to_image(win->img_menu, win->paint->coord.x
			    , win->paint->coord.y, ORANGE);
      l += 1;
      win->paint->coord.x = coord.x + l;
      win->paint->coord.y = coord.y;
      my_pixel_put_to_image(win->img_menu, win->paint->coord.x
			    , win->paint->coord.y, ORANGE);
      coord.y += 1;
    }
  i = coord.x - l;
  bouton_triangle_line(win, i, l, coord);
}
