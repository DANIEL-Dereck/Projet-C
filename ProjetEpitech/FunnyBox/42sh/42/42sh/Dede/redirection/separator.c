/*
** separator.c for separator in /home/daniel_d/rendu/42/42sh/Dede/redirection
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri May 23 14:18:56 2014 daniel_d
** Last update Fri May 23 15:59:54 2014 daniel_d
*/

int     my_semicolon(char *cmd1, char *cmd2, char **env)
{
  int	ret_val;

  ret_val = my_check_cmd(cmd1, env);
  my_check_cmd(cmd2, env);
  return (ret_val);
}

int     my_or(char *cmd1, char *cmd2, char **env)
{
  if (my_check_cmd(cmd1, env) == 0)
    if (my_check_cmd(cmd2, env) == 0)
      return (-1);
  return (0);
}

int     my_and(char *cmd1, char *cmd2, char **env)
{
  if (my_check_cmd(cmd1, env) == 0)
    return (-1);
  if (my_check_cmd(cmd2, env) == 0)
    return (-1);
  return (0);
}
