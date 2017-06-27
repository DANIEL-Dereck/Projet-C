/*
** intersections.c for rtv1 in /home/grasla_r/rendu/MUL_2013_rtv1
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Wed Feb 26 18:47:46 2014 grasla_r
** Last update Tue May 13 14:25:26 2014 jouana_j
*/

#include "ray.h"

t_object     inter_plan(t_object obj, t_coord *V, t_coord *eye)
{
  float k;

  *V = pos_simple(*V, obj);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  if (V->z > 0.01 || V->z < -0.01)
    {
      k = -(eye->z / V->z);
      if (k > 0.00001)
        {
          obj.k = k;
          obj.is_inter = 1;
        }
      else
	obj.is_inter = 0;
    }
  else
    obj.is_inter = 0;
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(*V, obj);
  return (obj);
}

t_object     inter_sphere(t_object obj, t_coord *V, t_coord *eye)
{
  float a;
  float b;
  float c;
  float delta;

  *V = pos_simple(*V, obj);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2) + pow(V->z, 2);
  b = 2 * ((eye->x * V->x) + (eye->y * V->y) + (eye->z * V->z));
  c = pow(eye->x, 2) + pow(eye->y, 2) + pow(eye->z, 2) - pow(75, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(*V, obj);
  if (delta < 0.00001)
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

t_object     inter_cyl(t_object obj, t_coord *V, t_coord *eye)
{
  float a;
  float b;
  float c;
  float delta;

  *V = pos_simple(*V, obj);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2);
  b = 2 * ((eye->x * V->x) + (eye->y * V->y));
  c = pow(eye->x, 2) + pow(eye->y, 2) - pow(75, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(*V, obj);
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

t_object     inter_cone(t_object obj, t_coord *V, t_coord *eye)
{
  float a;
  float b;
  float c;
  float delta;

  *V = pos_simple(*V, obj);
  *V = rotate(*V , obj.angle.x, obj.angle.y, obj.angle.z);
  a = pow(V->x, 2) + pow(V->y, 2) - pow(tan(25), 2) * pow(V->z, 2);
  b = 2 * ((eye->x * V->x) + (eye->y * V->y)
	   - pow(tan(25), 2) * (eye->z * V->z));
  c = pow(eye->x, 2) + pow(eye->y, 2) - pow(tan(25), 2) * pow(eye->z, 2);
  delta = pow(b, 2) - (4 * a * c);
  *V = rotate(*V , -obj.angle.x, -obj.angle.y, -obj.angle.z);
  *V = pos_reel(*V, obj);
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
