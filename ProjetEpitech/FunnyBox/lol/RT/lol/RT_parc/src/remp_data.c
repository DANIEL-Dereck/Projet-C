/*
** remp_data.c for remp_data in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun  2 15:23:40 2014 daniel_d
** Last update Mon Jun  2 15:51:34 2014 daniel_d
*/

#include <stdlib.h>
#include "rt_pars.h"
#include "my.h"

int     remp_eye(char **tab, t_eye *eye, int i)
{
  eye->x = -300.0;
  eye->y = 0.0;
  eye->z = 100.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_EYE) == 0)
      {
	if (my_strcmpv2(tab[++i], POS_X) == 0)
	  eye->x = atof(get_info(tab[i], '>', '<'));
	else
	  eye->x = -300.0;
	if (my_strcmpv2(tab[++i], POS_Y) == 0)
	  eye->y = atof(get_info(tab[i], '>', '<'));
	else
	  eye->y = 0.0;
	if (my_strcmpv2(tab[++i], POS_Z) == 0)
	  eye->z = atof(get_info(tab[i], '>', '<'));
	else
	  eye->z = 100.0;
	return (0);
      }
  return (0);
}

int     remp_coord(char **tab, t_obj *item, int i)
{
  item->coord.x = 0.0;
  item->coord.y = 0.0;
  item->coord.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_POSITION) == 0)
      {
	if (my_strcmpv2(tab[++i], POS_X) == 0)
	  item->coord.x = atof(get_info(tab[i++], '>', '<'));
	else
	  item->coord.x = 0.0;
	if (my_strcmpv2(tab[i], POS_Y) == 0)
	  item->coord.y = atof(get_info(tab[i++], '>', '<'));
	else
	  item->coord.y = 0.0;
	if (my_strcmpv2(tab[i], POS_Z) == 0)
	  item->coord.z = atof(get_info(tab[i], '>', '<'));
	else
	  item->coord.z = 0.0;
	i++;
	return (0);
      }
  return (0);
}

int     remp_angle(char **tab, t_obj *item, int i)
{
  item->angle.x = 0.0;
  item->angle.y = 0.0;
  item->angle.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_POSITION) == 0)
      {
	if (my_strcmpv2(tab[++i], POS_X) == 0)
	  item->angle.x = atof(get_info(tab[i++], '>', '<'));
	else
	  item->angle.x = 0.0;
	if (my_strcmpv2(tab[i], POS_Y) == 0)
	  item->angle.y = atof(get_info(tab[i++], '>', '<'));
	else
	  item->angle.y = 0.0;
	if (my_strcmpv2(tab[i], POS_Z) == 0)
	  item->angle.z = atof(get_info(tab[i], '>', '<'));
	else
	  item->angle.z = 0.0;
	i++;
	return (0);
      }
  return (0);
}

int     remp_color(char **tab, t_obj *item, int i)
{
  item->color.r = 127;
  item->color.v = 127;
  item->color.b = 127;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_COLOR) == 0)
      {
	if (my_strcmpv2(tab[++i], COLOR_RED) == 0)
	  item->color.r = my_getnbr(get_info(tab[i++], '>', '<'));
	else
	  item->color.r = 127;
	if (my_strcmpv2(tab[i], COLOR_GREEN) == 0)
	  item->color.v = my_getnbr(get_info(tab[i++], '>', '<'));
	else
	  item->color.v = 127;
	if (my_strcmpv2(tab[i], COLOR_BLUE) == 0)
	  item->color.b = my_getnbr(get_info(tab[i], '>', '<'));
	else
	  item->color.b = 127;
	i++;
	return (0);
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
