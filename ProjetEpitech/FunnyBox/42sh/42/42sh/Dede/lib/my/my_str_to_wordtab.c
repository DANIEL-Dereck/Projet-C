/*
** my_str_to_worktab.c for my_str_to_wordtab.c in /home/le-fra_g/rendu/Piscine-C-lib/my
** 
** Made by le-fra_g
** Login   <le-fra_g@epitech.net>
** 
** Started on  Tue Jan 28 16:32:11 2014 le-fra_g
** Last update Fri May 16 10:16:40 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	**my_tab(char **tab, char *str)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  k = 0;
  while (k < my_strlen(str))
    {
      j = 0;
      while (str[k + j] != 0 && str[k + j] != '\t' && str[k + j] != ' ')
	j++;
      tab[i] = malloc(sizeof(*tab) * (j));
      j=0;
      while (str[k] != 0 && str[k] != '\t' && str[k] != ' ')
	{
	  tab[i][j] = str[k];
	  k++;
	  j++;
	}
      tab[i][j] = 0;
      j = 0;
      k++;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

int	count_caract(char *str)
{
  int i;
  int nb_caract;

  i = 0;
  nb_caract = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\t' && str[i] != ' ')
	{
	  nb_caract++;
	  i++;
	}
      else
	i++;
    }
  return (nb_caract);
}

int	count_word(char *str)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\t' && str[i] == ' ')
      j++;
      i++;
    }
  j++;
  return (j);
}

char	**my_str_to_wordtab(char *str)
{
  int nb_word;
  int nb_caract;
  char **tab;
  int i;

  i = 0;
  nb_word = count_word(str);
  nb_caract = count_caract(str);
  tab = malloc(sizeof(*tab) * (nb_word + 1));
  if (tab == NULL)
    return (0);
  while (nb_word != i)
    {
      tab[i] = malloc(sizeof(**tab) * (nb_caract + 1));
      if (tab[i++] == NULL)
	return (0);
    }
  tab[i] = NULL;
  tab = my_tab(tab, str);
  return (tab);
}
