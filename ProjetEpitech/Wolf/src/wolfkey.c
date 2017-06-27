/*
** wolfkey.c for wolf in /home/daniel_d/rendu/MUL_2013_wolf3d/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Jan  9 10:21:13 2014 daniel_d
** Last update Sun Jan 12 17:06:39 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "wolf.h"

int	wolfkey(int keycode)
{
  if (keycode == 65307)
      exit(1);
  if (keycode == 65362)
      my_printf("up   \r");
  if (keycode == 65364)
      my_printf("down \r");
  if (keycode == 65361)
      my_printf("left \r");
  if (keycode == 65363)
      my_printf("right\r");
  return (0);
}

int	gere_expose(t_window *wd)
{
  if ((mlx_put_image_to_window
       (wd->mlx, wd->win, wd->img2_ptr, 0, 0)) == 0)
    return (0);
  my_printf("Expose_Gerer");
  return (0);
}
