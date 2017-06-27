/*
** init_obj.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 18:47:12 2014 jouana_j
** Last update Mon May 12 10:06:24 2014 daniel_d
*/

#include "ray.h"

void	init_eye(coord *eye)
{
  eye->x = -300;
  eye->y = 0;
  eye->z = 100;
}

void    init_obj(t_object *obj)
{
  obj[0].type = 'p';
  obj[0].pos.x = 0.0;
  obj[0].pos.y = 0.0;
  obj[0].pos.z = 0.0;
  obj[0].angle.x = 10.0;
  obj[0].angle.y = 0.0;
  obj[0].angle.z = 0.0;
  obj[0].brill = 0.1;
  my_color(&obj[0].color, 0, 0, 255);
  obj[1].type = 's';
  obj[1].pos.x = 100.0;
  obj[1].pos.y = 0.0;
  obj[1].pos.z = 0.0;
  obj[1].angle.x = 0.0;
  obj[1].angle.y = 0.0;
  obj[1].angle.z = 0.0;
  obj[1].brill = 0.1;
  my_color(&obj[1].color, 255, 0, 0);
  obj[2].type = 'y';
  obj[2].pos.x = 100.0;
  obj[2].pos.y = 100.0;
  obj[2].pos.z = 0.0;
  obj[2].angle.x = 30.0;
  obj[2].angle.y = 0.0;
  obj[2].angle.z = 0.0;
  obj[2].brill = 0.1;
  my_color(&obj[2].color, 0, 255, 0);
  obj[3].type = 's';
  obj[3].pos.x = 100.0;
  obj[3].pos.y = -100.0;
  obj[3].pos.z = 0.0;
  obj[3].angle.x = 0.0;
  obj[3].angle.y = 0.0;
  obj[3].angle.z = 0.0;
  obj[3].brill = 0.1;
  my_color(&obj[3].color, 255, 255, 0);
}
