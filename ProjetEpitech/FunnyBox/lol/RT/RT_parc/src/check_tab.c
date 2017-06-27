/*
** check_tab.c for check_tab in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 31 17:53:27 2014 daniel_d
** Last update Wed Jun  4 16:35:31 2014 daniel_d
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

int	check_tab_bis(char **tab, char **start, char **end, int rv)
{
  int	i;
  int	l;

  i = 0;
  while (tab[i++] != NULL)
    {
      l = -1;
      while (start[++l] != NULL)
	{
	  if (my_strcmpv2(tab[i], end[l]) == 0)
	    rv = my_check_balise_end(tab, start[l], end[l], i);
	  else if (my_strcmpv2(tab[i], start[l]) == 0)
	    rv = my_check_balise(tab, start[l], end[l], i);
	  if (rv == -1)
	    return (-1);
	}
    }
  return (0);
}

int	check_tab(char **tab)
{
  char	**start;
  char	**end;
  int	rv;

  rv = 0;
  if ((start = malloc(sizeof(start) * 12)) == NULL ||
      (end = malloc(sizeof(end) * 12)) == NULL)
    return (-1);
  start = init_tab_start(start);
  end = init_tab_end(end);
  if (check_tab_bis(tab, start, end, rv) == -1)
    return (-1);
  return (0);
}
