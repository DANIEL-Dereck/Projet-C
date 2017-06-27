/*
** remp_item.c for remp_item in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 31 17:01:22 2014 daniel_d
** Last update Sun Jun  8 22:23:14 2014 daniel_d
*/

#include "ray.h"

t_obj	*remp_plan(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_PLAN) == 0)
    {
      item[*c].type = 'p';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      *c += 1;
      return (item);
    }
  return (item);
}

t_obj	*remp_sphere(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_SPHERE) == 0)
    {
      item[*c].type = 's';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      *c += 1;
      return (item);
    }
  return (item);
}

t_obj	*remp_cone(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_CONE) == 0)
    {
      item[*c].type = 'c';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      *c += 1;
      return (item);
    }
  return (item);
}

t_obj	*remp_cylindre(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_CYLINDRE) == 0)
    {
      item[*c].type = 'y';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      *c +=1;
      return (item);
    }
  return (item);
}

t_obj	*remp_parabole(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_PARA) == 0)
    {
      item[*c].type = 'a';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      *c +=1;
      return (item);
    }
  return (item);
}
