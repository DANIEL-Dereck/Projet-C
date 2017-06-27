/*
** my_cd.c for minishell in /home/daniel_d/rendu/minishell1_re/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 29 09:55:26 2014 daniel_d
** Last update Thu May 15 15:25:21 2014 le-franc
*/

#include "mysh.h"

int	take_direction(char *home)
{
  char	*str;
  int	k;
  int	end;
  int	i;

  i = 0;
  k = 0;
  end = my_strlen(home);
  while (home[i] != '=')
    i++;
  i++;
  if ((str = malloc(sizeof(*str) * (end - i))) == NULL)
    return (-1);
  while (i < end)
    {
      str[k++] = home[i++];
    }
  if (chdir(str) != 0)
    my_printf("42sh: cd: %s: No such file or directory\n", str);
  free(str);
  return (0);
}

int     my_cd_tiret(char **env)
{
  int   pos;
  int   i;

  i = 0;
  pos = my_needposchar("OLDPWD=", '=');
  while (env[i] != NULL)
    {
      if (my_nmatch("OLDPWD=", env[i], pos) == 0)
	{
	  if (take_direction(env[i]) == 1)
	    return (-1);
	  if (aff_directory(env[i], pos) == -1)
	    return (-1);
	  return (0);
	}
      i++;
    }
  my_printf("42sh : cd: OLDPWD not set.\n");
  return (-1);
}

int	my_gohome(char **env)
{
  int	pos;
  int	i;

  i = 0;
  pos = my_needposchar("HOME=", '=');
  while (env[i] != NULL)
    {
      if (my_nmatch("HOME=", env[i], pos))
	{
	  if (take_direction(env[i]) == -1)
	    return (-1);
	  return (0);
	}
      i++;
    }
  my_printf("ERROR : 'HOME' doesn't exist.\n");
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
      my_printf("42sh: cd: %s: No such file or directory\n", str);
    }
  free(str);
  return (0);
}

int	my_cd(char *buffer, char **env)
{
  if (my_strcmp("cd -", buffer) == 0)
    {
      if (my_cd_tiret(env) == -1)
	return (-1);
    }
  else if (my_strcmp("cd", buffer) == 0)
    {
      if (my_gohome(env) == -1)
	return (-1);
    }
  else
    if (my_cd_exec(buffer) == -1)
      return (-1);
  return (0);
}
