/*
** my_prompt.c for 42 in /home/daniel_d/rendu/42/42sh/Dede/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 16:52:36 2014 daniel_d
** Last update Tue May 20 16:05:10 2014 daniel_d
*/

#include "mysh.h"
#include "my.h"

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
  while ((rd = read(0, tmp, 1)) != 0 && rd != -1)
    {
      if (buff[0] == '\0' && tmp[0] == '\n')
	return ("\n");
      if (tmp[0] == '\n')
	return (buff);
      buff = my_strcat(buff, tmp);
      if (rd <= 0)
	return ("\0");
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
    my_printf("setenv\n");
  else if (my_nmatch("unsetenv", cmd, 8) == 0)
    my_printf("unsetenv\n");
  else
    my_exec(cmd, env);
  return (env);
}

int     my_prompt(char **env)
{
  char  *cmd;

  signal_set();
  my_putstr("$>");
  while ((cmd = my_read()) != NULL)
    {
      if (cmd[0] == '\n')
        my_putstr("\0");
      else if (my_nmatch("exit", cmd, 4) == 0)
	return (my_exit(cmd));
      else if ((env = my_check_cmd(cmd, env)) == NULL)
	return (-1);
      if (cmd[0] == '\0')
	my_putstr("\n");
      my_putstr("$>");
      free(cmd);
    }
  my_putstr("exit\n");
  return (0);
}
