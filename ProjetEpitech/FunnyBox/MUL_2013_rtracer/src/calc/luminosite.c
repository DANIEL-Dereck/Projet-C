/*
** luminosite.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 16:57:53 2014 jouana_j
** Last update Sun Jun  8 19:23:21 2014 daniel_d
*/

#include "ray.h"

t_color    my_brillance(float alpha, t_color color, t_lum *lum)
{
  color.r = color.r * alpha * (lum->color.r / 255);
  color.v = color.v * alpha * (lum->color.v / 255);
  color.b = color.b * alpha * (lum->color.b / 255);
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

void	luminosite(t_color *color, t_object obj, t_coord *V, t_rt *rt)
{
  int i;
  float alpha;
  t_coord *pos;

  pos = malloc(sizeof(t_coord*));
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
  alpha = alpha_tri(rt->lum);
  if (damier(obj, color) == 0)
    {
      if (alpha < 0.00001)
	*color = my_color(*color, 0, 0, 0);
      else if (alpha > 0.00001)
	*color = my_brillance(alpha, *color, rt->lum);
    }
}
