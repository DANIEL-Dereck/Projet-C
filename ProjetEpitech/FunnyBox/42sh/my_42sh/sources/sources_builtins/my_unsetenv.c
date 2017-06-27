/*
** my_unsetenv.c for unsetenv in /home/dumlup_i/rendu/PSU_2013_42h/unsetenv/src
**
** Made by dumlup_i
** Login   <dumlup_i@epitech.net>
**
** Started on  Wed May 14 18:46:22 2014 dumlup_i
** Last update Sun May 25 13:59:04 2014 le-franc
*/

#include "../../include/my.h"
#include "../../include/sh.h"

int     match_testbis(t_list **list, char *name)
{
  t_list *tmp;
  int   a;
  int   c;

  c = 1;
  tmp = *list;
  while (tmp != NULL)
    {
      a = 0;
      while (name[a] != 0 && name[a] == tmp->envir[a])
        a++;
      if (name[a] == '\0' && tmp->envir[a] == '=')
        return (c);
      tmp = tmp->next;
      c++;
    }
  return (0);
}

int     list_cancel(t_list **list, int c)
{
  t_list *tmp;
  t_list *tmp2;
  int   count;

  count = 1;
  tmp = *list;
  if (c == 1)
    {
      *list = tmp->next;
      return (0);
    }
  while (count != (c - 1))
    {
      tmp = tmp->next;
      count++;
    }
  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  return (0);
}

t_list     *my_unsetenv(char **param, t_list *list)
{
  int   c;

  c = 0;
  if (param[1][0] == '*')
    {
      list = NULL;
      return (list);
    }
  if ((c = match_testbis(&list, param[1])) != 0)
    list_cancel(&list, c);
  else
    {
      printf("%s does not exist in env\n", param[1]);
      return (list);
    }
  return (list);
}
