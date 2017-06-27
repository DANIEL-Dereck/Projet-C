/*
** main.c for main in /home/guenol_v/rendu/lemin
**
** Made by guenol_v
** Login   <guenol_v@epitech.net>
**
** Started on  Sun May  4 14:28:59 2014 guenol_v
** Last update Sun May  4 23:24:44 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "lem_in.h"

char	**my_algo(t_node *node)
{
  int	a;
  int	b;
  char	**algo;

  a = 0;
  b = 0;
  while (node[a].nom != NULL)
    a++;
  if ((algo = malloc(sizeof(*algo) * a + 1)) == NULL)
    return (0);
  algo[a + 1] = NULL;
  while (node[b].nom != NULL)
    {
      if ((algo[b] = malloc(sizeof(**algo) * a + 1)) == NULL)
	return (0);
      algo[b][a + 1] = '\0';
    }
  return (algo);
}

int	my_trait_end(t_node *node)
{
  int	a;

  a = 0;
  while (node[a].nom != NULL)
    {
      if (node[a].order == 2)
	return (a);
      a++;
    }
  return (a);
}

int	my_trait_start(t_node *node)
{
  int	a;

  a = 0;
  while (node[a].nom != NULL)
    {
      if (node[a].order == 1)
	return (a);
      a++;
    }
  return (a);
}

int	my_calc_dist(t_node *node)
{
  int	a;
  int	b;
  t_node info;
  t_node autre;

  a = 0;
  b = 0;
  while (node[a].nom != NULL)
    {
      info = node[a];
      while (info.pipe[b] != 0)
	{
	  if (info.pipe[b] == 1)
	    {
	      autre = node[b];
	      info.dist[b] = sqrt(pow(2, info.x - autre.x)
				  + pow(2, info.y - autre.y));
	    }
	  b++;
	}
      a++;
    }
  return (0);
}

int	my_main_algo(t_node *node)
{
  my_calc_dist(node);
  my_trait_start(node);
  my_trait_end(node);
  my_algo(node);
  return (0);
}
