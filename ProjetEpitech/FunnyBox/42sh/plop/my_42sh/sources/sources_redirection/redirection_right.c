/*
** redirection.c for redir in /home/daniel_d/rendu/42/42sh/Dede/redirection
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu May 22 15:14:02 2014 daniel_d
** Last update Sun May 25 21:59:48 2014 daniel_d
*/

#include "../../include/sh.h"
#include "../../include/my.h"

t_list	*my_redir_right(char *cmd1, char *cmd2, t_list *list)
{
  int	i;
  int	fd_file;

  fd_file = 0;
  i = 0;
  if ((fd_file = open(cmd2,  O_CREAT | O_RDWR | O_TRUNC ,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (list);
  if (dup2(1, fd_file) == -1)
    return (list);
  my_exec_total(list, cmd1, &i);
  if (i == EXIT_FAILURE)
    return (list);
  close(fd_file);
  return (list);
}

t_list	*my_double_redir_right(char *cmd1, char *cmd2, t_list *list)
{
  int	i;
  int	fd_file;

  fd_file = 0;
  i = 0;
  if ((fd_file = open(cmd2,  O_CREAT | O_RDWR ,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (list);
  if (dup2(1, fd_file) == -1)
    return (list);
  my_exec_total(list, cmd1, &i);
  if (i == EXIT_FAILURE)
    return (list);
  close(fd_file);
  return (list);
}
