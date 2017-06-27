/*
** my_command.c for exec_commande in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 13 15:47:53 2014 daniel_d
** Last update Wed May 21 08:47:38 2014 daniel_d
*/

#include "mysh.h"

char	**my_path(char **path, char **env)
{
  int	i;

  i = 0;
  while (my_nmatch("PATH=", env[i], 5) != 0)
    i = i + 1;
  path = my_path_to_wordtab(env[i]);
  return (path);
}

char	*my_access(char **path, char *cmd)
{
  int	i;

  i = 0;
  if (cmd == NULL)
    return (NULL);
  if (access(cmd, F_OK) == 0)
    return (cmd);
  else
    {
      while (path[i] != NULL)
	{
	  path[i] = my_strcat(path[i], cmd);
	  if (access(path[i], F_OK) == 0)
	    return (path[i]);
	  else
	    i++;
	}
      my_printf("Command not found .\n");
    }
  return (NULL);
}

int	exec_cmd(char **tabcmd, char **env)
{
  int	result;
  int	pid;

  result = 0;
  pid = fork();
  if (pid == -1)
    return (-1);
  if (pid == 0)
    {
      if (execve(tabcmd[0], tabcmd, env) == -1)
	{
	  my_printf("Command not found.\n");
	  result = -1;
	}
      exit(pid);
    }
  wait(&pid);
  return (result);
}

int	my_exec_cmd(char *cmd, char **path, char **env)
{
  char	**tabcmd;

  tabcmd = my_str_to_wordtab(cmd);
  tabcmd[0] = my_access(path, tabcmd[0]);
  if (tabcmd[0] == NULL)
    return (-1);
  if (exec_cmd(tabcmd, env) == -1)
    return (-1);
  return (0);
}

int	my_exec(char *cmd, char **env)
{
  char	**path;

  if ((path = malloc(sizeof(**path))) == NULL)
    return (-1);
  path = my_path(path, env);
  if (my_exec_cmd(cmd, path, env) == -1)
    return (-1);
  return (0);
}
