/*
** separator.c for separator in /home/daniel_d/rendu/42/42sh/Dede/redirection
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri May 23 14:18:56 2014 daniel_d
** Last update Sun May 25 23:01:06 2014 dumlup_i
*/

#include "../../include/my.h"
#include "../../include/sh.h"

t_list	*my_semicolon(char *cmd1, char *cmd2, t_list *list)
{
  int	i;

  i = 0;
  my_exec_total(list, cmd1, &i);
  my_exec_total(list, cmd2, &i);
  return (list);
}

t_list	*my_or(char *cmd1, char *cmd2, t_list *list)
{
  int	i;

  i = 0;
  my_exec_total(list, cmd1, &i);
  if (i == EXIT_FAILURE)
    {
      my_exec_total(list, cmd2, &i);
      if (i == EXIT_FAILURE)
	return (list);
    }
  return (list);
}

t_list	*my_and(char *cmd1, char *cmd2, t_list *list)
{
  int	i;

  i = 0;
  my_exec_total(list, cmd1, &i);
  if (i == EXIT_FAILURE)
    return (list);
  my_exec_total(list, cmd2, &i);
  if (i == EXIT_FAILURE)
    return (list);
  return (list);
}
