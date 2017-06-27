/*
** main.c for  in /home/boucha_q/rendu/PSU_42
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 08:51:32 2014 bouchard alexandre
** Last update Mon May 19 16:17:25 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char	**my_path(char **env, char *buff)
{
  char	*path;
  char	**tab_path;
  int	i;

  i = 0;
  tab_path = NULL;
  path = get_path(env);
  if (path == NULL)
    my_putstr("path non remplis");
  else
    {
      tab_path = my_path_to_wordtab(path);
      while (tab_path[i] != '\0')
	{
	  tab_path[i] = fill_func_path(tab_path[i], buff);
	  i++;
	}
      i = 0;
      return (tab_path);
    }
  return (NULL);
}
