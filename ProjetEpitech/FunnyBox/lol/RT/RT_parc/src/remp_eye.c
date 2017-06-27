/*
** remp_eye.c for remp _eye in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Jun  5 13:35:54 2014 daniel_d
** Last update Thu Jun  5 14:32:37 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "rt_pars.h"

int     remp_eye_position(char **tab, t_eye *eye, int i)
{
  eye->coord.x = 0.0;
  eye->coord.y = 0.0;
  eye->coord.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_POSITION) == 0)
      {
        while (my_strcmp(tab[i], BE_POSITION) != 0 && tab[i] != NULL)
          {
            if (my_strcmpv2(tab[++i], POS_X) == 0)
              eye->coord.x = atof(get_info(tab[i], '>', '<'));
            if (my_strcmpv2(tab[++i], POS_Y) == 0)
              eye->coord.y = atof(get_info(tab[i], '>', '<'));
            if (my_strcmpv2(tab[++i], POS_Z) == 0)
              eye->coord.z = atof(get_info(tab[i], '>', '<'));
            i++;
          }
        if (tab[i] != NULL)
          return (0);
        else
          return (-1);
      }
  return (0);
}

int     remp_eye_rotate(char **tab, t_eye *eye, int i)
{
  eye->angle.x = 0.0;
  eye->angle.y = 0.0;
  eye->angle.z = 0.0;
  while (tab[i++] != NULL)
    if (my_strcmp(tab[i], BS_ROTATE) == 0)
      {
        while (my_strcmp(tab[i], BE_ROTATE) != 0 && tab[i] != NULL)
          {
            if (my_strcmpv2(tab[++i], POS_X) == 0)
              eye->angle.x = atof(get_info(tab[i], '>', '<'));
            if (my_strcmpv2(tab[++i], POS_Y) == 0)
              eye->angle.y = atof(get_info(tab[i], '>', '<'));
            if (my_strcmpv2(tab[++i], POS_Z) == 0)
              eye->angle.z = atof(get_info(tab[i], '>', '<'));
            i++;
          }
        if (tab[i] != NULL)
          return (0);
        else
          return (-1);
      }
  return (0);
}

t_eye	remp_eye(char **tab, t_eye eye)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], BS_EYE) == 0)
	{
	  remp_eye_rotate(tab, &eye, i);
	  remp_eye_position(tab, &eye, i);
	}
      i++;
    }
  return (eye);
}
