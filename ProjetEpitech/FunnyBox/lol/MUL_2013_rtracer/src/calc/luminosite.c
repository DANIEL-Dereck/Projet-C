/*
** luminosite.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 16:57:53 2014 jouana_j
** Last update Sat Jun  7 17:08:58 2014 jouana_j
*/

#include "ray.h"

t_color    my_brillance(float alpha, t_color color, t_object obj, t_lum *lum)
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
      //alpha_max += lum[i].alpha;
      i = i + 1;
    }
  //alpha_max = alpha_max / 3;
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

void    luminosite(t_color *color, t_object obj, t_coord *V, t_rt *rt)
{
  int i;
  float alpha;
  t_coord *pos;
  float ombr;

  i = 0;
  pos = malloc(sizeof(*pos));
  *V = pos_simple(rt->eye, V, &obj, pos);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *rt->eye = rotate(*rt->eye , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.pos = rotate(obj.pos , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p.x = rt->eye->x + (obj.k * V->x);
  obj.p.y = rt->eye->y + (obj.k * V->y);
  obj.p.z = rt->eye->z + (obj.k * V->z);
  obj.p = rotate(obj.p, obj.angle.x, obj.angle.y, obj.angle.z);
  obj.p.x += obj.pos.x;
  obj.p.y += obj.pos.y;
  obj.p.z += obj.pos.z;
  obj = calcul_normale(obj, pos);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  *rt->eye = rotate(*rt->eye , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.pos = rotate(obj.pos , obj.angle.x, obj.angle.y, obj.angle.z);
  *V = pos_reel(rt->eye, V, &obj, pos);
  while (i <= rt->lum->nb_spot)
    {
      rt->lum[i] = my_calc_l(rt->lum[i], obj);
      i++;
    }
  alpha = alpha_tri(rt->lum);
  if (alpha < 0.00001)
    *color = my_color(*color, 0, 0, 0);
  else if (alpha > 0.00001)
    *color = my_brillance(alpha, *color, obj, rt->lum);
  /* i = 0; */
  /* while (i <= 2) */
  /*   { */
  /*     ombr = ombr_sphere(obj, rt->lum[i].L); */
  /*     if (ombr > 0.00001 && ombr < 1.0000) */
  /*       *color = my_color(*color, color->r * 0.2, color->v * 0.2, color->b * 0.2); */
  /*     ombr = ombr_plan(obj, rt->lum[i].L); */
  /*     if (ombr > 0.00001 && ombr < 1.0000) */
  /*       *color = my_color(*color, color->r * 0.2, color->v * 0.2, color->b * 0.2); */
  /*     ombr = ombr_cone(obj, rt->lum[i].L); */
  /*     if (ombr > 0.00001 && ombr < 1.0000) */
  /*       *color = my_color(*color, color->r * 0.2, color->v * 0.2, color->b * 0.2); */
  /*     ombr = ombr_cyl(obj, rt->lum[i].L); */
  /*     if (ombr > 0.00001 && ombr < 1.0000) */
  /*       *color = my_color(*color, color->r * 0.2, color->v * 0.2, color->b * 0.2); */
  /*     i += 1; */
  /*   } */
}
