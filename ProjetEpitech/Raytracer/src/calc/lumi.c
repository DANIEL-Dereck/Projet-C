/*
** lumi.c for lumi in /home/daniel_d/rendu/MUL_2013_rtracer/src/calc
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Jun  8 23:08:10 2014 daniel_d
** Last update Sun Jun  8 23:23:31 2014 daniel_d
*/

#include "ray.h"

t_color         my_final_color(t_color f_color, t_color color)
{
  f_color.r = f_color.r + color.r;
  f_color.v = f_color.v + color.v;
  f_color.b = f_color.b + color.b;
  return (f_color);
}

t_color         my_final_final_color(t_color f_color, t_rt *rt)
{
  f_color.r = f_color.r / rt->lum->nb_spot;
  f_color.v = f_color.v / rt->lum->nb_spot;
  f_color.b = f_color.b / rt->lum->nb_spot;
  return (f_color);
}

t_color         *my_color_brillance(t_rt *rt, t_color *color, t_object obj)
{
  int i;
  t_color *f_color;

  i = 0;
  if ((f_color = malloc(sizeof(*f_color))) == NULL)
    return (f_color);
  *f_color = my_color(*f_color, 0, 0, 0);
  while (i < rt->lum->nb_spot)
    {
      if (rt->lum[i].alpha < 0.00001)
        {
          *color = my_color(*color, 0, 0, 0);
          *f_color = my_final_color(*f_color, *color);
        }
      else if (rt->lum[i].alpha > 0.00001)
        {
          *color = my_brillance(*color, obj, rt, i);
          *f_color = my_final_color(*f_color, *color);
        }
      i = i + 1;
    }
  *f_color = my_final_final_color(*f_color, rt);
  *color = my_color(*color, f_color->r, f_color->v, f_color->b);
  return (color);
}

void    luminosite(t_color *color, t_object obj, t_coord *V, t_rt *rt)
{
  int i;
  t_coord *pos;

  if ((pos = malloc(sizeof(t_coord*))) == NULL)
    return;
  *V = pos_simple(rt->eye, V, &obj, pos);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *rt->eye = rotate(*rt->eye , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p = my_calc_p(obj, rt, V);
  obj = calcul_normale(obj, pos);
  obj.p = rotate(obj.p, obj.angle.x, obj.angle.y, obj.angle.z);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  *rt->eye = rotate(*rt->eye , obj.angle.x, obj.angle.y, obj.angle.z);
  *V = pos_reel(rt->eye, V, &obj, pos);
  i = 0;
  while (i <= rt->lum->nb_spot)
    {
      rt->lum[i] = my_calc_l(rt->lum[i], obj);
      i++;
    }
  color = my_color_brillance(rt, color, obj);
}
