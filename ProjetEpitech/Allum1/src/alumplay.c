/*
** alumplay.c for alum1 in /home/daniel_d/rendu/alum1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Feb 10 16:35:06 2014 daniel_d
** Last update Sun Feb 16 22:44:17 2014 daniel_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum.h"

char	**sapin(int nl)
{
  char	**sapin;
  int	i;
  int	maxi;
  int	p;

  p = 0;
  i = 0;
  maxi = 1;
  if ((sapin = malloc(sizeof(sapin) * (nl - 1))) == NULL)
    return (0);
  sapin[nl + 1] = NULL;
  while (nl > 0)
    {
      if ((sapin[p] = malloc(sizeof(sapin) * (maxi + 1))) == NULL)
	return (0);
      sapin[p][maxi] = '\0';
      while (i < maxi)
	sapin[p][i++] = '|';
      maxi += 2;
      i = 0;
      p++;
      nl--;
    }
  return (sapin);
}

int	verif(char **sapin, int nl, int j, char *buffer)
{
  int	k;

  sapin = jcj_play(sapin, buffer, nl);
  k = pipecount(sapin, nl);
  if (k == 1)
    {
      my_printf("Player %d WIN\n", j);
      return (4);
    }
  else if (k == 0)
    {
      if (j == 1)
	j++;
      else
	j--;
      my_printf("Player %d WIN\n", j);
      return (4);
    }
  if (j == 1)
    j++;
  else
    j--;
  return (j);
}

int     ia_verif(char **sapin, int nl, int j, char *buffer)
{
  int   k;

  sapin = ia_play(sapin, buffer, nl);
  k = pipecount(sapin, nl);
  if (k == 1)
    {
      my_printf("Player WIN\n", j);
      return (4);
    }
  else if (k == 0)
    {
      if (j == 1)
        j++;
      else
        j--;
      my_printf("IA WIN\n", j);
      return (4);
    }
  if (j == 1)
    j++;
  else
    j--;
  return (j);
}

int	jcj(char **sapin, int nl)
{
  int	i;
  int	j;
  char	buffer[4096];

  j = 1;
  while (42)
    {
      aff_tab(sapin, nl);
      my_printf("Player %d: [ligne] [stick]\n", j);
      if ((i = read(0, buffer, 4096)) == -1)
	return (0);
      if (buffer[0] != '\n' && buffer[0] != ' ')
	{
	  j = verif(sapin, nl, j, buffer);
	  if (j == 4)
	    return (0);
	}
    }
  return (0);
}

int	ia(char **sapin, int nl)
{
  int   i;
  int   j;
  char  buffer[4096];

  j = 1;
  while (42)
    {
      aff_tab(sapin, nl);
      my_printf("Player: [ligne] [stick]\n");
      if ((i = read(0, buffer, 4096)) == -1)
        return (0);
      if (buffer[0] != '\n' && buffer[0] != ' ')
        {
          j = ia_verif(sapin, nl, j, buffer);
          if (j == 4)
            return (0);
	  aff_tab(sapin, nl);
	  my_printf("IA: [ligne] [stick]\n");
	  sapin = iabrain(sapin, nl);
	  j = ia_verif(sapin, nl, j, buffer);
	  if (j == 4)
            return (0);
        }
    }
  return (0);
}
