/*
** menu.c for menu in /home/daniel_d/rendu/Pmp/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jun 27 02:21:42 2014 daniel_d
** Last update Mon Jun 30 13:22:17 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

int	take_option(int keycode, int x, int y, t_window *win)
{
  if (keycode == LC)
    {
      bouton_square(win, x, y);
      bouton_brush(win, x, y);
      bouton_triangle(win, x, y);
      bouton_circle(win, x, y);
      bouton_remp(win, x, y);
      bouton_size(win, x, y);
      draw_limite(win);
    }
  if ((mlx_put_image_to_window(win->mlx_ptr, win->win_menu
                               , win->img_menu, 0, 0)) == 0)
    return (-1);
  return (0);
}

void	draw_mid(t_window *win, int y)
{
  int	x;

  x = 0;
  while (x <= MENUX)
    my_pixel_put_to_image(win->img_menu, x++, y, WHITE);
}

void	draw_limite(t_window *win)
{
  int	x;
  int	y;

  x = MENUX / 2;
  y = 0;
  while (y <= (MENUY - (MENUY / 4)))
    {
      my_pixel_put_to_image(win->img_menu, x, y, WHITE);
      my_pixel_put_to_image(win->img_menu, x + 1, y, WHITE);
      if ((y == (MENUY - MENUY / 2)) || (y == (MENUY - MENUY / 4)) ||
					 (y == (MENUY / 4)))
	  draw_mid(win, y);
      y++;
    }
  while (y <= MENUY)
    {
      my_pixel_put_to_image(win->img_menu, (MENUX - (MENUX / 3)), y, WHITE);
      my_pixel_put_to_image(win->img_menu, (MENUX / 3), y, WHITE);
      y++;
    }
}

t_window	*color_menu(t_window *win)
{
  draw_limite(win);
  remp_bouton_square(win);
  remp_bouton_size1(win);
  bouton_brush_aff(win);
  bouton_remp_aff(win);
  bouton_square_aff(win);
  bouton_size_aff_1(win);
  bouton_size_aff_2(win);
  bouton_size_aff_3(win);
  bouton_triangle_aff(win);
  bouton_circle_aff(win);
  return (win);
}

t_window	*menu(t_window *win)
{
  if ((win->win_menu = mlx_new_window(win->mlx_ptr
                                       , MENUX, MENUY, NAMEMENU)) == 0)
    return (win);
  if ((win->img_menu = mlx_new_image(win->mlx_ptr, MENUX, MENUY)) == 0)
    return (win);
  win = color_menu(win);
  if ((mlx_put_image_to_window(win->mlx_ptr, win->win_menu
                               , win->img_menu, 0, 0)) == 0)
    return (win);
  mlx_mouse_hook(win->win_menu, take_option, win);
  mlx_key_hook(win->win_menu, gere_end, win);
  mlx_expose_hook(win->win_menu, gere_expose_menu, win);
  return (win);
}
