/*
** my_cd.c for minishell in /home/daniel_d/rendu/minishell1_re/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 29 09:55:26 2014 daniel_d
** Last update Sun May 25 23:33:44 2014 daniel_d
*/

#include "../../include/sh.h"
#include "../../include/my.h"

int	take_direction(char *home, char *where)
{
  char	*str;
  int	k;
  int	end;
  int	i;

  i = 0;
  k = 0;
  if (home == NULL || where == NULL)
    return (-1);
  end = my_strlen(home);
  i = my_needposchar(where, '=') + 1;
  if ((str = malloc(sizeof(*str) * (end - i + 1))) == NULL)
    return (-1);
  while (i < end)
    {
      str[k++] = home[i++];
    }
  str[k] = '\0';
  if (chdir(str) != 0)
    printf("42sh: cd: %s: No such file or directory\n", str);
  free(str);
  return (0);
}

int     my_cd_tiret(t_list *list)
{
  int   pos;

  pos = my_needposchar("OLDPWD=", '=') + 1;
  while (list->envir != NULL)
    {
      if (my_nmatch("OLDPWD=", list->envir, pos) == 0)
	{
	  if (take_direction(list->envir, "OLDPWD=") == 1)
	    return (-1);
	  if (aff_directory(list->envir, pos) == -1)
	    return (-1);
	  return (0);
	}
      list = list->next;
    }
  printf("42sh : cd: OLDPWD not set.\n");
  return (-1);
}

int	my_gohome(t_list *list)
{
  int	pos;

  pos = my_needposchar("HOME=", '=');
  while (list->envir != NULL)
    {
      if (my_nmatch("HOME=", list->envir, pos + 1) == 0)
	{
	  if (take_direction(list->envir, "HOME=") == -1)
	    return (-1);
	  return (0);
	}
      list = list->next;
    }
  printf("ERROR : 'HOME' doesn't exist.\n");
  return (-1);
}

int	my_cd_exec(char *buffer)
{
  int	l;
  char	*str;

  l = 3;
  if ((str = malloc(sizeof(*str))) == NULL)
    return (-1);
  if (my_strcmp("..", buffer) == 0)
    {
      if ((str = my_strdup("../")) == NULL)
	return (-1);
    }
  else if (my_strcmp("...", buffer) == 0)
    {
      if ((str = my_strdup("../../")) == NULL)
	return (-1);
    }
  else
    if ((str = cpydirec(l, str, buffer)) == NULL)
      return (-1);
  if (chdir(str) != 0)
    {
      printf("42sh: cd: %s: No such file or directory\n", str);
    }
  free(str);
  return (0);
}

t_list	*my_cd(char *buffer, t_list *list)
{
  if (my_strcmp("cd -", buffer) == 0)
    {
      if (my_cd_tiret(list) == -1)
	return (NULL);
    }
  else if (my_strcmp("cd", buffer) == 0)
    {
      if (my_gohome(list) == -1)
	return (NULL);
    }
  else
    if (my_cd_exec(buffer) == -1)
      return (NULL);
  return (list);
}
