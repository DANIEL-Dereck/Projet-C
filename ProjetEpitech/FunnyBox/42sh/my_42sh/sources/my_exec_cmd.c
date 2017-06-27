/*
** my_exec_cmd.c for  in /home/boucha_q/Downloads/my_42sh/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Tue May 20 17:18:54 2014 bouchard alexandre
** Last update Sun May 25 23:37:06 2014 daniel_d
*/

#include "../include/sh.h"
#include "../include/my.h"

int	count_list(t_list *list_env)
{
  int i;

  i = 0;
  while (list_env->next != NULL)
    {
      list_env = list_env->next;
      i++;
    }
  return (--i);
}

char	**init_env(t_list *list_env)
{
  char  **env;
  int	i;
  int	l;

  i = count_list(list_env);
  if ((env = malloc(sizeof(**env) * (i + 1))) == NULL)
    return (NULL);
  while (l < i)
    {
      env[l] = my_strdup(list_env->envir);
      l++;
      list_env = list_env->next;
    }
  return (env);
}

int	exec_bis(char **path, char **tab_cmd)
{
  if (path == NULL || tab_cmd == NULL)
    {
      puts("error path or tab_cmd nul exec");
      return (EXIT_FAILURE);
    }
  if ((my_strcmp(tab_cmd[0], "env")) == 0 ||
      (my_strcmp(tab_cmd[0], "echo")) == 0 ||
      (my_strcmp(tab_cmd[0], "cd")) == 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	my_exec_cmd(char **path, char **tab_cmd, t_list *list)
{
  int	i;
  pid_t	pid;
  char  **env;

  i = -1;
  if ((env = init_env(list)) == NULL)
    return (EXIT_FAILURE);
  if ((exec_bis(path, tab_cmd)) == EXIT_SUCCESS)
  while (path[++i] != '\0')
    {
      if ((access(path[i], F_OK)) == 0)
	{
	  pid = fork();
	  if (pid == 0)
	    {
	      execve(path[i], tab_cmd, env);
	      return (EXIT_SUCCESS);
	    }
	  else
	    {
	      wait(NULL);
	      return (EXIT_SUCCESS);
	    }
	}
    }
  return (EXIT_FAILURE);
}
