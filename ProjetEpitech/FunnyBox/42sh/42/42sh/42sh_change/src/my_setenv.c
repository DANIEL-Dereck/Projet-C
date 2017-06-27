/*
** my_setenv.c for setenv in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 13 10:55:31 2014 daniel_d
** Last update Tue May 13 14:12:28 2014 daniel_d
*/

#include "mysh.h"

char	**my_setenv(char *cmd, char **env)
{
  my_printf("setenv : cmd = %s, env[0] = %s\n", cmd, env[0]);
  return (env);
}
