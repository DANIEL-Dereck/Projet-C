/*
** my_str_to_strtab.c for my_str_to_strtab in /home/besnie_b/Lem_in
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sat May  3 16:17:42 2014 besnie_b
** Last update Sun May  4 20:34:59 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "lem_in.h"

int	my_count_of_tab(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	n++;
      i++;
    }
  return (n);
}

char	**my_size_strtab(char *str, char **tab)
{
  int	i;
  int	n;
  int	k;

  i = 0;
  n = 0;
  k = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n' || str[i + 1] == 0)
	{
	  if ((tab[k] = malloc(sizeof(**tab) * (n + 1))) == NULL)
	    return (0);
	  tab[k][n] = 0;
	  k++;
	  i++;
	  n = 0;
	}
      else
	{
	  i++;
	  n++;
	}
    }
  return (tab);
}

char	**my_finish_tab(char *str, char **tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	{
	  j++;
	  k = 0;
	  i++;
	}
      else
	{
	  tab[j][k] = str[i];
	  k++;
	  i++;
	}
    }
  return (tab);
}

char	**my_str_to_strtab(char	*str)
{
  int	i;
  char	**tab;

  i = my_count_of_tab(str);
  if ((tab = malloc(sizeof(*tab) * (i + 2))) == NULL)
    return (0);
  tab[i + 1] = NULL;
  tab = my_size_strtab(str, tab);
  tab = my_finish_tab(str, tab);
  return (tab);
}
