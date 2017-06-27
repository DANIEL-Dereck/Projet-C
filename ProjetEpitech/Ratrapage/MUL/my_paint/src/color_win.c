/*
** color_win.c for color_win in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 14:33:49 2014 daniel_d
** Last update Fri Jun 27 03:12:47 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

unsigned int *init_tab(unsigned int *tab)
{
  tab[0] = RED;
  tab[1] = BLUE;
  tab[2] = CYAN;
  tab[3] = BROWN;
  tab[4] = WHITE;
  tab[5] = GREEN;
  tab[6] = PURPLE;
  tab[7] = YELLOW;
  tab[8] = ORANGE;
  tab[9] = BLACK;
  return (tab);
}

t_window	*color_square(t_coord_square coord,
			      t_window *win, unsigned int color)
{
  int	x;
  int	y;

  x = coord.x1;
  while (x <= coord.x2)
    {
      y = coord.y1;
      while (y <= coord.y2)
	{
	  my_pixel_put_to_image(win->img_color, x, y, color);
	  y++;
	}
      x++;
    }
  return (win);
}

t_coord_square	init_coord(t_coord_square coord, int *i)
{
  *i = 0;
  coord.x1 = 0;
  coord.x2 = 50;
  coord.y1 = 0;
  coord.y2 = 50;
  return (coord);
}

t_window	*color_prep(t_window *win)
{
  int	l;
  int	i;
  unsigned int	*tab;
  t_coord_square	coord;

  if ((tab = malloc(sizeof(*tab) * 10)) == NULL)
    return (NULL);
  tab = init_tab(tab);
  coord = init_coord(coord, &i);
  while (i <= 9)
    {
      l = 1;
      while (l <= 5)
	{
	  win = color_square(coord, win, tab[i++]);
	  coord.x1 += 50;
	  coord.x2 += 50;
	  l++;
	}
      coord.y1 = 50;
      coord.y2 = 100;
      coord.x1 = 0;
      coord.x2 = 50;
    }
  return (win);
}

t_window	*color_win(t_window *win)
{
  if ((win->win_color = mlx_new_window(win->mlx_ptr
				       , COLORX, COLORY, NAMECOLOR)) == 0)
    return (win);
  if ((win->img_color = mlx_new_image(win->mlx_ptr, COLORX, COLORY)) == 0)
    return (win);
  win = color_prep(win);
  if ((mlx_put_image_to_window(win->mlx_ptr, win->win_color
                               , win->img_color, 0, 0)) == 0)
    return (win);
  mlx_mouse_hook(win->win_color, take_color, win);
  mlx_key_hook(win->win_color, gere_end, win);
  mlx_expose_hook(win->win_color, gere_expose_color, win);
  return (win);
}
