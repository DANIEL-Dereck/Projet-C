/*
** str_to_wordtab.c for minishell2 in /home/cordon_b/rendu/PSU_2013_minishell2/srcs
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Mon Feb 17 13:44:19 2014 cordon_b
** Last update Sat May 10 16:37:22 2014 cordon_b
*/

#include <stdlib.h>
#include "rush.h"

char	*my_fill_zero_tab(char *str, int c)
{
  int	a;

  a = 0;
  while (a < c + 1)
    {
      str[a] = '\0';
      a++;
    }
  return (str);
}

char	**write_lane(char **tab, char *str, char sep)
{
  int	a;
  int	b;
  int	c;

  c = 0;
  b = 0;
  a = -1;
  while (str[++a])
    {
      if (str[a] == sep)
	{
	  tab[b][c] = '\0';
	  c = 0;
	  b++;
	  a++;
	}
      if (str[a] == '\0')
	{
	  tab[b] = NULL;
	  return (tab);
	}
      tab[b][c] = str[a];
      c++;
    }
  return (tab);
}

char	**malloc_lane(char **tab, char *str, char sep)
{
  int	a;
  int	b;
  int	c;

  a = 0;
  b = 0;
  c = 1;
  while (str[a])
    {
      if (str[a] == sep || str[a + 1] == '\0')
	{
	  tab[b] = malloc((c + 1) * sizeof (*tab[b]));
	  tab[b] = my_fill_zero_tab(tab[b], c);
	  c = 0;
	  b++;
	}
      a++;
      c++;
    }
  tab = write_lane(tab, str, sep);
  return (tab);
}

char	**malloctab(char *str, char sep)
{
  int	a;
  int	b;
  char	**tab;

  b = 1;
  a = 0;
  while (str[a])
    {
      if (str[a] == sep)
	b++;
      a++;
    }
  tab = NULL;
  tab = malloc((b + 1) * sizeof (*tab));
  if (tab == NULL)
    return (NULL);
  tab[b] = NULL;
  tab = malloc_lane(tab, str, sep);
  return (tab);
}

char	**str_to_wordtab(char *str, char sep)
{
  char	**tab;

  tab = malloctab(str, sep);
  return (tab);
}
