/*
** my_multinf.c for Bistro in /home/daniel_d/rendu/Bistro/code
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Nov  1 13:28:15 2013 daniel_d
** Last update Mon Nov 11 11:08:18 2013 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	my_tabcpy(char *result, int **tab, int len)
{
  while (len >= 0)
    {
      result[len] = tab[3][len] + '0';
      len = len - 1;
    }
  my_aff(result);
  return (0);
}

int	**my_multadd(int **tab, int len)
{
  int	ret;

  ret = 0;
  while (len >= 0)
    {
      tab[3][len] = (tab[2][len] + tab[3][len] + ret);
      ret = 0;
      if (tab[3][len] >= 10)
	{
	  tab[3][len] = tab[3][len] % 10;
	  ret = ret + 1;
	}
      len = len - 1;
    }
  return (tab);
}

int	**my_multwhile(int **tab, int i, int k, int n)
{
  int	ret;
  int	a;

  ret = 0;
  a = i;
  while (a >= 0 && k >= 0)
    {
      tab[2][a] = ((tab[0][k] * tab[1][n]) + ret);
      ret = 0;
      if (tab[2][a] >= 10)
	{
	  ret = tab[2][a] / 10;
	  tab[2][a] = tab[2][a] % 10;
	}
      a = a - 1;
      k = k - 1;
    }
  return (tab);
}

int	my_calc_multinf(int **tab, char *result, int len)
{
  int	k;
  int	n;
  int	i;

  k = len;
  i = len;
  n = len;
  while (n >= 0)
    {
      tab = my_multwhile(tab, i, k, n);
      tab = my_multadd(tab, len);
      tab[2][i] = 0;
      i = i - 1;
      k = len;
      n = n - 1;
    }
  my_tabcpy(result, tab, len);
  return (0);
}

int	my_multinf(char *s1, char *s2)
{
  int	len;
  int	a;
  int	**tab;
  char	*result;

  a = 0;
  len = (my_strlen(s1) + my_strlen(s2));
  tab = malloc(sizeof(*tab) * 4);
  if (tab == NULL)
    return (0);
  while (a <= 3)
    {
      tab[a] = malloc(sizeof(**tab) * (len + 2));
      if (tab[a] == NULL)
        return (0);
      a = a + 1;
    }
  result = malloc(sizeof(*result) * (len + 1));
  if (result == NULL)
    return (0);
  tab[0] = my_remptab(tab[0], s1, my_strlen(s1), my_strlen(s2));
  tab[1] = my_remptab(tab[1], s2, my_strlen(s2), my_strlen(s1));
  my_calc_multinf(tab, result, len);
  return (0);
}

