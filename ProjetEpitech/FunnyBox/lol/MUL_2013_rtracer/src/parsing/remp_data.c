/*
** remp_data.c for remp_data in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun  2 15:23:40 2014 daniel_d
** Last update Sat Jun  7 17:03:34 2014 jouana_j
*/

#include "ray.h"

int     remp_coord(char **tab, t_obj *item, int i)
{
  item->coord.x = 0.0;
  item->coord.y = 0.0;
  item->coord.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_POSITION) == 0)
      {
	while (tab[i] !=  NULL && my_strcmp(tab[i], BE_POSITION) != 0)
	  {
	    if (my_strcmpv2(tab[++i], POS_X) == 0)
	      if ((item->coord.x = atof(get_info(tab[i++], '>', '<'))) >= 100)
		item->coord.x = 99;
	    if (my_strcmpv2(tab[i], POS_Y) == 0)
	      item->coord.y = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], POS_Z) == 0)
	      item->coord.z = atof(get_info(tab[i], '>', '<'));
	    i++;
	  }
	if (tab[i] != NULL)
	  return (0);
	else
	  return (-1);
      }
  return (0);
}

int     remp_angle(char **tab, t_obj *item, int i)
{
  item->angle.x = 0.0;
  item->angle.y = 0.0;
  item->angle.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_ROTATE) == 0)
      {
	while (tab[i] != NULL && my_strcmp(tab[i], BE_ROTATE) != 0)
	  {
	    if (my_strcmpv2(tab[++i], POS_X) == 0)
	      item->angle.x = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], POS_Y) == 0)
	      item->angle.y = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], POS_Z) == 0)
	      item->angle.z = atof(get_info(tab[i], '>', '<'));
	    i++;
	  }
	if (tab[i] != NULL)
	  return (0);
	else
	  return (-1);
      }
  return (0);
}

int     remp_color(char **tab, t_obj *item, int i)
{
  item->color.r = 0.0;
  item->color.v = 0.0;
  item->color.b = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_COLOR) == 0)
      {
	while (tab[i] != NULL && my_strcmp(tab[i], BE_COLOR) != 0)
	  {
	    if (my_strcmpv2(tab[++i], COLOR_RED) == 0)
	      item->color.r = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], COLOR_GREEN) == 0)
	      item->color.v = atof(get_info(tab[i++], '>', '<'));
	    if (my_strcmpv2(tab[i], COLOR_BLUE) == 0)
	      item->color.b = atof(get_info(tab[i], '>', '<'));
	    i++;
	  }
	if (tab[i] != NULL)
	  return (0);
	else
	  return (-1);
      }
  return (0);
}

int       remp_brill(char **tab, t_obj *item, int i)
{
  item->brill = 0.1;
  while (tab[i] != NULL)
    {
      if (my_strcmpv2(tab[i], BRILL) == 0)
	{
	  item->brill = atof(get_info(tab[i], '>', '<'));
	  return (0);
	}
      i++;
    }
  return (0);
}

int       remp_rayon(char **tab, t_obj *item, int i)
{
  item->rayon = 50.0;
  while (tab[i] != NULL)
    {
      if (my_strcmpv2(tab[i], RAYON) == 0)
	{
	  item->rayon = atof(get_info(tab[i], '>', '<'));
	  return (0);
	}
      i++;
    }
  return (0);
}
