/*
** tri_inter_k.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 18:04:31 2014 jouana_j
** Last update Fri May  9 18:27:36 2014 jouana_j
*/

#include "ray.h"

coord	pos_simple(coord V, t_object obj)
{
  V.x = V.x + obj.pos.x;
  V.y = V.y + obj.pos.y;
  V.z = V.z + obj.pos.z;
  return (V);
}

coord	pos_reel(coord V, t_object obj)
{
  V.x -= obj.pos.x;
  V.y -= obj.pos.y;
  V.z -= obj.pos.z;
  return (V);
}

t_object	tri_k(float a, float b, float delta, t_object obj)
{
  float	k;
  float k2;

  k = (-b + sqrt(delta)) / (2 * a);
  k2 = (-b - sqrt(delta)) / (2 * a);
  if (k < k2)
    obj.k = k;
  else if (k2 < k)
    obj.k = k2;
  obj.is_inter = 1;
  return (obj);
}

int     my_triobject_k(t_object *obj, int nb_obj)
{
  float kmin;
  int i;
  int iobj;
  int ret;

  ret = 0;
  i = 0;
  while (i <= nb_obj)
    ret = ret + obj[i++].is_inter;
  if (ret == 0)
    return (-1);
  i = 0;
  kmin = 9999;
  while (i <= nb_obj)
    {
      if (obj[i].is_inter == 1 && obj[i].k <= kmin)
        {
          iobj = i;
          kmin = obj[i].k;
        }
      i = i + 1;
    }
  return (iobj);
}
