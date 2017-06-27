/*
** my_epur_str.c for epur_str in /home/daniel_d/rendu/PSU_2013_minishell2/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Mar  5 10:24:15 2014 daniel_d
** Last update Sun Mar  9 17:31:39 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	my_strcharlen(char *str)
{
  int	a;
  int	l;

  a = 0;
  l = 0;
  while (str[a] != '\0' && str[a] != '\n')
    {
      if (str[a] != ' ' && str[a] != '\t')
	l++;
      a++;
    }
  return (l);
}

char	*my_verif(char *str)
{
  int	k;

  k = 0;
  if (str == NULL)
    return (NULL);
  if ((k = my_strcharlen(str)) == 0)
    return (NULL);
  return (str);
}

char	*my_epur_str(char *str)
{
  char	*dest;
  int	k;
  int	i;

  if ((str = my_verif(str)) == NULL)
    return (NULL);
  k = 0;
  i = 0;
  if ((dest = malloc(sizeof(dest) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if ((k != 0 && str[i + 1] != '\0'))
	    dest[k++] = ' ';
	}
      if (str[i] != ' ' || str[i] != '\t')
	dest[k++] = str[i];
      i++;
    }
  dest[++k] = '\0';
  return (dest);
}
