/*
** luminosite.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 16:57:53 2014 jouana_j
** Last update Sun Jun  8 23:09:59 2014 daniel_d
*/

#include "ray.h"

t_color    my_brillance(t_color color, t_object obj, t_rt *rt, int i)
{
  color.r = color.r * rt->lum[i].alpha;
  color.v = color.v * rt->lum[i].alpha;
  color.b = color.b * rt->lum[i].alpha;
  color.r = color.r + (obj.brill * rt->lum[i].color.r * rt->lum[i].alpha);
  if (color.r > 255)
    color.r = 255;
  color.v = color.v + (obj.brill * rt->lum[i].color.v * rt->lum[i].alpha);
  if (color.v > 255)
    color.v = 255;
  color.b = color.b + (obj.brill * rt->lum[i].color.b * rt->lum[i].alpha);
  if (color.b > 255)
    color.b = 255;
  return (color);
}

float     alpha_tri(t_lum *lum)
{
  int i;
  float lim;
  float alpha_max;

  i = 0;
  alpha_max = 0;
  lim = -9999;
  while (i <= lum->nb_spot)
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

t_coord	my_calc_p(t_object obj, t_rt *rt, t_coord *V)
{
  t_coord p;
  p.x = rt->eye->x + (obj.k * V->x);
  p.y = rt->eye->y + (obj.k * V->y);
  p.z = rt->eye->z + (obj.k * V->z);
  return (p);
}
