/*
** my_env_in_list.c for my_env_in_list in /home/boucha_q/rendu/PSU_2013_minishell1
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Fri Mar  7 16:03:49 2014 bouchard alexandre
** Last update Sun May 25 22:20:35 2014 daniel_d
*/

#include "../include/sh.h"

int     my_put_in_list(t_list **list_a, char *strenv)
{
  t_list *elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->envir = strenv;
  elem->next = *list_a;
  *list_a = elem;
  return (0);
}

t_list	*my_env_in_list(t_list *list_a, char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      my_put_in_list(&list_a, env[i]);
      i++;
    }
  return (list_a);
}
