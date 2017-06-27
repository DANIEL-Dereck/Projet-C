/*
** setenv.c for Setenv in /home/aubry_f/rendu/42sh/setenv
**
** Made by aubry_f
** Login   <aubry_f@epitech.net>
**
** Started on  Wed Apr 30 14:15:38 2014 aubry_f
** Last update Sat May 17 13:44:25 2014 bouchard alexandre
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int     match_test(t_list **list, char *name) // vérification dans la liste si name éxiste
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


void	list_overwrite(t_list **list, char *envir, int c) // remplace le string du maillon par le nouveau
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

char	*new_envir(char *envir, char *name, char *value) // on regroupe name et value dans un string
{
  int	lenn;
  int	lenv;

  lenn = my_strlen(name);
  lenv = my_strlen(value);
  if ((envir = malloc(sizeof(*envir) * (lenn + lenv + 2))) == NULL)
    return (0);
  envir = my_strcpy(envir, name);
  envir = my_strcat(envir, "=");
  envir = my_strcat(envir, value);
  envir = my_strcat(envir, "\0");
  return (envir);
}

int	name_check(char *name) // on vérifie si il y a un = dans le name
{
  int	count;

  count = 0;
  while (name[count] != 0)
    if (name[count++] == '=')
      return (-1);
  return (0);
}

int	setenv_main(char *name, char *value, int overwrite, char **env) // main du setenv
{
  t_list *list;
  int	c;
  char	*envir;

  list = NULL;
  c = 0;
  if (name_check(name) == -1)
    {
      printf("ERROR : name contains a '='\n");
      return (0);
    }
  envir = NULL;
  envir = new_envir(envir, name, value);
  printf("envir=%s", envir);
  while (env[c] != NULL)
    put_tail_list(&list, env[c++]);
  if ((c = match_test(&list, name)) != 0 && overwrite != 0)
    list_overwrite(&list, envir, c);
  if (match_test(&list, name) == 0)
    put_tail_list(&list, envir);
  show_list(&list);
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  int	overwrite;

  if (argc != 4)
    {
      printf("Usage : ./setenv [string name] [string value] [int overwrite]\n");
      return (0);
    }
  overwrite = my_getnbr(argv[3]);
  setenv_main(argv[1], argv[2], overwrite, env);
  return (0);
}
