/*
** ppti.c for wolf in /home/daniel_d/rendu/MUL_2013_wolf3d/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Jan  9 11:34:13 2014 daniel_d
** Last update Sun Mar 16 20:48:07 2014 daniel_d
*/

#include "mlx_int.h"
#include "mlx.h"
#include "rt.h"
#include "my.h"

void	*my_pixel_put_to_image(void *img_ptr, int x, int y, unsigned int color)
{
  char  *data;
  int   bpp;
  int   sizeline;
  int   endline;
  int	i;

  data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endline);
  i = (y * sizeline) + (sizeline - (x * 4));
  data[i++] = color % 256;
  color = color / 256;
  data[i++] = color % 256;
  color = color / 256;
  data[i++] = color % 256;
  color = color / 256;
  data[i] = color % 256;
  return (img_ptr);
}
