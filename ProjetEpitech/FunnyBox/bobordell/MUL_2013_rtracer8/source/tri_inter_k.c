/*
** tri_inter_k.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 18:04:31 2014 jouana_j
** Last update Wed Jun  4 16:14:13 2014 jouana_j
*/

#include "ray.h"

t_coord	pos_simple(t_rt *rt, t_coord *V, t_object *obj, t_coord *pos)
{
  rt->eye->x -= obj->pos.x;
  rt->eye->y -= obj->pos.y;
  rt->eye->z -= obj->pos.z;
  V->x -= obj->pos.x;
  V->y -= obj->pos.y;
  V->z -= obj->pos.z;
  pos->x = obj->pos.x;
  pos->y = obj->pos.y;
  pos->z = obj->pos.z;
  obj->pos.x = 0;
  obj->pos.y = 0;
  obj->pos.z = 0;
  return (*V);
}

t_coord	pos_reel(t_rt *rt, t_coord *V, t_object *obj, t_coord *pos)
{
  obj->pos.x = pos->x;
  obj->pos.y = pos->y;
  obj->pos.z = pos->z;
  V->x += obj->pos.x;
  V->y += obj->pos.y;
  V->z += obj->pos.z;
  rt->eye->x += obj->pos.x;
  rt->eye->y += obj->pos.y;
  rt->eye->z += obj->pos.z;
  return (*V);
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
  while (i < nb_obj)
    ret = ret + obj[i++].is_inter;
  if (ret == 0)
    return (-1);
  i = 0;
  kmin = 9999;
  while (i < nb_obj)
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
