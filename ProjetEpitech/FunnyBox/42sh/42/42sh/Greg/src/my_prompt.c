/*
** my_prompt.c for 42 in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 16:52:36 2014 daniel_d
** Last update Tue May 13 17:02:14 2014 le-franc
*/

#include "mysh.h"
#include "../include/my.h"

void	my_exec(char *cmd, char **env)
{
  my_printf("exec : cmd = %s env[0] = %s\n", cmd, env[0]);
}

char    *my_read()
{
  char  *buff;
  char  *tmp;
  int   rd;

  rd = 0;
  if ((buff = malloc(sizeof(*buff) * 1)) == NULL ||
      (tmp = malloc(sizeof(*tmp) * 2)) == NULL)
    return (NULL);
  buff[0] = '\0';
  tmp[1] = '\0';
  while ((rd = read(0, tmp, 1)) > 0)
    {
      if (tmp[0] == '\n')
	{
	  buff = my_strcat(buff, '\0');
	  return (buff);
	}
      buff = my_strcat(buff, tmp);
    }
  return (NULL);
}

char	**my_check_cmd(char *cmd, char **env)
{
  if (my_nmatch("cd", cmd, 2) == 0 || my_nmatch("..", cmd, 2) == 0)
    my_cd(cmd, env);
  else if (my_nmatch("echo", cmd, 4) == 0)
    my_echo(cmd);
  else if (my_nmatch("setenv", cmd, 6) == 0)
    env = my_setenv(cmd, env);
  else if (my_nmatch("unsetenv", cmd, 8) == 0)
    env = my_unsetenv(cmd, env);
  else
    my_exec(cmd, env);
  return (env);
}

int     my_prompt(char **env)
{
  char  *cmd;

  signal_set();
  my_putstr(PROMPT);
  while ((cmd = my_read()) != NULL)
    {
      if (cmd[0] == '\0')
        my_putstr("\n");
      if (my_nmatch("exit", cmd, 4) == 0)
	return (my_exit(cmd));
      else if ((env = my_check_cmd(cmd, env)) == NULL)
	return (-1);
      my_putstr(PROMPT);
    }
  return (0);
}
