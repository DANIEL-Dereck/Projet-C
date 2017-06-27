/*
** wolff.c for wolfTP in /home/daniel_d/TP/Wolf3d/Wolf3d-TP/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jan 10 09:15:30 2014 daniel_d
** Last update Sun Jan 12 23:26:53 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "wolf.h"

int	my_wolf()
{
  t_window      *wd;
  t_myimg	im;

  if ((wd = malloc(sizeof(*wd))) == NULL)
    return (0);
  if ((wd->mlx = mlx_init()) == 0)
    {
      my_printf("ENV ERROR\n");
      return (0);
    }
  if ((wd->win = mlx_new_window(wd->mlx, WSX, WSY, "Wolf3D")) == 0)
    return (0);
  if ((im.img_ptr = mlx_new_image(wd->mlx, WSX, WSY)) == 0)
    return (0);
  affshellmap();
  im = my_wolfsky(im);
  im = my_wolfground(im);
  if ((mlx_put_image_to_window(wd->mlx, wd->win, im.img_ptr, 0, 0)) == 0)
      return (0);
  wd->img2_ptr = im.img_ptr;
  mlx_key_hook(wd->win, wolfkey, wd->mlx);
  mlx_expose_hook(wd->win, gere_expose, wd);
  mlx_loop(wd->mlx);
  return (0);
}
