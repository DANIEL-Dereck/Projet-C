/*
** my_put_pixel_to_image.c for painter in /home/daniel_d/rendu/MUL/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun 23 13:05:31 2014 daniel_d
** Last update Tue Jun 24 17:54:50 2014 daniel_d
*/

#include "mlx_int.h"
#include "mlx.h"
#include "painter.h"
#include "my.h"

void	*my_pixel_put_to_image(void *img_ptr, int x, int y, unsigned int color)
{
  char  *data;
  int   bpp;
  int   sizeline;
  int   endline;
  int	i;

  if ((x <= WINX && x >= 0) && (y >= 0 && y <= WINY))
    {
      data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endline);
      i = x * (bpp / 8);
      i = y * sizeline + sizeline + i;
      data[i++] = color % 256;
      color = color / 256;
      data[i++] = color % 256;
      color = color / 256;
      data[i++] = color % 256;
      color = color / 256;
      data[i] = color % 256;
    }
  return (img_ptr);
}
