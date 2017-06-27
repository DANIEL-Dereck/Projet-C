/*
** check_tab.c for check_tab in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 31 17:53:27 2014 daniel_d
** Last update Mon Jun  2 16:20:55 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "rt_pars.h"

int	my_check_balise(char **tab, char *balise_s, char *balise_e, int i)
{
  i++;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], balise_s) == 0)
	return (-1);
      if (my_strcmp(tab[i], balise_e) == 0)
	return (0);
      else if (my_strcmpv2(tab[i], balise_e) == 0)
	return (0);
      i++;
    }
  return (-1);
}

int	my_check_balise_end(char **tab, char *balise_s, char *balise_e, int i)
{
  i--;
  while (i >= 0)
    {
      if (my_strcmp(tab[i], balise_e) == 0)
	return (-1);
      if (my_strcmp(tab[i], balise_s) == 0)
	return (0);
      else if (my_strcmpv2(tab[i], balise_s) == 0)
	return (0);
      i--;
    }
  return (-1);
}

int	my_check_end(char **tab, int i, int rv)
{
  if (my_strcmp(tab[i], BE_RACINE) == 0)
    rv = my_check_balise_end(tab, BS_RACINE, BE_RACINE, i);
  else if (my_strcmp(tab[i], BE_EYE) == 0)
    rv = my_check_balise_end(tab, BS_EYE, BE_EYE, i);
  else if (my_strcmp(tab[i], BE_OBJ) == 0)
    rv = my_check_balise_end(tab, BS_OBJ, BE_OBJ, i);
  else if (my_strcmp(tab[i], BE_ROTATE) == 0)
    rv = my_check_balise_end(tab, BS_ROTATE, BE_ROTATE, i);
  else if (my_strcmp(tab[i], BE_POSITION) == 0)
    rv = my_check_balise_end(tab, BS_POSITION, BE_POSITION, i);
  else if (my_strcmp(tab[i], BE_COLOR) == 0)
    rv = my_check_balise_end(tab, BS_COLOR, BE_COLOR, i);
  else if (my_strcmpv2(tab[i], BE_SPOT) == 0)
    rv = my_check_balise_end(tab, BS_SPOT, BE_SPOT, i);
  else if (my_strcmpv2(tab[i], BE_PLAN) == 0)
    rv = my_check_balise_end(tab, BS_PLAN, BE_PLAN, i);
  else if (my_strcmpv2(tab[i], BE_SPHERE) == 0)
    rv = my_check_balise_end(tab, BS_SPHERE, BE_SPHERE, i);
  else if (my_strcmpv2(tab[i], BE_CONE) == 0)
    rv = my_check_balise_end(tab, BS_CONE, BE_CONE, i);
  else if (my_strcmpv2(tab[i], BE_CYLINDRE) == 0)
    rv = my_check_balise_end(tab, BS_CYLINDRE, BE_CYLINDRE, i);
  return (rv);
}

int	check_tab(char **tab)
{
  int	rv;
  int	i;

  i = 0;
  rv = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], BS_RACINE) == 0)
	rv = my_check_balise(tab, BS_RACINE, BE_RACINE, i);
      else if (my_strcmp(tab[i], BS_EYE) == 0)
	rv = my_check_balise(tab, BS_EYE, BE_EYE, i);
      else if (my_strcmp(tab[i], BS_OBJ) == 0)
	rv = my_check_balise(tab, BS_OBJ, BE_OBJ, i);
      else if (my_strcmp(tab[i], BS_ROTATE) == 0)
	rv = my_check_balise(tab, BS_ROTATE, BE_ROTATE, i);
      else if (my_strcmp(tab[i], BS_POSITION) == 0)
	rv = my_check_balise(tab, BS_POSITION, BE_POSITION, i);
      else if (my_strcmp(tab[i], BS_COLOR) == 0)
	rv = my_check_balise(tab, BS_COLOR, BE_COLOR, i);
      else if (my_strcmpv2(tab[i], BS_SPOT) == 0)
	rv = my_check_balise(tab, BS_SPOT, BE_SPOT, i);
      else if (my_strcmpv2(tab[i], BS_PLAN) == 0)
	rv = my_check_balise(tab, BS_PLAN, BE_PLAN, i);
      else if (my_strcmpv2(tab[i], BS_SPHERE) == 0)
	rv = my_check_balise(tab, BS_SPHERE, BE_SPHERE, i);
      else if (my_strcmpv2(tab[i], BS_CONE) == 0)
	rv = my_check_balise(tab, BS_CONE, BE_CONE, i);
      else if (my_strcmpv2(tab[i], BS_CYLINDRE) == 0)
	rv = my_check_balise(tab, BS_CYLINDRE, BE_CYLINDRE, i);
      else
	rv = my_check_end(tab, i, rv);
      if (rv == -1)
	{
	  my_printf("ERROR : Invalid syntax ligne : %d\n", (i + 1));
	  return (-1);
	}
      i++;
    }
  return (0);
}
