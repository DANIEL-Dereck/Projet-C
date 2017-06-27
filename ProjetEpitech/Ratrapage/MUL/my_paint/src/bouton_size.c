/*
** bouton_size.c for size in /home/daniel_d/rendu/Pmp/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 03:01:22 2014 daniel_d
** Last update Mon Jun 30 12:48:36 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void    bouton_size(t_window *win, int x, int y)
{
  if (x >= x && x <= 68 && y >= 451 && y <= 600)
    {
      remp_bouton_size1(win);
      clean_bouton_size2(win);
      clean_bouton_size3(win);
      win->paint->ep = EP1;
    }
  else if (x >= 69 && x <= 136 && y >= 451 && y <= 600)
    {
      clean_bouton_size1(win);
      remp_bouton_size2(win);
      clean_bouton_size3(win);
      win->paint->ep = EP2;
    }
  else if (x >= 136 && x <= 204 && y >= 451 && y <= 600)
    {
      clean_bouton_size1(win);
      clean_bouton_size2(win);
      remp_bouton_size3(win);
      win->paint->ep = EP3;
    }
  bouton_size_aff_1(win);
  bouton_size_aff_2(win);
  bouton_size_aff_3(win);
}

void    bouton_size_aff_1(t_window *win)
{
  t_coord	cor;
  int	x;
  int	y;

  x = MENUX / 6;
  cor.y = 580;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
}

void    bouton_size_aff_2(t_window *win)
{
  t_coord	cor;
  int	x;
  int	y;

  x = 101;
  cor.y = 580;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
}

void    bouton_size_aff_3(t_window *win)
{
  t_coord	cor;
  int	x;
  int	y;

  x = MENUX - (MENUX / 6) - 2;
  cor.y = 580;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
  x++;
  y = 470;
  while (y <= cor.y)
    my_pixel_put_to_image(win->img_menu, x, y++, WHITE);
}
