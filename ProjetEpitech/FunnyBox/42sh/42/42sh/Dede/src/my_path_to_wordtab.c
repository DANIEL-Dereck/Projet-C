/*
** my_path_to_wordtab.c for  in /home/boucha_q/rendu/PSU_42/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 09:36:17 2014 bouchard alexandre
** Last update Wed May 14 10:35:25 2014 daniel_d
*/

#include "mysh.h"

int     count_line_path(char *path)
{
  int	j;
  int	c;

  j = 0;
  c = 0;
  while (path != NULL && path[j] != '\0')
    {
      if (path[j] == ':')
        c++;
      j++;
    }
  return (c);
}

int     count_long_line_path(char *str, int j)
{
  int   size;

  size = 0;
  while (str[j] != ':' && str[j] != '\0')
    {
      j++;
      size++;
    }
  return (size);
}

char  **fill_tab_path(char *path, int c, int i, int j)
{
  int   k;
  char  **tab;

  k = 0;
  if ((tab = malloc(sizeof(*tab) * (c + 2))) == NULL)
    return (NULL);
  while (path[j] != '\0')
    {
      if ((tab[i] = malloc(sizeof(**tab) *
			   count_long_line_path(path, j) + 3)) == NULL)
	return (NULL);
      while (path[j] != ':' && path[j] != '\0')
          tab[i][k++] = path[j++];
      tab[i][k++] = '/';
      tab[i][k] = '\0';
      k = 0;
      i++;
      if (path[j])
	j++;
    }
  tab[i] = NULL;
  return (tab);
}

char    **my_path_to_wordtab(char *path)
{
  char  **tab;
  int   c;

  c = count_line_path(path);
  tab = fill_tab_path(path, c, 0, 0);
  if (tab == NULL)
    return (NULL);
  return (tab);
}
