/*
** intersections.c for rtv1 in /home/grasla_r/rendu/MUL_2013_rtv1
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Wed Feb 26 18:47:46 2014 grasla_r
** Last update Sun Jun  8 21:35:39 2014 daniel_d
*/

#include "ray.h"

t_object     inter_plan(t_object obj, t_coord *V, t_rt *rt)
{
  float k;
  t_coord pos;

  pos_simple(rt->eye, V, &obj, &pos);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *rt->eye = rotate(*rt->eye , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  if (V->z >= 0.0001 || V->z <= -0.0001)
    {
      k = -(rt->eye->z / V->z);
      if (k >= 0.0001)
        {
          obj.k = k;
          obj.is_inter = 1;
        }
      else
	obj.is_inter = 0;
    }
  else
    obj.is_inter = 0;
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  *rt->eye = rotate(*rt->eye , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(rt->eye, V, &obj, &pos);
  return (obj);
}

t_object     inter_sphere(t_object obj, t_coord *V, t_rt *rt)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  pos_simple(rt->eye, V, &obj, &pos);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *rt->eye = rotate(*rt->eye , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2) + pow(V->z, 2);
  b = 2 * ((rt->eye->x * V->x) + (rt->eye->y * V->y) + (rt->eye->z * V->z));
  c = pow(rt->eye->x, 2) + pow(rt->eye->y, 2) + pow(rt->eye->z, 2)
    - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  *rt->eye = rotate(*rt->eye , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(rt->eye, V, &obj, &pos);
  if (delta < 0.00001)
    {
      obj.is_inter = 0;
      return (obj);
    }
  else
    return (tri_k(a, b, delta, obj));
}

t_object     inter_cyl(t_object obj, t_coord *V, t_rt *rt)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  *V = pos_simple(rt->eye, V, &obj, &pos);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2);
  b = 2 * ((rt->eye->x * V->x) + (rt->eye->y * V->y));
  c = pow(rt->eye->x, 2) + pow(rt->eye->y, 2) - pow(obj.rayon, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(rt->eye, V, &obj, &pos);
  if (delta < 0)
    {
      obj.is_inter = 0;
      return (obj);
    }
  else
    {
      obj = tri_k(a, b, delta, obj);
      return (obj);
    }
}

t_object     inter_cone(t_object obj, t_coord *V, t_rt *rt)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  *V = pos_simple(rt->eye, V, &obj, &pos);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2) - pow(tan(25), 2) * pow(V->z, 2);
  b = 2 * ((rt->eye->x * V->x) + (rt->eye->y * V->y)
	   - pow(tan(25), 2) * (rt->eye->z * V->z));
  c = pow(rt->eye->x, 2) + pow(rt->eye->y, 2)
    - pow(tan(25), 2) * pow(rt->eye->z, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(rt->eye, V, &obj, &pos);
  if (delta < 0)
    {
      obj.is_inter = 0;
      return (obj);
    }
  else
    return (tri_k(a, b, delta, obj));
}

t_object     inter_ph(t_object obj, t_coord *V, t_rt *rt)
{
  float a;
  float b;
  float c;
  float delta;
  t_coord pos;

  pos_simple(rt->eye, V, &obj, &pos);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *rt->eye = rotate(*rt->eye , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2);
  b = 2 *((rt->eye->x * V->x) + (rt->eye->y * V->y)) - 80 * V->z;
  c = pow(rt->eye->x, 2) + pow(rt->eye->y, 2) - 80 * rt->eye->z;
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  *rt->eye = rotate(*rt->eye , obj.angle.x, obj.angle.y, obj.angle.z);
  pos_reel(rt->eye, V, &obj, &pos);
  if (delta < 0.00001)
    {
      obj.is_inter = 0;
      return (obj);
    }
  else
    return (tri_k(a, b, delta, obj));
}
