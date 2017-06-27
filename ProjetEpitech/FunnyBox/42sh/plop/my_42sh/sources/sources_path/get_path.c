/*
** get_path.c for  in /home/boucha_q/rendu/PSU_42/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 09:11:31 2014 bouchard alexandre
** Last update Sun May 25 20:58:57 2014 bouchard alexandre
*/

#include "../../include/sh.h"
#include "../../include/my.h"

int     my_match(char *str, char *str1)
{
  int   i;

  i = 0;
  if (str == NULL || str1 == NULL)
    return (-1);
  while (str[i] != '\0' && str1[i] != '\0' && str[i] != '=' && str1[i] != '=')
    {
      if (str[i] != str1[i])
        return (-1);
      i++;
    }
  return (0);
}

char    *fill_path(t_list *list)
{
  char  *str;

  str = "PATH=";
  if (list == NULL)
    return (NULL);
  while (list->envir != NULL)
    {
      if (my_match(str, list->envir) == 0)
	return (list->envir);
      if ((list = list->next) == NULL)
	return (NULL);
    }
  return (NULL);
}

char    *get_path(t_list *list)
{
  int   i;
  int   j;
  char  *str;
  char  *path;

  i = 5;
  j = 0;
  str = fill_path(list);
  if (str == NULL)
    return (NULL);
  if ((path = malloc(sizeof(*path) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    path[j++] = str[i++];
  path[j] = '\0';
  return (path);
}
