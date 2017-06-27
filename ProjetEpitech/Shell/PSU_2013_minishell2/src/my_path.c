/*
** my_path.c for minishell2 in /home/daniel_d/rendu/PSU_2013_minishell2/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Feb 24 09:22:59 2014 daniel_d
** Last update Mon Feb 24 10:25:26 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "my_minishell.h"

char    *my_pathname(char *env, char *path)
{
  int   i;
  int   k;

  i = 0;
  k = my_strlen(env);
  path = malloc(sizeof(path) * k - 4);
  k = 5;
  while (env[k] != '\0')
    {
      if (env[k] == ':')
        path[i] = ' ';
      else
        path[i] = env[k];
      i++;
      k++;
    }
  return (path);
}

char    *my_path(char **envp)
{
  char  *path;
  int   i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
          envp[i][2] == 'T' && envp[i][3] == 'H')
        {
          if ((path = malloc(sizeof(path) * my_strlen(envp[i]))) == NULL)
            return (0);
          path = my_pathname(envp[i], path);
        }
      i++;
    }
  return (path);
}
