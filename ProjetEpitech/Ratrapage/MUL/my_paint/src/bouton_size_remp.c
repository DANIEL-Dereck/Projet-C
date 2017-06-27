/*
** bouton_size_remp.c for remp in /home/daniel_d/rendu/my_paint/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 30 11:47:30 2014 daniel_d
** Last update Mon Jun 30 12:43:49 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void    remp_bouton_size1(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 455;
  while (cor.y <= 595)
    {
      cor.x = 5;
      while (cor.x <= 63)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}

void    remp_bouton_size2(t_window *win)
{
  t_coord cor;

  cor.x = 73;
  cor.y = 455;
  while (cor.y <= 595)
    {
      cor.x = 73;
      while (cor.x <= 131)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}

void    remp_bouton_size3(t_window *win)
{
  t_coord cor;

  cor.x = 141;
  cor.y = 455;
  while (cor.y <= 595)
    {
      cor.x = 141;
      while (cor.x <= 199)
        {
          my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
        }
      cor.y++;
    }
}
