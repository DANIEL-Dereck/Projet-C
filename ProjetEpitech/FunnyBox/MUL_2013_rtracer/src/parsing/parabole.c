/*
** parabole.c for pars in /home/daniel_d/rendu/MUL_2013_rtracer/src/parsing
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Jun  8 19:12:05 2014 daniel_d
** Last update Sun Jun  8 21:10:36 2014 daniel_d
*/

#include "ray.h"

t_obj   *remp_parabole(char **tab, t_obj *item, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_PARABOLE) == 0)
    {
      printf("remp_parabole\n");
      item[*c].type = 'a';
      remp_coord(tab, &item[*c], i);
      remp_angle(tab, &item[*c], i);
      remp_color(tab, &item[*c], i);
      remp_brill(tab, &item[*c], i);
      remp_rayon(tab, &item[*c], i);
      remp_damier(tab, &item[*c], i);
      *c +=1;
      return (item);
    }
  return (item);
}
