/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/grasla_r/Documents/TP_raytracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Thu Feb  6 09:20:52 2014 grasla_r
** Last update Tue May 13 12:18:14 2014 jouana_j
*/

#include "ray.h"

t_color    my_color(t_color color, int r, int v, int b)
{
  color.r = r;
  color.v = v;
  color.b = b;
  return (color);
}

void    my_pixel_put_to_image(int x, int y, t_color *color, t_window *libx)
{
  int   i;

  x = 4  * x;
  i = libx->sizeline - x;
  y = libx->sizeline * y + i;
  libx->data[y] = color->b;
  libx->data[y + 1] = color->v;
  libx->data[y + 2] = color->r;
  libx->data[y + 3] = 0;
}
