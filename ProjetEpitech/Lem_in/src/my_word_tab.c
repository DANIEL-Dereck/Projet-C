/*
** my_word_tab.c for my_word_tab in /home/besnie_b/Lem_in
** 
** Made by besnie_b
** Login   <besnie_b@epitech.net>
** 
** Started on  Sun May  4 21:51:45 2014 besnie_b
** Last update Sun May  4 22:24:11 2014 besnie_b
*/

#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"

int     my_nbofword(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i] != 0 && str[i] == ' ')
    {
      i++;
      if (str[i + 1] == 0)
	return (n);
    }
  while (str[i] != 0)
    {
      if (str[i] != '-' && (str[i + 1] == '-' || str[i + 1] == 0))
        n++;
      i++;
    }
  return (n);
}

char    **my_tab_size(char *str, char **tab)
{
  int   i;
  int   k;
  int   n;

  i = 0;
  n = 0;
  k = 0;
  while (str[i] != 0 && str[i] == ' ')
    i++;
  while (str[i] != 0)
    {
      if (str[i] != '-' && (str[i + 1] != '-' || str[i + 1] != 0))
        n++;
      if (str[i] != '-' && (str[i + 1] == '-' || str[i + 1] == 0))
        {
          if ((tab[k] = malloc(sizeof(**tab) * (n + 1))) == NULL)
            return (0);
          tab[k][n + 1] = 0;
          k++;
          n = 0;
        }
      i++;
    }
  return (tab);
}

char    **my_f_tab(char *str, char **tab)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != 0 && str[i] == ' ')
    i++;
  while (str[i] != 0)
    {
      if (str[i] != '-')
        {
          tab[j][k] = str[i];
          k++;
        }
      if (str[i] != '-' && (str[i + 1] == '-' || str[i + 1] == 0))
        {
          k = 0;
          j++;
        }
      i++;
    }
  return (tab);
}

char    **my_word_tab(char *str)
{
  char  **tab;
  int   n;

  n = my_nbofword(str);
  if ((tab = malloc(sizeof(tab) * (n + 1))) == NULL)
    return (0);
  tab = my_tab_size(str, tab);
  tab = my_f_tab(str, tab);
  tab[n] = NULL;
  return (tab);
}
