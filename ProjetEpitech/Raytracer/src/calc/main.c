/*
** main.c for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 15:49:42 2014 grasla_r
** Last update Mon Jun 23 14:22:13 2014 daniel_d
*/

#include <unistd.h>
#include "ray.h"

int     my_expose(t_window *libx)
{
  if ((mlx_put_image_to_window
       (libx->mlx_ptr, libx->win_ptr, libx->img_ptr, 0, 0)) == 0)
    return (0);
  return (0);
}

int	gere_echap(int keycode, t_window *libx)
{
  if (keycode == 65307)
    {
      free(libx);
      exit(0);
    }
  return (0);
}

int	rt_main(t_eyep eyep, t_lumos *lumos, t_obj *item)
{
  t_window *libx;

  if ((libx = malloc(sizeof(*libx))) == NULL)
    return (-1);
  if ((libx->mlx_ptr = mlx_init()) == 0)
    return (-1);

  if ((libx->img_ptr = mlx_new_image(libx->mlx_ptr, WIN_X, WIN_Y)) == 0)
    return (-1);

  if ((libx->win_ptr = mlx_new_window(libx->mlx_ptr, WIN_X, WIN_Y, NAME)) == 0)
    return (-1);
  libx->data = mlx_get_data_addr(libx->img_ptr, &libx->bpp,
  				      &libx->sizeline, &libx->endian);
  remplir_image(libx, eyep, lumos, item);
  mlx_put_image_to_window(libx->mlx_ptr, libx->win_ptr,
  			  libx->img_ptr, 0, 0);
  mlx_key_hook(libx->win_ptr, gere_echap, libx);
  mlx_expose_hook(libx->win_ptr, my_expose, libx);
  mlx_loop(libx->mlx_ptr);
  free(libx);
  return (0);
}
