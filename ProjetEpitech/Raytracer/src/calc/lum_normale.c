/*
** lum_normale.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V6)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon May 12 14:46:57 2014 jouana_j
** Last update Sun Jun  8 22:10:09 2014 daniel_d
*/

#include "ray.h"

t_object	my_n_sphere(t_object obj, t_coord *pos)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = obj.p.z;
  obj.N = rotate(obj.N , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.N.x += pos->x;
  obj.N.y += pos->y;
  obj.N.z += pos->z;
  return (obj);
}

t_object	my_n_plan(t_object obj, t_coord *pos)
{
  obj.N.x = 0;
  obj.N.y = 0;
  obj.N.z = 100;
  obj.N = rotate(obj.N , obj.angle.x, obj.angle.y, obj.angle.z);
  obj.N.x += pos->x;
  obj.N.y += pos->y;
  obj.N.z += pos->z;
  return (obj);
}

t_object	my_n_cylindre(t_object obj, t_coord *pos)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = 0;
  obj.N.x += pos->x;
  obj.N.y += pos->y;
  obj.N.z += pos->z;
  obj.N = rotate(obj.N , obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object my_n_cone(t_object obj, t_coord *pos)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = -tan(25) * obj.p.z;
  obj.N.x += pos->x;
  obj.N.y += pos->y;
  obj.N.z += pos->z;
  obj.N = rotate(obj.N , obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object my_n_ph(t_object obj, t_coord *pos)
{
  obj.N.x = obj.p.x;
  obj.N.y = -obj.p.y;
  obj.N.z = 80;
  obj.N.x += pos->x;
  obj.N.y += pos->y;
  obj.N.z += pos->z;
  obj.N = rotate(obj.N , obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}
