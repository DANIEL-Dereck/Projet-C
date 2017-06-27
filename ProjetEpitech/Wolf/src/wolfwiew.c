/*
** wolfwiew.c for wolf in /home/daniel_d/TP/Wolf3d/Wolf3d-TP/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Jan 10 12:47:45 2014 daniel_d
** Last update Sun Jan 12 23:23:48 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "wolf.h"

t_myimg     my_wolfsky(t_myimg image)
{
  image.y = 0;
  image.x = 0;
  while (image.y <= WSY / 2)
    {
      while (image.x <= WSX)
        {
          image.img_ptr = my_pixel_put_to_image
	    (image.img_ptr, image.x, image.y, COLORS);
          image.x = image.x + 1;
        }
      image.x = 0;
      image.y = image.y + 1;
    }
  return (image);
}

t_myimg aff_wall_line(t_myimg image, double k, int x)
{
  int	i;

  i = ((WSY - (WSY * k)) / 2);
  my_printf(" -- a --");
  printf("%d\n", i);
  printf("%.2f\n", k);
  printf("%d\n", WSY);
  while (i <= (WSY - ((WSY - (WSY * k)) / 2)))
    image.img_ptr = my_pixel_put_to_image(image.img_ptr, x, i++, COLORW);
  my_printf(" -- a --");
  return (image);
}

t_myimg     my_wolfground(t_myimg image)
{
  image.x = 0;
  while (image.y <= WSY)
    {
      while (image.x <= WSX)
        {
          image.img_ptr = my_pixel_put_to_image
	    (image.img_ptr, image.x, image.y, COLORG);
          image.x = image.x + 1;
        }
      image.x = 0;
      image.y = image.y + 1;
    }
  return (image);
}

void    *clear_image(void *img_ptr, int	x, int	y)
{
  char  *data;
  int   bpp;
  int   sizeline;
  int   endline;
  int   i;

  data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endline);
  i = (y * sizeline) + (sizeline - (x * (bpp / 8)));
  while (i <= (WSY * sizeline) + (sizeline - (WSX * (bpp / 8))))
    {
      data[i++] = 0x00;
      data[i++] = 0x00;
      data[i++] = 0x00;
      data[i++] = 0x00;
    }
  return (img_ptr);
}
