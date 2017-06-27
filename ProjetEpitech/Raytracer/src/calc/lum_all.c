/*
** lum_all.c for lum_all in /home/daniel_d/rendu/rttttttttttt/MUL_2013_rtracer/src/calc
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Jun  8 22:09:04 2014 daniel_d
** Last update Sun Jun  8 22:09:16 2014 daniel_d
*/

#include "ray.h"

t_object        calcul_normale(t_object obj, t_coord *pos)
{
  int   i;
  t_object (*p_normale[6])(t_object, t_coord *);
  char  symbol[6];

  i = 0;
  symbol[0] = 'p';
  symbol[1] = 's';
  symbol[2] = 'y';
  symbol[3] = 'c';
  symbol[4] = 'a';
  symbol[5] = '\0';
  p_normale[0] = &my_n_plan;
  p_normale[1] = &my_n_sphere;
  p_normale[2] = &my_n_cylindre;
  p_normale[3] = &my_n_cone;
  p_normale[4] = &my_n_ph;
  p_normale[5] = NULL;
  while (p_normale[i] != NULL)
    {
      if (symbol[i] == obj.type)
        obj = p_normale[i](obj, pos);
      i++;
    }
  return (obj);
}
