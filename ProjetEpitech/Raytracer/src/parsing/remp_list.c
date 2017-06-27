/*
** list.c for list in /home/daniel_d/rendu/RT/RT_parseur/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 13:53:15 2014 daniel_d
** Last update Sun Jun  8 22:35:15 2014 daniel_d
*/

#include "ray.h"

int	count_item_bis_bis(char **tab, int i, int *nb)
{
  if (my_strcmpv2(tab[i], BS_CYLINDRE) == 0)
    {
      while (my_strcmpv2(tab[i], BE_CYLINDRE) != 0 && tab[i] != NULL)
	i++;
      *nb = *nb + 1;
    }
  else if (my_strcmpv2(tab[i], BS_PARA) == 0)
    {
      while (my_strcmpv2(tab[i], BE_PARA) != 0 && tab[i] != NULL)
	i++;
      *nb = *nb + 1;
    }
  return (0);
}

int	count_item_bis(char **tab, int i, int *nb)
{
  if (my_strcmpv2(tab[i], BS_PLAN) == 0)
    {
      while (my_strcmpv2(tab[i], BE_PLAN) != 0 && tab[i] != NULL)
	i++;
      *nb = *nb + 1;
    }
  else if (my_strcmpv2(tab[i], BS_SPHERE) == 0)
    {
      while (my_strcmpv2(tab[i], BE_SPHERE) != 0 && tab[i] != NULL)
	i++;
      *nb = *nb + 1;
    }
  else if (my_strcmpv2(tab[i], BS_CONE) == 0)
    {
      while (my_strcmpv2(tab[i], BE_CONE) != 0 && tab[i] != NULL)
	i++;
      *nb = *nb + 1;
    }
  else
    count_item_bis_bis(tab, i, nb);
  return (i);
}

int	count_item(char **tab)
{
  int	nb;
  int	i;

  i = 0;
  nb = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], BS_OBJ) == 0)
	{
	  while (my_strcmp(tab[i], BE_OBJ) != 0 && tab[i] != NULL)
	    {
	      i = count_item_bis(tab, i, &nb);
	      if (tab[i] == NULL)
		return (0);
	      i++;
	    }
	  if (my_strcmp(tab[i], BE_OBJ) == 0)
	    return (nb);
	  return (0);
	}
      i++;
    }
  return (0);
}

int	remp_list(char **tab)
{
  t_obj	*item;
  int	nb;

  if (check_tab(tab) == -1)
    return (-1);
  nb = count_item(tab);
  if (nb <= 0)
    {
      my_printf("ERROR : map invalid\n");
      return (-1);
    }
  if ((item = malloc(sizeof(*item) * nb)) == NULL)
    return (-1);
  if (remp_item(tab, item, nb) == -1)
    return (-1);
  return (0);
}

int     remp_item(char **tab, t_obj *item, int nb_item)
{
  int   i;
  int   c;
  t_lumos       *lum;
  t_eyep        eye;

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
      item = remp_parabole(tab, item, i, &c);
      i++;
    }
  if ((lum = remp_spot(tab, lum)) == NULL)
    return (-1);
  if (rt_main(eye, lum, item) == -1)
    return (-1);
  return (0);
}
