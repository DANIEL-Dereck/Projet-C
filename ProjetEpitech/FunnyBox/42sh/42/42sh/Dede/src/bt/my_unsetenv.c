/*
** my_unsetenv.c for unsetenv in /home/dumlup_i/rendu/PSU_2013_42h/unsetenv/src
**
** Made by dumlup_i
** Login   <dumlup_i@epitech.net>
**
** Started on  Wed May 14 18:46:22 2014 dumlup_i
** Last update Mon May 19 10:24:45 2014 bouchard alexandre
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"
/*
int     match_test(t_list **list, char *name) // vérification dans la liste si name éxiste
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
*/
int     list_cancel(t_list **list, int c) // suppression du maillon à la position c
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

int     unsetenv_main(char *name, char **env) // fonction principale
{
  t_list *list;
  int   c;

  list = NULL;
  c = 0;
  while (env[c] != NULL)
    put_tail_list(&list, env[c++]);
  if (name[0] == '*')
    {
      list = NULL;
      return (0);
    }
  /*
  if ((c = match_test(&list, name)) != 0)
    list_cancel(&list, c);
  else
    {
      printf("%s does not exist in env\n", name);
      return (0);
      }*/
  show_list(&list);
  return (0);
}
/*
int	main(int ac, char **av, char **env)
{
  if (ac != 2)
    {
      printf("Usage : ./unsetenv [string name]\n");
      return (0);
    }
  unsetenv_main(av[1], env);
  return (0);
}
*/
