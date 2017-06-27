/*
** my_command.c for my_command in /home/le-fra_g/rendu/PSU/PSU_2013_minishell1
** 
** Made by le-fra_g
** Login   <le-fra_g@epitech.net>
** 
** Started on  Wed Jan 22 16:08:58 2014 le-fra_g
** Last update Sun Mar  9 22:09:50 2014 le-fra_g
*/

#include "mysh.h"

char	*my_cp_cmd_path(char *path, char *cmd)
{
  char *tmp;
  int i;
  int j;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(*tmp) * (my_strlen(path) + my_strlen(cmd) + 2));
  if (tmp == NULL)
    return (0);
  while (path[j] != '\0')
    {
      tmp[i++] = path[j++];
    }
  tmp[i] = '/';
  i++;
  j = 0;
  while (cmd[j + (cmd[j] && cmd[j + 1] == '\n')] != '\0')
    {
      tmp[i++] = cmd[j++];
    }
  tmp[i] = 0;
  return (tmp);
}

char	**my_path(char **path, char *cmd)
{
  int i;
  char **path2;

  i = 0;
  while (path[i] != '\0')
    i++;
  path2 = malloc(sizeof(path) * (i + 1));
  if (path2 == NULL)
    return (NULL);
  i = 0;
  while (path[i] != NULL)
    {
      path2[i] = my_cp_cmd_path(path[i], cmd);
      i++;
    }
  path2[i] = NULL;
  return (path2);
}

char	**exec()
{
  extern char **environ;
  char *str;
  int   i;
  char **tab;
  char **path;

  tab = environ;
  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == 'P' && tab[i][1] == 'A' &&
	  tab[i][2] == 'T' && tab[i][3] == 'H')
	{
	  str = tab[i];
	  path = my_str_to_wordtab(str);
	}
      i++;
    }
  return (path);
}

char	*pre_path(char **path)
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

int	my_execfunk(char **path, char **cmd)
{
  extern char **environ;
  int pid;
  char *s;

  s = pre_path(path);
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
