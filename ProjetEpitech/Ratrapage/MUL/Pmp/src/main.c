/*
** main.c for Pimp my Paint in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 12:51:56 2014 daniel_d
** Last update Thu Jun 26 18:42:04 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

t_window *init_background(t_window *win)
{
  int	x;
  int	y;

  y = 0;
  while (y <= WINY)
    {
      x = 0;
      while (x <= WINX)
	{
	  my_pixel_put_to_image(win->img_paint, x, y, WHITE);
	  x++;
	}
      y++;
    }
  mlx_put_image_to_window(win->mlx_ptr, win->win_paint , win->img_paint, 0, 0);
  return (win);
}

int	main_painter(t_window *win)
{
  if ((win->paint = malloc(sizeof(*win->paint))) == NULL)
    return (-1);
  win->paint->color_mode = 0;
  win = init_background(win);
  draw(win);
  color_win(win);
  mlx_key_hook(win->win_paint, gere_key, win);
  mlx_expose_hook(win->win_paint, gere_expose_paint, win);
  mlx_loop(win->mlx_ptr);
  free(win->paint);
  return (0);
}

void	usage()
{
  my_printf("key list :\n\t%c = brush mode\n", ZERO);
  my_printf("\t%c = square mode\n\t%c = circle mode\n", ONE, TWO);
  my_printf("\t%c = triangle mode\n\t%c = clean window\n", THREE, FOUR);
  my_printf("\t%c = change thickness\n\t%c = filling\n", EP, REMP);
}

int	main()
{
  t_window *win;

  if ((win = malloc(sizeof(*win))) == NULL)
    return (-1);
  if ((win->mlx_ptr = mlx_init()) == 0)
    {
      my_printf("ERROR: empty environment\n");
      return (-1);
    }
  usage();
  if ((win->win_paint = mlx_new_window(win->mlx_ptr
					 , WINX, WINY, NAMEPAINT)) == 0)
    return (-1);
  if ((win->img_paint = mlx_new_image(win->mlx_ptr, WINX, WINY)) == 0)
    return (-1);
  if (main_painter(win) == -1)
    return (-1);
  free(win);
  return (0);
}
