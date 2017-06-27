/*
** mini.c for minishell2 in /home/daniel_d/rendu/PSU_2013_minishell2
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Feb 24 09:20:02 2014 daniel_d
** Last update Sun Mar  9 21:30:54 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "my_minishell.h"

int     my_clear_prompt(char **envp)
{
  int   status;
  pid_t pid;
  char  **cmd;

  cmd = NULL;
  if ((pid = fork()) == 0)
    {
      execve("/usr/bin/clear", cmd, envp);
      exit(1);
    }
  wait(&status);
  return (0);
}

char	*my_clearbuff(char *buffer)
{
  int	l;
  int	i;

  i = 0;
  l = my_strlen(buffer);
  while (i <= l)
    buffer[i++] = '\0';
  return (buffer);
}

int	provid(char *buffer, char **envp, int r)
{
  int	k;

  my_printf("mysh$>");
  signal_set();
  if ((r = read(0, buffer, 4095)) > 0)
    {
      if (my_strcmp("exit\n", buffer) == 2)
	return (2);
      else if ((buffer[0] == 'c' && buffer[1] == 'd') ||
	       my_strcmp("..\n", buffer) == 2)
	my_cd(buffer);
      else if (buffer[0] != '\n')
	if ((k = my_parscmd(envp, buffer)) == -1)
	  return (0);
      buffer = my_clearbuff(buffer);
    }
  else
    {
      free(buffer);
      return (2);
    }
  return (0);
}

int     my_prompt(char **envp)
{
  char  *buffer;
  int   r;
  int	v;

  r = 0;
  v = 0;
  my_clear_prompt(envp);
  if ((buffer = malloc(sizeof(buffer) * 4096)) == NULL)
    return (0);
  while (42)
    {
      v = provid(buffer, envp, r);
      if (v == 2)
	{
	  free(buffer);
	  my_clear_prompt(envp);
	  return (0);
	}
      else if (v == -1)
	my_printf("ERROR\n");
    }
  free(buffer);
  return (0);
}
