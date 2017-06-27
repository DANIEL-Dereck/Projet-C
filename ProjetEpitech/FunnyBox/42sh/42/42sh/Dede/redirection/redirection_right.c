/*
** redirection.c for redir in /home/daniel_d/rendu/42/42sh/Dede/redirection
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu May 22 15:14:02 2014 daniel_d
** Last update Sat May 24 14:13:53 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	my_redir_right(char *cmd1, char *cmd2, char **env)
{
  int	ret_val;
  int	fd_file;

  fd_file = 0;
  ret_cal = 0;
  if (fd_file = open(cmd2,  O_CREAT | O_WRONLY | O_TRUNC ,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    return (-1);
  if (dup2(1, fd_file) == -1)
    return (-1);
  if ((ret_val = my_check_cmd(cmd1, env)) == 0)
    return (-1);
  close(fd_file);
  return (ret_val);
}

int	my_double_redir_right(char *cmd1, char *cmd2, char **env)
{
  int	ret_val;
  int	fd_file;

  fd_file = 0;
  ret_cal = 0;
  if (fd_file = open(cmd2,  O_CREAT | O_WRONLY | O_APPEND,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    return (-1);
  if (dup2(1, fd_file) == -1)
    return (-1);
  if ((ret_val = my_check_cmd(cmd1, env)) == 0)
    return (-1);
  close(fd_file);
  return (ret_val);
}
