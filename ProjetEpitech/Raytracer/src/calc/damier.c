/*
** damier.c for damier.c in /home/julien_t/Desktop
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sun Jun  8 16:53:55 2014 julien_t
** Last update Sun Jun  8 19:21:22 2014 daniel_d
*/

#include "ray.h"

int     simple(float nb)
{
  int	a;
  int	b;
  int	r;

  a = floorf(nb);
  b = ceilf(nb);
  r = (a + b) / 2;
  if (r % 2)
    return (0);
  else
    return (1);
}

int	damier(t_object obj, t_color *color)
{
  if (obj.damier == 1)
    {
      if (simple(obj.p.z) == 0)
        {
          if (((simple(obj.p.x) == 0) && (simple(obj.p.y)) == 0) ||
              ((simple(obj.p.x) == 1) && (simple(obj.p.y) == 1)))
            *color = my_color(*color, 255, 255, 255);
          else
            *color = my_color(*color, 0, 0, 0);
        }
      else
        {
          if (((simple(obj.p.x) == 0) && (simple(obj.p.y)) == 0) ||
              ((simple(obj.p.x) == 1) && (simple(obj.p.y) == 1)))
            *color = my_color(*color, 0, 0, 0);
          else
            *color = my_color(*color, 255, 255, 255);
        }
      return (1);
    }
  return (0);
}
