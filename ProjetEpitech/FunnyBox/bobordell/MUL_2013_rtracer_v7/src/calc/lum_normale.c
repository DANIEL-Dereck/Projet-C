/*
** lum_normale.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V6)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon May 12 14:46:57 2014 jouana_j
** Last update Mon Jun  2 15:05:17 2014 grasla_r
*/

#include "ray.h"

t_object	my_n_sphere(t_object obj)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = obj.p.z;
  obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object	my_n_plan(t_object obj)
{
  obj.N.x = 0;
  obj.N.y = 0;
  obj.N.z = 100;
  obj.N = pos_simple(obj.N, obj);
  obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object	my_n_cylindre(t_object obj)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = 0;
  obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object my_n_cone(t_object obj)
{
  obj.N.x = obj.p.x;
  obj.N.y = obj.p.y;
  obj.N.z = -tan(25) * obj.p.z;
  obj.N = rotate(obj.N, obj.angle.x, obj.angle.y, obj.angle.z);
  return (obj);
}

t_object        calcul_normale(t_object obj)
{
  int	i;
  t_object (*p_normale[4])(t_object);
  char	symbol[4];

  i = 0;
  symbol[0] = 'p';
  symbol[1] = 's';
  symbol[2] = 'y';
  symbol[3] = 'c';
  symbol[4] = '\0';
  p_normale[0] = &my_n_plan;
  p_normale[1] = &my_n_sphere;
  p_normale[2] = &my_n_cylindre;
  p_normale[3] = &my_n_cone;
  p_normale[4] = NULL;
  while (p_normale[i] != NULL)
    {
      if (symbol[i] == obj.type)
	obj = p_normale[i](obj);
      i++;
    }
  return (obj);
}
