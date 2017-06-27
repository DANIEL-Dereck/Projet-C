/*
** my_epur_str.c for epur_str in /home/daniel_d/rendu/PSU_2013_minishell2/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Mar  5 10:24:15 2014 daniel_d
** Last update Wed Mar  5 10:56:09 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*my_epur_str(char	*str)
{
  char	*dest;
  int	k;
  int	i;

  k = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  if ((dest = malloc(sizeof(dest) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if (k != 0 && str[i + 1] != '\0')
	    dest[k++] = ' ';
	}
      if (str[i] != ' ' || str[i] != '\t')
	dest[k++] = str[i++];
      i++;
    }
  dest[k] = '\0';
  return (dest);
}
