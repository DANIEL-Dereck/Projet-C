/*
** my_path_to_wordtab.c for  in /home/boucha_q/rendu/PSU_42/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 09:36:17 2014 bouchard alexandre
** Last update Mon May 19 14:09:40 2014 le-franc
*/

#include "../include/my.h"

int     count_line_str(char *str)
{
  int	j;
  int	c;

  j = 0;
  c = 0;
  while (str != NULL && str[j] != '\0')
    {
      if (str[j] == ' ')
        c++;
      j++;
    }
  return (c);
}

int     count_long_line_str(char *str, int j)
{
  int   size;

  size = 0;
  while (str[j] != ' ' && str[j] != '\0')
    {
      j++;
      size++;
    }
  return (size);
}

char  **fill_tab_str(char *str, int c, int i, int j)
{
  int   k;
  char  **tab;

  k = 0;
  if ((tab = malloc(sizeof(*tab) * (c + 2))) == NULL)
    return (NULL);
  while (str[j] != '\0')
    {
      if ((tab[i] = malloc(sizeof(**tab) *
			   count_long_line_str(str, j) + 3)) == NULL)
	return (NULL);
      while (str[j] != ' ' && str[j] != '\0')
          tab[i][k++] = str[j++];
      tab[i][k++] = '/';
      tab[i][k] = '\0';
      k = 0;
      i++;
      if (str[j])
	j++;
    }
  tab[i] = NULL;
  return (tab);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  int   c;

  c = count_line_str(str);
  tab = fill_tab_str(str, c, 0, 0);
  if (tab == NULL)
    return (NULL);
  return (tab);
}
