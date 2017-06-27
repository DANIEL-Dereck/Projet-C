/*
** remp_spot.c for remp_spot in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Jun  3 15:17:18 2014 daniel_d
** Last update Fri Jun  6 17:28:33 2014 daniel_d
*/

#include "ray.h"

int     remp_coord_lum(char **tab, t_lumos *lum, int i)
{
  lum->coord.x = 0.0;
  lum->coord.y = 0.0;
  lum->coord.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_POSITION) == 0)
      {
	while (my_strcmp(tab[i], BE_POSITION) != 0 && tab[i] != NULL)
	  {
	    if (my_strcmpv2(tab[++i], POS_X) == 0)
	      lum->coord.x = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], POS_Y) == 0)
	      lum->coord.y = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], POS_Z) == 0)
	      lum->coord.z = atof(get_info(tab[i], '>', '<'));
	    i++;
	  }
	if (tab[i] != NULL)
	  return (0);
	else
	  return (-1);
      }
  return (0);
}

int     remp_color_lum(char **tab, t_lumos *lum, int i)
{
  lum->color.r = 255.0;
  lum->color.v = 255.0;
  lum->color.b = 255.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_COLOR) == 0)
      {
	while (my_strcmp(tab[i], BE_COLOR) != 0 && tab[i] != NULL)
	  {
	    if (my_strcmpv2(tab[++i], COLOR_RED) == 0)
	      lum->color.r = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], COLOR_GREEN) == 0)
	      lum->color.v = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], COLOR_BLUE) == 0)
	      lum->color.b = atof(get_info(tab[i], '>', '<'));
	    i++;
	  }
	if (tab[i] != NULL)
	  return (0);
	else
	  return (-1);
      }
  return (0);
}

int	count_spot(char **tab)
{
  int	nb_lum;
  int	i;

  i = 0;
  nb_lum = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmpv2(tab[i], BS_SPOT) == 0)
	{
	  while (my_strcmpv2(tab[i], BE_SPOT) != 0 && tab[i] != NULL)
	    i++;
	  if (tab[i] != NULL)
	    nb_lum++;
	  else
	    return (nb_lum);
	}
      i++;
    }
  return (nb_lum);
}

t_lumos	*remp_lum(char **tab, t_lumos *lum, int i, int *c)
{
  if (my_strcmpv2(tab[i], BS_SPOT) == 0)
    {
      remp_coord_lum(tab, &lum[*c], i);
      remp_color_lum(tab, &lum[*c], i);
      *c += 1;
      return (lum);
    }
  return (lum);
}

t_lumos	*remp_spot(char **tab, t_lumos *lum)
{
  int	i;
  int	c;
  int	nb_lum;

  i = 0;
  c = 0;
  if ((nb_lum = count_spot(tab)) == -1)
    return (NULL);
  if ((lum = malloc(sizeof(*lum) * (nb_lum))) == NULL)
    return (NULL);
  while (tab[i] != NULL && c < nb_lum)
    {
      lum[c].nb_spot = nb_lum;
      lum = remp_lum(tab, lum, i, &c);
      i++;
    }
  return (lum);
}
