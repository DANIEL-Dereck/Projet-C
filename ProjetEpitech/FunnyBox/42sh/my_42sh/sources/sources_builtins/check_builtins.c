/*
** check_builtins.c for  in /home/boucha_q/Downloads/my_42sh/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Tue May 20 17:38:43 2014 bouchard alexandre
** Last update Sun May 25 23:07:27 2014 dumlup_i
*/

#include "../../include/sh.h"
#include "../../include/my.h"

t_list	*send_cd(char **tab_cmd, t_list *list_env, int len_tab)
{
  char	*cmd;

  if (len_tab == 1)
    list_env = my_cd(tab_cmd[0], list_env);
  else if (len_tab == 2)
    {
      cmd = my_strcat("cd ", tab_cmd[1]);
      list_env = my_cd(cmd, list_env);
    }
  return (list_env);
}

int	send_exit(char	**tab_cmd, int len_tab)
{
  char	*cmd;
  int	error;

  error = 0;
  if (len_tab == 1)
    return (0);
  else
    {
      cmd = my_strcat(tab_cmd[0], " ");
      cmd = my_strcat(cmd, tab_cmd[1]);
      return (error = my_exit(cmd));
    }
}

t_list	*send_setenv(char **tab_cmd, t_list *list_env, int len_tab)
{
  if (len_tab == 1)
    my_env(&list_env);
  else if (len_tab == 2 || len_tab == 3)
    list_env = my_setenv(tab_cmd, list_env, len_tab);
  else
    printf("to many argument in setenv");
  return (list_env);
}

void	send_echo(char **tab_cmd, int len_tab)
{
  char	*cmd;
  int	i;
  int	error;

  i = 0;
  if (len_tab > 1)
    {
      cmd = my_strcat(tab_cmd[0], " ");
      while (tab_cmd[++i] != NULL)
	{
	  cmd = my_strcat(cmd, tab_cmd[i]);
	  if (tab_cmd[i + 1] != NULL)
	    cmd = my_strcat(cmd, " ");
	}
    }
  else
    cmd = "echo";
  if ((error = my_echo(cmd)) == -1)
    printf("Invalid option echo\n");
}

t_list	*check_builtins(char **tab_cmd, t_list *list_env, int *exit)
{
  int	len_tab;

  len_tab = -1;
  while (tab_cmd[++len_tab] != NULL);
  if (my_strcmp("cd", tab_cmd[0]) == 0 || my_nmatch("..", tab_cmd[0], 2) == 0)
    list_env = send_cd(tab_cmd, list_env, len_tab);
  else if (my_strcmp("echo", tab_cmd[0]) == 0)
    send_echo(tab_cmd, len_tab);
  else if (my_strcmp("exit", tab_cmd[0]) == 0)
    *exit = send_exit(tab_cmd, len_tab);
  else if (my_strcmp("setenv", tab_cmd[0]) == 0)
    send_setenv(tab_cmd, list_env, len_tab);
  else if (my_strcmp("env", tab_cmd[0]) == 0)
    my_env(&list_env);
  else if (my_strcmp("unsetenv", tab_cmd[0]) == 0 && len_tab == 2)
    list_env = my_unsetenv(tab_cmd, list_env);
  return (list_env);
}
