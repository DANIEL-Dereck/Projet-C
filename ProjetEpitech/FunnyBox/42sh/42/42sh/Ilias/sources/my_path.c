/*
** main.c for  in /home/boucha_q/rendu/PSU_42
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 08:51:32 2014 bouchard alexandre
** Last update Mon May 12 15:43:27 2014 daniel_d
*/

#include "../include/my_read.h"

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

char    *test_access(char **path)
{
  int i;
  char *tmp;

  i = 0;
  tmp = NULL;
  while (path[i] != NULL)
    {
      if ((access(path[i], X_OK)) == 0)
	{
	  tmp = path[i];
	  return (tmp);
	}
      i++;
    }
  return (tmp);
}

int     my_execfunk(char **path, char **cmd)
{
  extern char **environ;
  int pid;
  char *s;

  s = test_access(path);
  pid = fork();
  if (pid == -1)
    return (0);
  if (pid == 0)
    {
      if ((execve(s, cmd, environ)) == -1)
        {
          my_putstr("$> Command not found.\n");
          exit(pid);
        }
    }
  wait(&pid);
  return (0);
}
