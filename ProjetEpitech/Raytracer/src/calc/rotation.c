/*
** rotation.c for tp_raytracer in /home/jouana_j/rendu/tp_raytracer/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Thu Feb 20 12:12:40 2014 jouana_j
** Last update Sun Jun  8 04:05:46 2014 jouana_j
*/

#include "ray.h"

t_coord   rotate_x(t_coord obj, float angle)
{
  float x1;
  float y1;
  float z1;

  angle = angle/57.2957795;
  y1 = (obj.y * cosf(angle)) - (obj.z * sinf(angle));
  z1 = (obj.y * sinf(angle)) + (obj.z * cosf(angle));
  x1 = obj.x;
  obj.x = x1;
  obj.y = y1;
  obj.z = z1;
  return (obj);
}

t_coord    rotate_y(t_coord obj, float angle)
{
  float x1;
  float y1;
  float z1;

  angle = angle/57.2957795;
  x1 = (obj.x * cosf(angle)) + (obj.z * sinf(angle));
  z1 = (-obj.x * sinf(angle)) + (obj.z * cosf(angle));
  y1 = obj.y;
  obj.x = x1;
  obj.y = y1;
  obj.z = z1;
  return (obj);
}

t_coord     rotate_z(t_coord obj, float angle)
{
  float x1;
  float y1;
  float z1;

  angle = angle/57.2957795;
  x1 = (obj.x * cosf(angle)) - (obj.y * sinf(angle));
  y1 = (obj.x * sinf(angle)) + (obj.y * cosf(angle));
  z1 = obj.z;
  obj.x = x1;
  obj.y = y1;
  obj.z = z1;
  return (obj);
}

t_coord rotate(t_coord obj, float angle_x, float angle_y, float angle_z)
{
  if (angle_x > 0.001 || angle_x < -0.001)
    obj = rotate_x(obj, angle_x);
  if (angle_y > 0.001 || angle_y < -0.001)
    obj = rotate_y(obj, angle_y);
  if (angle_z > 0.001 || angle_z < -0.001)
    obj = rotate_z(obj, angle_z);
  return (obj);
}
