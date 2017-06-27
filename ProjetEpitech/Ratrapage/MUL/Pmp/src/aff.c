/*
** aff.c for aff in /home/daniel_d/rendu/Pmp/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jun 25 15:28:49 2014 daniel_d
** Last update Thu Jun 26 20:43:40 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	aff_remp(int keycode, t_window *win)
{
  if (win->paint->remp == 0 && (keycode == EP || keycode == ZERO ||
				keycode == ONE || keycode == TWO ||
				keycode == THREE || keycode == REMP))
    my_printf("remp OFF");
  else if (win->paint->remp == 1 && (keycode == EP || keycode == ZERO ||
				     keycode == ONE || keycode == TWO ||
				     keycode == THREE || keycode == REMP))
    my_printf("remp ON ");
}

void	aff_size(int keycode, t_window *win)
{
  if (win->paint->ep == EP1 && (keycode == ZERO || keycode == ONE ||
				keycode == TWO || keycode == THREE ||
				keycode == EP || keycode == REMP))
    my_printf("size 1 ");
  else if (win->paint->ep == EP2 && (keycode == ZERO || keycode == ONE ||
				     keycode == TWO || keycode == THREE ||
				     keycode == EP || keycode == REMP))
    my_printf("size 2 ");
  else if (win->paint->ep == EP3 && (keycode == ZERO || keycode == ONE ||
				     keycode == TWO || keycode == THREE ||
				     keycode == EP || keycode == REMP))
    my_printf("size 3 ");
}

void	aff_mode(int keycode, t_window *win)
{
  if (keycode == ZERO || ((keycode == EP || keycode == REMP) &&
			  win->paint->mode == BRUSH))
    my_printf("\rBrush mode    ");
  else if (keycode == ONE || ((keycode == EP || keycode == REMP) &&
			      win->paint->mode == SQUARE))
    my_printf("\rSquare mode   ");
  else if (keycode == TWO || ((keycode == EP || keycode == REMP) &&
			      win->paint->mode == CIRCLE))
    my_printf("\rCircle mode   ");
  else if (keycode == THREE || ((keycode == EP || keycode == REMP) &&
				win->paint->mode == TRIANGLE))
    my_printf("\rTriangle mode ");
  else if (keycode == FOUR)
    my_printf("\rWindow clean                 ");
  aff_size(keycode, win);
  aff_remp(keycode, win);
}
