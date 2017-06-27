/*
** main.c for  in /home/boucha_q/rendu/PSU_42
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 08:51:32 2014 bouchard alexandre
** Last update Sun May 25 21:09:31 2014 bouchard alexandre
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char	**my_path(t_list *list, char *buff)
{
  char	*path;
  char	**tab_path;
  int	i;

  i = -1;
  tab_path = NULL;
  path = get_path(list);
  if (path == NULL && list != NULL)
    printf("Path non remplis");
  else if (path == NULL && list == NULL);
  else
    {
      tab_path = my_path_to_wordtab(path);
      while (tab_path[++i] != '\0')
	  tab_path[i] = fill_func_path(tab_path[i], buff);
      i = 0;
      return (tab_path);
    }
  return (NULL);
}
