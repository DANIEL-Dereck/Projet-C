/*
** my_sousinf.c for Bistro in /home/daniel_d/rendu/Bistro/code
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Nov  1 13:28:15 2013 daniel_d
** Last update Mon Nov 11 11:07:53 2013 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	my_calc_sousinf(int **tab, char *result, int len)
{
  int	k;

  k = len;
  while (k >= 0)
    {
      if (tab[0][k] < tab[1][k])
	{
	  tab[0][k - 1] = tab[0][k - 1] - 1;
	  tab[0][k] = tab[0][k] + 10;
	}
      tab[2][k] = (tab[0][k] - tab[1][k]);
      result[k] = tab[2][k] + '0';
      k = k - 1;
    }
  my_aff(result);
  return (0);
}

int	my_sousinf(char *s1, char *s2)
{
  int	a;
  int	len;
  int	**tab;
  char	*result;

  a = 0;
  len = (my_strlen(s1) + my_strlen(s2) + 1);
  tab = malloc(sizeof(*tab) * 3);
  if (tab == NULL)
    return (0);
  while (a <= 2)
    {
      tab[a] = malloc(sizeof(**tab) * (len + 1));
      if (tab[a] == NULL)
	return (0);
      a = a + 1;
    }
  result = malloc(sizeof(*result) * (len + 1));
  if (result == NULL)
    return (0);
  tab[0] = my_remptab(tab[0], s1, my_strlen(s1), my_strlen(s2));
  tab[1] = my_remptab(tab[1], s2, my_strlen(s2), my_strlen(s1));
  my_calc_sousinf(tab, result, len);
  return (0);
}

