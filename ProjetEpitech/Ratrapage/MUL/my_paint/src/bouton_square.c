/*
** bouton_square.c for square in /home/daniel_d/rendu/Pmp/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 02:43:21 2014 daniel_d
** Last update Mon Jun 30 13:04:25 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void    clean_bouton_square(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 156;
  while (cor.y <= 295)
    {
      cor.x = 5;
      while (cor.x <= 97)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, BLACK);
        }
      cor.y++;
    }
}

void    remp_bouton_square(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 156;
  while (cor.y <= 295)
    {
      cor.x = 5;
      while (cor.x <= 97)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}

void    bouton_square(t_window *win, int x, int y)
{
  if (x >= 0 && x <= 102 && y >= 151 && y <= 300)
    {
      clean_bouton_triangle(win);
      clean_bouton_circle(win);
      clean_bouton_brush(win);
      remp_bouton_square(win);
      win->paint->mode = SQUARE;
    }
  bouton_square_aff(win);
  bouton_circle_aff(win);
  bouton_brush_aff(win);
  bouton_triangle_aff(win);
}

void    bouton_square_aff(t_window *win)
{
  int	i;
  t_coord_square cor;

  win->paint->coord.x = 51;
  win->paint->coord.y = 225;
  cor.x1 = win->paint->coord.x - SR;
  cor.x2 = win->paint->coord.x + SR;
  cor.y1 = win->paint->coord.y - SR;
  cor.y2 = win->paint->coord.y + SR;
  i = cor.x1;
  while (i <= cor.x2)
      my_pixel_put_to_image(win->img_menu, i++, cor.y1, GREEN);
  i = cor.x1;
  while (i <= cor.x2)
      my_pixel_put_to_image(win->img_menu, i++, cor.y2, GREEN);
  i = cor.y1;
  while (i <= cor.y2)
    my_pixel_put_to_image(win->img_menu, cor.x1, i++, GREEN);
  i = cor.y1;
  while (i <= cor.y2)
    my_pixel_put_to_image(win->img_menu, cor.x2, i++, GREEN);
}
