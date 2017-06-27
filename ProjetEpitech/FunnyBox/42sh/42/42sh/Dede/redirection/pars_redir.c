/*
** pars_redir.c for pars in /home/daniel_d/rendu/42/42sh/Dede/redirection
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 24 17:00:09 2014 daniel_d
** Last update Sun May 25 18:01:53 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	my_count_with_sep(int sep, char *str)
{
  int	i;

  i = sep;
  while (str[sep] != '\0')
    {
      if (str[sep] == ' ' || str[sep] == '\t')
	i++;
      else if (str[sep] == ';' || str[sep] == '|' || str[sep] == '&' ||
	  str[sep] == '<' || str[sep] == '>')
	{
	  while (str[sep] == ';' || str[sep] == '|' || str[sep] == '&' ||
	  str[sep] == '<' || str[sep] == '>')
	    sep++;
	  return ((sep - i));
	}
      sep++;
    }
  return (0);
}

int	my_count_sep(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|' || str[i] == '<' || str[i] == ';' ||
	  str[i] == '>' || str[i] == '&')
	{
	  while (str[i - 1] == ' ' || str[i - 1] == '\t')
	    i--;
	  return (i);
	}
      i++;
    }
  return (i);
}

char	**my_remp_tab(char **tab, char *str, int v, int s)
{
  int	l;
  int	i;

  i = 0;
  l = 0;
  while (i < v)
    tab[0][l++] = str[i++];
  l = 0;
  while (str[i] == ' ' || str[i] == '\t')
    {
      s++;
      i++;
    }
  while (i < (s + v))
    tab[1][l++] = str[i++];
  l = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    tab[2][l++] = str[i++];
  return (tab);
}

char	**init_more_tab(char *cmd, char **tab, int *val)
{
  if (my_count_with_sep(val[1] , cmd) != 0)
    {
      if ((tab[val[0]] = malloc(sizeof(*tab) * (val[2] + 1))) == NULL)
	return (NULL);
      tab[val[0]++][val[2]] = '\0';
      if ((tab[val[0]] = malloc(sizeof(*tab) *
			   (my_strlen(cmd) - (val[1] + val[2]) + 1))) == NULL)
	return (NULL);
      tab[val[0]++][(val[1] + val[2])] = '\0';
      if ((tab = my_remp_tab(tab, cmd, val[1], val[2])) == NULL)
	return (NULL);
    }
  else
    {
      val[0]--;
      if ((tab[val[0]] = my_strcpy(tab[val[0]], cmd)) == NULL)
	return (NULL);
      val[0]++;
    }
  return (tab);
}

char	**pars_redirection(char	*cmd)
{
  char	**tab;
  int	*val;

  if ((val = malloc(sizeof(*val) * 3)) == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(**tab) * 4)) == NULL)
    return (NULL);
  val[0] = 0;
  val[1] = my_count_sep(cmd);
  val[2] = my_count_with_sep(val[1], cmd);
  if ((tab[val[0]] = malloc(sizeof(*tab) * (my_count_sep(cmd)))) == NULL)
    return (NULL);
  tab[val[0]++][val[1]] = '\0';
  init_more_tab(cmd, tab, val);
  tab[val[0]] == NULL;
  free(val);
  return (tab);
}
