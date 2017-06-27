/*
** setenv.c for Setenv in /home/aubry_f/rendu/42sh/setenv
**
** Made by aubry_f
** Login   <aubry_f@epitech.net>
**
** Started on  Wed Apr 30 14:15:38 2014 aubry_f
** Last update Sat May 24 17:36:26 2014 bouchard alexandre
*/

#include "../../include/sh.h"

int     match_test(t_list **list, char *name)
{
  t_list *tmp;
  int	a;
  int	c;

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

void	list_overwrite(t_list **list, char *envir, int c)
{
  t_list *tmp;
  int	count;

  count = 1;
  tmp = *list;
  while (count != c)
    {
      tmp = tmp->next;
      count++;
    }
  tmp->envir = envir;
}

char	*new_envir(char *envir, char **param, int len_tab)
{
  int	lenn;
  int	lenv;

  lenv = 0;
  lenn = strlen(param[1]);
  if (len_tab == 3)
    lenv = strlen(param[2]);
  if ((envir = malloc(sizeof(*envir) * (lenn + lenv + 2))) == NULL)
    return (0);
  envir = strcpy(envir, param[1]);
  envir = strcat(envir, "=");
  if (len_tab == 3)
    envir = strcat(envir, param[2]);
  envir = strcat(envir, "\0");
  return (envir);
}

int	name_check(char *name) // on vérifie si il y a un = dans le name
{
  int	count;

  count = -1;
  while (name[++count] != 0)
    if (name[count] == '=')
      return (-1);
  return (0);
}

t_list	*my_setenv(char **param, t_list *list, int len_tab)
{
  int	c;
  char	*envir;

  c = 0;
  if (name_check(param[1]) == -1)
    {
      printf("ERROR : name contains a '='\n");
      return (list);
    }
  envir = NULL;
  envir = new_envir(envir, param, len_tab);
  if ((c = match_test(&list, param[1])) != 0)
    list_overwrite(&list, envir, c);
  if (match_test(&list, param[1]) == 0)
    put_tail_list(&list, envir);
  return (list);
}
