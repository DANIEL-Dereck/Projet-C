/*
** luminosite.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 16:57:53 2014 jouana_j
** Last update Fri May  9 21:20:56 2014 jouana_j
*/

#include "ray.h"

void    my_brillance(float alpha, t_color *color, t_object obj)
{
  t_color color_spot;

  my_color(&color_spot, 255, 0, 0);
  color->r = color->r * alpha;
  color->v = color->v * alpha;
  color->b = color->b * alpha;
  /*  color->r = (color->r * (1 - obj.brill)) + ((color_spot.r) * obj.brill);
  if (color->r > 255)
    color->r = 255;
  color->v = (color->v * (1 - obj.brill)) + ((color_spot.v) * obj.brill);
  if (color->v > 255)
    color->v = 255;
  color->b = (color->b * (1 - obj.brill)) + ((color_spot.b) * obj.brill);
  if (color->b > 255)
  color->b = 255;*/
}

void	init_lum(t_lum *lum)
{
  lum[0].pos.x = -200.0;
  lum[0].pos.y = -300;
  lum[0].pos.z = 100;
  lum[1].pos.x = -200.0;
  lum[1].pos.y = 300;
  lum[1].pos.z = 100;
}

t_object	calcul_normale(t_object obj)
{
  if (obj.type == 's')
    {
      obj.N.x = obj.p.x;
      obj.N.y = obj.p.y;
      obj.N.z = obj.p.z;
      obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
    }
  else if (obj.type == 'p')
    {
      obj.N.x = 0;
      obj.N.y = 0;
      obj.N.z = 100;
      obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
    }
  else if (obj.type == 'y')
    {
      obj.N.x = obj.p.x;
      obj.N.y = obj.p.y;
      obj.N.z = 0;
      obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
    }
  else if (obj.type == 'c')
    {
      obj.N.x = obj.p.x;
      obj.N.y = obj.p.y;
      obj.N.z = -tan(25) * obj.p.z;
      obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
    }
  return (obj);
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

void    luminosite(t_color *color, t_object obj, coord *V, coord *eye)
{
  t_lum *lum;
  int i;
  float alpha;

  i = 0;
  lum = malloc(sizeof(*lum) * 2);
  obj.p.x = eye->x + (obj.k * V->x);
  obj.p.y = eye->y + (obj.k * V->y);
  obj.p.z = eye->z + (obj.k * V->z);
  init_lum(lum);
  obj = calcul_normale(obj);
  while (i <= 1)
    {
      lum[i].L.x = lum[i].pos.x - obj.p.x;
      lum[i].L.y = lum[i].pos.y - obj.p.y;
      lum[i].L.z = lum[i].pos.z - obj.p.z;
      lum[i].NL = sqrt(pow(obj.N.x, 2) + pow(obj.N.y, 2) + pow(obj.N.z, 2));
      lum[i].NL = lum[i].NL * sqrt(pow(lum[i].L.x, 2)
				   + pow(lum[i].L.y, 2) + pow(lum[i].L.z, 2));
      lum[i].alpha = (obj.N.x * lum[i].L.x)
	+ (obj.N.y * lum[i].L.y) + (obj.N.z * lum[i].L.z);
      lum[i].alpha = lum[i].alpha / lum[i].NL;
      i++;
    }
  alpha = alpha_tri(lum);
  if (alpha < 0.00001)
    my_color(color, 0, 0, 0);
  else if (alpha > 0.00001)
    my_brillance(alpha, color, obj);
  free(lum);
}
