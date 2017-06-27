/*
** my_remptab.c for Bistro in /home/daniel_d/rendu/Bistro
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov  5 13:49:22 2013 daniel_d
** Last update Sun Nov 10 10:14:03 2013 daniel_d
*/

#include "my.h"
#include "bistro.h"

int	*my_remptab(int *tab, char *str, int len1, int len2)
{
  int	a;
  int	k;

  k = (len1 + len2 + 1);
  a = 0;
  while (k >= 3)
    {
      tab[a] = 0;
      k = k - 1;
      a = a + 1;
    }
  k = (len1 + len2 + 1);
  while (len1 >= 0)
    {
      tab[k] = str[len1] - '0';
      len1 = len1 - 1;
      k = k - 1;
    }
  return (tab);
}
