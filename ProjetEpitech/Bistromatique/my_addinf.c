/*
** my_addinf.c for Bistro in /home/daniel_d/rendu/Bistro/code
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Nov  1 13:28:15 2013 daniel_d
** Last update Mon Nov 11 11:08:03 2013 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	my_calc_addinf(int **tab, char *result, int len)
{
  int	ret;
  int	k;

  k = len;
  ret = 0;
  while (k >= 0)
    {
      tab[2][k] = (tab[0][k] + tab[1][k] + ret);
      ret = 0;
      if (tab[2][k] > 9)
	{
	  tab[2][k] = tab[2][k] % 10;
	  ret = ret + 1;
	}
      result[k] = tab[2][k] + '0';
      k = k - 1;
    }
  my_aff(result);
  return (0);
}

int	my_addinf(char *s1, char *s2)
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
  my_calc_addinf(tab, result, len);
  return (0);
}
