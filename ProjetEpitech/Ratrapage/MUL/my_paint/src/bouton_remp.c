/*
** bouton_remp.c for remp in /home/daniel_d/rendu/Pmp/src/bouton
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 03:00:38 2014 daniel_d
** Last update Mon Jun 30 11:44:17 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	clean_bouton_remp(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 306;
  while (cor.y <= 445)
    {
      cor.x = 5;
      while (cor.x <= 97)
	{
	  my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, BLACK);
	}
      cor.y++;
    }
}

void	remp_bouton_remp(t_window *win)
{
  t_coord cor;

  cor.x = 5;
  cor.y = 306;
  while (cor.y <= 445)
    {
      cor.x = 5;
      while (cor.x <= 97)
	{
	  my_pixel_put_to_image(win->img_menu, cor.x++, cor.y, GRAY);
	}
      cor.y++;
    }
}

void	bouton_remp(t_window *win, int x, int y)
{
  if (x >= 0 && x <= 102 && y >= 301 && y <= 450)
    {
      if (win->paint->remp == 1)
	{
	  clean_bouton_remp(win);
	  win->paint->remp = 0;
	}
      else if (win->paint->remp == 0)
	{
	  win->paint->remp = 1;
	  remp_bouton_remp(win);
	}
    }
  bouton_remp_aff(win);
}

void	bouton_remp_aff_remp(t_window *win)
{
  int	i;
  int	l;
  t_coord_square cor;

  cor.x1 = 65 - RR;
  cor.x2 = 65 + RR;
  cor.y1 = 390 - RR;
  cor.y2 = 390 + RR;
  l = cor.y1;
  while (l <= cor.y2)
    {
      i = cor.x1;
      while (i <= cor.x2)
	{
	  my_pixel_put_to_image(win->img_menu, i++, l, PURPLE);
	}
      l++;
    }
}

void	bouton_remp_aff(t_window *win)

{
  int	i;
  t_coord_square cor;

  cor.x1 = 40 - RR;
  cor.x2 = 40 + RR;
  cor.y1 = 370 - RR;
  cor.y2 = 370 + RR;
  i = cor.x1;
  while (i <= cor.x2)
    my_pixel_put_to_image(win->img_menu, i++, cor.y1, PURPLE);
  i = cor.x1;
  while (i <= cor.x2)
    my_pixel_put_to_image(win->img_menu, i++, cor.y2, PURPLE);
  i = cor.y1;
  while (i <= cor.y2)
    my_pixel_put_to_image(win->img_menu, cor.x1, i++, PURPLE);
  i = cor.y1;
  while (i <= cor.y2)
    my_pixel_put_to_image(win->img_menu, cor.x2, i++, PURPLE);
  bouton_remp_aff_remp(win);
}
