/*
** alumcounteur.c for alum1 in /home/daniel_d/rendu/alum1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Feb 13 14:35:01 2014 daniel_d
** Last update Sun Feb 16 16:04:11 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum.h"

int	aff_tab(char **sapin, int nl)
{
  int	k;
  int	i;
  int	c;

  k = nl - 1;
  i = 0;
  c = 0;
  while (i < nl)
    {
      while (c < k)
	{
	  my_putchar(' ');
	  c++;
	}
      k--;
      c = 0;
      my_printf("%s\n", sapin[i++]);
    }
  my_printf("Pipes: %d/%d\n", pipecount(sapin, nl), pipercount(sapin, nl));
  return (0);
}

int     pipercount(char **tab, int nl)
{
  int   piper;
  int   i;
  int   j;

  i = 0;
  j = 0;
  piper = 0;
  while (i < nl)
    {
      j = my_strlen(tab[i]);
      piper = piper + j - 1;
      i++;
    }
  return (piper);
}

int	pipecount(char **tab, int nl)
{
  int	pipe;
  int	i;
  int	j;

  i = 0;
  j = 0;
  pipe = 0;
  while (i < nl)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == '|')
	    pipe = pipe + 1;
	  j++;
	}
      j = 0;
      i++;
    }
  return (pipe);
}
