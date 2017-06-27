/*
** alumbrain.c for allum1 in /home/daniel_d/rendu/Allum1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Feb 16 21:47:00 2014 daniel_d
** Last update Sun Feb 16 22:31:36 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum.h"

char	**iabrain(char **sapin, int nl)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i <= nl)
    {
      while (sapin[i][j] != '\0')
	{
	  if (sapin[i][j] == '|')
	    {
	      sapin[i][j] = '.';
	      return (sapin);
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  return (sapin);
}
