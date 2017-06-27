/*
** alumain.c for  in /home/daniel_d/rendu/alum1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Feb 10 13:32:56 2014 daniel_d
** Last update Sun Feb 16 16:39:18 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "alum.h"

int	ligneforplay()
{
  char	*buffer;
  int	r;
  int	line;

  line = 0;
  while (42)
    {
      if ((buffer = malloc(sizeof(buffer) * 4096)) == NULL)
	return (0);
      my_printf("Number of ligne please (5 <= 50)?\n");
      if ((r = read(0, buffer, 4096)) != -1)
	{
	  line = my_getnbr(buffer);
	  if (line >= 5 && line <= 50)
	    return (line);
	  else
	    my_printf("please insert a valid number\n");
	  free(buffer);
	}
      else
	return (0);
    }
  return (0);
}

int	playerselect()
{
  char	*buffer;
  int	r;

  r = 0;
  while (42)
    {
      if ((buffer = malloc(sizeof(buffer) *4096)) == NULL)
	return (0);
      my_printf("You play with your friend 'F' or my IA 'I'\n");
      if ((r = read(0, buffer, 4096)) != -1)
	{
	  if (buffer[0] == 'F' && buffer[1] == '\n')
	    return (1);
	  else if (buffer[0] == 'I' && buffer[1] == '\n')
	    return (2);
	  else
	    my_printf("Select good player please\n");
	  free(buffer);
	}
      else
	return (0);
    }
  return (0);
}

int	alumain()
{
  char	**tab;
  int	t;
  int	line;

  t = playerselect();
  if (t == 1)
    {
      line = ligneforplay();
      my_printf("mode : player versus player | ligne: %d\n", line);
      tab = sapin(line);
      jcj(tab, line);
    }
  else if (t == 2)
    {
      line = ligneforplay();
      my_printf("mode : player vs IA | ligne: %d\n", line);
      tab = sapin(line);
      ia(tab, line);
    }
  else
    {
      my_printf("ERROR: you have select bad player\n");
      return (0);
    }
  return (0);
}
