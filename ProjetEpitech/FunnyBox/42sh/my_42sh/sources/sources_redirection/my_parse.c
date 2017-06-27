/*
** do_op.c for do_op.c in /home/le-fra_g/lol/my_42sh/sources/sources_redirection
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Thu May 22 14:43:38 2014 le-franc
** Last update Sun May 25 22:33:04 2014 daniel_d
*/

#include "../../include/my.h"
#include "../../include/sh.h"

t_list	*my_exec_total(t_list *list, char *buff, int *i)
{
  char	**tab_buff;
  int	error;
  char  **path;

  path = my_path(list, buff);
  tab_buff = my_str_to_wordtab(buff);
  *i = my_exec_cmd(path, tab_buff, list);
  list = check_builtins(tab_buff, list, &error);
  return (list);
}

t_list	*my_parse(char *cmd, t_list *list)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = pars_redirection(cmd)) == NULL)
    return (list);
  if (tab[1] == NULL && tab[0] != NULL)
    my_exec_total(list, cmd, &i);
  else if (my_strcmp(tab[1], "&&") == 0 && tab[0] != NULL && tab[2] != NULL)
    list = my_and(tab[0], tab[2], list);
  else if (my_strcmp(tab[1], "||") == 0 && tab[0] != NULL && tab[2] != NULL)
    list = my_or(tab[0], tab[2], list);
  else if (my_strcmp(tab[1], ";") == 0 && tab[0] != NULL && tab[2] != NULL)
    list = my_semicolon(tab[0], tab[2], list);
  else if (my_strcmp(tab[1], ">") == 0 && tab[0] != NULL && tab[2] != NULL)
    list = my_redir_right(tab[0], tab[2], list);
  else if (my_strcmp(tab[1], ">>") == 0 && tab[0] != NULL && tab[2] != NULL)
    list = my_double_redir_right(tab[0], tab[2], list);
  return (list);
}
