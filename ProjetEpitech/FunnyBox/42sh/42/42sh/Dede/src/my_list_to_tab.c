/*
** my_list_to_tab.c for lit_to_tab in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri May 16 14:04:40 2014 daniel_d
** Last update Fri May 16 14:34:44 2014 daniel_d
*/

#include "mysh.h"

char	**list_to_tab(t_list *list)
{
  char	**env;
  int	i;

  i = 0;
  if ((env = malloc(sizeof(*env))) == NULL)
    return (NULL);
  while (list->envir != NULL)
    {
      if ((env = realloc(env, (i + 1))) == NULL)
	return (NULL);
      if ((env[i] = strdup(list->envir)) == NULL)
	return (NULL);
      i++;
    }
  return (env);
}
