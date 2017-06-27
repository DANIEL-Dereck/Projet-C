/*
** my_realloc_tab.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/exec_alias
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Wed Apr 30 10:03:01 2014 bouchard alexandre
** Last update Mon May 19 16:16:45 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char	**my_realloc_tab(char **tab, char *str)
{
  char	**tmp;
  int	i;

  i = -1;
  while (tab != NULL && tab[++i] != NULL);
  if ((tmp = malloc(sizeof(*tmp) * (i + 2))) == NULL)
    return (NULL);
  i = -1;
  while (tab != NULL && tab[++i] != NULL)
    tmp[i] = tab[i];
  if (tab[0] == NULL)
    i = 0;
  tmp[i] = strdup(str);
  tmp[i + 1] = NULL;
  //  free(tab);
  //free(str);
  return (tmp);
}
