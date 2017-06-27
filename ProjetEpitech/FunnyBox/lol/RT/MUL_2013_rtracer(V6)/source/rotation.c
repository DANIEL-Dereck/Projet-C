/*
** rotation.c for tp_raytracer in /home/jouana_j/rendu/tp_raytracer/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Thu Feb 20 12:12:40 2014 jouana_j
** Last update Fri May  9 21:14:35 2014 jouana_j
*/

#include "ray.h"

coord   rotate_x(coord obj, float angle)
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

coord    rotate_y(coord obj, float angle)
{
  float x1;
  float y1;
  float z1;

  angle = angle/57.2957795;
  z1 = (obj.z * cosf(angle)) - (obj.x * sinf(angle));
  x1 = (obj.z * sinf(angle)) + (obj.x * cosf(angle));
  y1 = obj.y;
  obj.x = x1;
  obj.y = y1;
  obj.z = z1;
  return (obj);
}

coord     rotate_z(coord obj, float angle)
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

coord rotate(coord obj, float angle_x, float angle_y, float angle_z)
{
  obj = rotate_x(obj, angle_x);
  obj = rotate_y(obj, angle_y);
  obj = rotate_z(obj, angle_z);
  return (obj);
}
