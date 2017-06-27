/*
** my_prompt.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell1
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 16:12:13 2013 daniel_d
** Last update Thu Apr 24 15:36:24 2014 daniel_d
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

char    *my_concat_str(char *usrbin, char *cmd)
{
  char	*str;
  int i;
  int k;

  i = 0;
  k = 0;
  if (usrbin == NULL)
    return (0);
  if ((str = malloc(sizeof(str) *
		    (my_strlen(usrbin) + my_strlen(cmd)))) == NULL)
    return (0);
  if (usrbin == NULL)
    return (0);
  while (usrbin[i] != '\0')
    str[k++] = usrbin[i++];
  i = 0;
  str[k++] = '/';
  if (cmd == NULL)
      return (0);
  while (cmd[i] != '\0')
    str[k++] = cmd[i++];
  return (str);
}

char	*axe_s(char *usrbin, char **bin, char *cmd)
{
  int	t;
  int	k;

  t = 0;
  k = 0;
  if (bin[0] == NULL)
    return (NULL);
  while ((k = access(usrbin, F_OK)) != 0 && bin[t] != NULL)
    usrbin = my_concat_str(bin[t++], cmd);
  if (k == -1 || bin[t] == NULL)
    return (NULL);
  return (usrbin);
}

int	runner(char *usrbin, char **bin, char **cmd, char **envp)
{
  pid_t pid;
  int	status;

  if ((usrbin = axe_s(usrbin, bin, cmd[0])) == NULL)
    {
      my_printf("ERROR: Command not found\n");
      return (0);
    }
  if ((pid = fork()) == 0)
    {
      if (execve(usrbin, cmd, envp) == -1)
        my_printf("ERROR: command not found\n");
      exit(1);
    }
  else
    wait(&status);
  return (0);
}

int     run_cmd(char **envp, char *buffer)
{
  char	**cmd;
  char	*usrbin;
  char	**bin;
  int	k;

  k = 0;
  usrbin = my_path(envp);
  bin = my_str_to_wordtab(usrbin);
  cmd = my_str_to_wordtab(buffer);
  runner(usrbin, bin, cmd, envp);
  while (cmd[k] != NULL)
    free(cmd[k++]);
  k = 0;
  while (bin[k] != NULL)
    free(bin[k++]);
  k = 0;
  free(cmd);
  free(bin);
  return (0);
}
