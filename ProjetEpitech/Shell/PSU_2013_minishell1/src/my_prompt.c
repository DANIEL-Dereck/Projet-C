/*
** my_prompt.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell1
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 16:12:13 2013 daniel_d
** Last update Mon Jan  6 21:52:04 2014 daniel_d
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include "../Lib/include/my.h"
#include "../Lib/include/my_minishell.h"

char    *my_concat_str(char *usrbin, char *cmd)
{
  int i;
  int k;

  i = 9;
  k = 0;
  while (cmd[k] != '\0' && cmd[k] != '\n' && cmd[k] != ' ')
    usrbin[i++] = cmd[k++];
  return (usrbin);
}

int     run_cmd(char **envp, char *buffer)
{
  pid_t pid;
  int   status;
  char	**cmd;
  char	*usrbin;

  if ((usrbin = malloc(sizeof(usrbin) * (9 + my_strlen(buffer)))) == NULL)
    return (0);
  usrbin[0] = '/';
  usrbin[1] = 'u';
  usrbin[2] = 's';
  usrbin[3] = 'r';
  usrbin[4] = '/';
  usrbin[5] = 'b';
  usrbin[6] = 'i';
  usrbin[7] = 'n';
  usrbin[8] = '/';
  if ((pid = fork()) == 0)
    {
      cmd = my_str_to_wordtab(buffer);
      usrbin = my_concat_str(usrbin, cmd[0]);
      execve(usrbin, cmd, envp);
      exit(1);
    }
  wait(&status);
  return (0);
}

int	my_clear_prompt(char **envp)
{
  int   status;
  pid_t pid;
  char	**cmd;

  cmd = NULL;
  if ((pid = fork()) == 0)
    {
      execve("/usr/bin/clear" , cmd, envp);
      exit(1);
    }
  wait(&status);
  return (0);
}

int	my_prompt(char **envp)
{
  char	buffer[4096];
  int	r;

  r = 0;
  my_clear_prompt(envp);
  while (42)
    {
      my_printf("daniel_d  -> minishell1 $>");
      signal_set();
      if ((r = read(0, buffer, 4095)) != 0)
	{
	  if (buffer[0] == 'e' && buffer[1] == 'x' &&
	      buffer[2] == 'i' && buffer[3] == 't')
	    return (0);
	  run_cmd(envp, buffer);
	}
      else
	my_printf("ERROR : Commande not found");
    }
  return (0);
}
