/*
** expose.c for expose in /home/daniel_d/rendu/Pmp/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 03:10:12 2014 daniel_d
** Last update Fri Jun 27 03:11:41 2014 daniel_d
*/
#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

int     gere_expose_paint(t_window *win)
{
  if ((mlx_put_image_to_window
       (win->mlx_ptr, win->win_paint, win->img_paint, 0, 0)) == 0)
    return (0);
  return (0);
}

int	gere_expose_color(t_window *win)
{
    if ((mlx_put_image_to_window
       (win->mlx_ptr, win->win_color, win->img_color, 0, 0)) == 0)
    return (0);
  return (0);
}

int	gere_expose_menu(t_window *win)
{
  if ((mlx_put_image_to_window
       (win->mlx_ptr, win->win_menu, win->img_menu, 0, 0)) == 0)
    return (0);
  return (0);
}
