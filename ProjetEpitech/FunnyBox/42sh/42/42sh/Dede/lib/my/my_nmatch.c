/*
** my_nmatch.c for nmatch in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr 22 15:36:12 2014 daniel_d
** Last update Mon May 19 10:23:47 2014 bouchard alexandre
*/

#include <stdio.h>
#include "my.h"

int	my_nmatch_bis(char *s1, char *s2, int pos)
{
  int	i;

  i = -1;
  while (++i <= pos && (s1[i] != '\0' && s2[i] != '\0'))
    {
      if (s1[i] != s2[i])
	return (-1);
    }
  return (0);
}

int	my_nmatch(char *s1, char *s2, int pos)
{
  int	len1;
  int	len2;
  int	result;

  result = 0;
  if (pos <= 0 || s1 == NULL || s2 == NULL)
    return (-1);
  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if (len2 >= len1)
    result = my_nmatch_bis(s1, s2, pos);
  else
    return (-1);
  return (result);
}
