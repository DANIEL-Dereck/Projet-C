/*
** ombre.c for rt in /home/grasla_r/rendu/MUL_2013_rtracer(V7)
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Tue Jun  3 16:44:53 2014 grasla_r
** Last update Sun Jun  8 04:17:48 2014 jouana_j
*/
#include "ray.h"

float     ombr_plan(t_object obj, t_coord L)
{
  float k;
  t_coord pos;

  pos_simple(&obj.p, &L, &obj, &pos);
  L = rotate(L , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p = rotate(obj.p , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  if (L.z > 0.01 || L.z < -0.01)
    {
      k = -(obj.p.x / L.z);
      L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
      obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
      pos_reel(&obj.p, &L, &obj, &pos);
      if (k > 0.00001)
	return (k);
      else
        return (2.0);
    }
  else
    {
      L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
      obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
      pos_reel(&obj.p, &L, &obj, &pos);
      return (2.0);
    }
}

float     ombr_sphere(t_object obj, t_coord L)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  pos_simple(&obj.p, &L, &obj, &pos);
  L = rotate(L , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p = rotate(obj.p , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  a = pow(L.x, 2) + pow(L.y, 2) + pow(L.z, 2);
  b = 2 * ((obj.p.x * L.x) + (obj.p.y * L.y) + (obj.p.z * L.z));
  c = pow(obj.p.x, 2) + pow(obj.p.y, 2) + pow(obj.p.z, 2) - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(&obj.p, &L, &obj, &pos);
  if (delta < 0.00001)
    return (2.0);
  else
    {
      obj = tri_k(a, b, delta, obj);
      return (obj.k);
    }
}

float     ombr_cyl(t_object obj, t_coord L)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  pos_simple(&obj.p, &L, &obj, &pos);
  L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(L.x, 2) + pow(L.y, 2);
  b = 2 * ((obj.p.x * L.x) + (obj.p.y * L.y));
  c = pow(obj.p.x, 2) + pow(obj.p.y, 2) - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(&obj.p, &L, &obj, &pos);
  if (delta < 0.00001)
    return (2.0);
  else
    {
      obj = tri_k(a, b, delta, obj);
      return (obj.k);
    }
}

float     ombr_cone(t_object obj, t_coord L)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  pos_simple(&obj.p, &L, &obj, &pos);
  L = rotate(L , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  obj.p = rotate(obj.p , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  a = pow(L.x, 2) + pow(L.y, 2) - pow(tan(25), 2) * pow(L.z, 2);
  b = 2 * ((obj.p.x * L.x) + (obj.p.y * L.y)
           - pow(tan(25), 2) * (obj.p.z * L.z));
  c = pow(obj.p.x, 2) + pow(obj.p.y, 2) - pow(tan(25), 2) * pow(obj.p.z, 2);
  delta = pow(b, 2) - (4 * a * c);
  L = rotate(L , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.p = rotate(obj.p , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(&obj.p, &L, &obj, &pos);
  if (delta < 0.00001)
    return (2.0);
  else
    {
      obj = tri_k(a, b, delta, obj);
      return (obj.k);
    }
}
