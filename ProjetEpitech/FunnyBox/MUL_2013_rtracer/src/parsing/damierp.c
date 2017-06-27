/*
** damierp.c for damier in /home/daniel_d/rendu/MUL_2013_rtracer/src/parsing
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Jun  8 19:03:57 2014 daniel_d
** Last update Sun Jun  8 19:33:43 2014 daniel_d
*/

#include "ray.h"

int       remp_damier(char **tab, t_obj *item, int i)
{
  item->rayon = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmpv2(tab[i], DAMIER) == 0)
        {
          item->damier = atoi(get_info(tab[i], '>', '<'));
          if (item->damier <= 0)
            item->damier = 0;
          else
            item->damier = 1;
          return (0);
        }
      i++;
    }
  return (0);
}
