/*
** remp_item.c for remp_item in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 31 17:01:22 2014 daniel_d
** Last update Thu Jun  5 17:41:17 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "rt_pars.h"
#include "my.h"

t_obj	*remp_plan(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_PLAN) == 0)
    {
      item[*c].type = 'p';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
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
      *c +=1;
      return (item);
    }
  return (item);
}

int	remp_item(char **tab, t_obj *item, int nb_item)
{
  int	i;
  int	c;
  t_lumos	*lum;
  t_eye	eye;

  c = 0;
  i = 0;
  if ((lum = malloc(sizeof(lum))) == NULL)
    return (-1);
  eye = remp_eye(tab, eye);
  while (tab[i] != NULL && c < nb_item)
    {
      item[c].nb_obj = nb_item;
      item = remp_plan(tab, item, i, &c);
      item = remp_sphere(tab, item, i, &c);
      item = remp_cone(tab, item, i, &c);
      item = remp_cylindre(tab, item, i, &c);
      i++;
    }
  if ((lum = remp_spot(tab, lum)) == NULL)
    return (-1);
  aff_all(item, eye, lum);
  return (0);
}
