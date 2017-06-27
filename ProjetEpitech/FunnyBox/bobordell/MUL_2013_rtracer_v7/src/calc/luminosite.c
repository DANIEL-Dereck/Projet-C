/*
** luminosite.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 16:57:53 2014 jouana_j
** Last update Mon Jun  2 15:06:26 2014 grasla_r
*/

#include "ray.h"

t_color    my_brillance(float alpha, t_color color, t_object obj)
{
  t_color color_spot;

  color_spot = my_color(color_spot, 100, 100, 100);
  color.r = color.r * alpha;
  color.v = color.v * alpha;
  color.b = color.b * alpha;
  /*  color.r = (color.r * (1 - obj.brill)) + ((color_spot.r) * obj.brill); */
  /* if (color.r > 255) */
  /*   color.r = 255; */
  /* color.v = (color.v * (1 - obj.brill)) + ((color_spot.v) * obj.brill); */
  /* if (color.v > 255) */
  /*   color.v = 255; */
  /* color.b = (color.b * (1 - obj.brill)) + ((color_spot.b) * obj.brill); */
  /* if (color.b > 255) */
  /* color.b = 255; */
  return (color);
}

float     alpha_tri(t_lum *lum)
{
  int i;
  float lim;
  float alpha_max;

  i = 0;
  lim = -9999;
  while (i <= 1)
    {
      if (lum[i].alpha >= lim)
        {
          lim = lum[i].alpha;
          alpha_max = lum[i].alpha;
        }
      i = i + 1;
    }
  return (alpha_max);
}

t_lum	my_calc_l(t_lum lum, t_object obj)
{
  lum.L.x = lum.pos.x - obj.p.x;
  lum.L.y = lum.pos.y - obj.p.y;
  lum.L.z = lum.pos.z - obj.p.z;
  lum.NL = sqrt(pow(obj.N.x, 2) + pow(obj.N.y, 2) + pow(obj.N.z, 2));
  lum.NL = lum.NL * sqrt(pow(lum.L.x, 2)
  			 + pow(lum.L.y, 2) + pow(lum.L.z, 2));
  lum.alpha = (obj.N.x * lum.L.x)
    + (obj.N.y * lum.L.y) + (obj.N.z * lum.L.z);
  lum.alpha = lum.alpha / lum.NL;
  return (lum);
}

void    luminosite(t_color *color, t_object obj, t_coord *V, t_rt rt)
{
  int i;
  float alpha;

  i = 0;
  obj.p.x = rt.eye->x + (obj.k * V->x);
  obj.p.y = rt.eye->y + (obj.k * V->y);
  obj.p.z = rt.eye->z + (obj.k * V->z);
  obj.p = pos_simple(obj.p, obj);
  obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
  obj = calcul_normale(obj);
  while (i <= 1)
    {
      rt.lum[i] = my_calc_l(rt.lum[i], obj);
      i++;
    }
  alpha = alpha_tri(rt.lum);
  if (alpha < 0.00001)
    *color = my_color(*color, 0, 0, 0);
  else if (alpha > 0.00001)
    *color = my_brillance(alpha, *color, obj);
  obj.p = rotate(obj.p , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p = pos_reel(obj.p, obj);
}
