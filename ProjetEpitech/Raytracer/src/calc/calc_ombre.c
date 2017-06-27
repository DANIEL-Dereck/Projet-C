/*
** calc_ombre.c for rt in /home/jouana_j/Downloads/MUL_2013_rtracer/src/calc
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Sun Jun  8 03:20:14 2014 jouana_j
** Last update Sun Jun  8 23:18:46 2014 daniel_d
*/

#include "ray.h"

float	calc_ombre_color(int i, int j, t_object obj, t_rt *rt)
{
  float ombr;

  if (i != obj.num)
    {
      if (rt->obj[i].type == 's')
	ombr = ombr_sphere(rt->obj[i], rt->lum[j].L);
      else if (rt->obj[i].type == 'p')
	ombr = ombr_plan(rt->obj[i], rt->lum[j].L);
      else if (rt->obj[i].type == 'y')
	ombr = ombr_cyl(rt->obj[i], rt->lum[j].L);
    }
  return (ombr);
}

int	my_ombre(t_color *color, t_object obj, t_coord *V, t_rt *rt)
{
  int	i;
  int	j;
  float ombr;

  i = 0;
  while (i < obj.nb_obj)
    {
      obj.p.x = rt->eye->x + (obj.k * (V->x - rt->obj[i].pos.x));
      obj.p.y = rt->eye->y + (obj.k * (V->y - rt->obj[i].pos.y));
      obj.p.z = rt->eye->z + (obj.k * (V->z - rt->obj[i].pos.z));
      rt->obj[i].p = obj.p;
      j = 0;
      while (j < rt->lum->nb_spot)
        {
	  rt->lum[j] = my_calc_l(rt->lum[j], rt->obj[i]);
	  ombr = calc_ombre_color(i, j, obj, rt);
	  if (ombr >= 0.0001 && ombr <= 1.0000)
	    *color = my_color(*color, color->r * 0.2,
			      color->v * 0.2, color->b * 0.2);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}
