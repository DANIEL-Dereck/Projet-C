/*
** big_func.c for big_func in /home/besnie_b/Lem_in
**
** Made by besnie_b
** Login   <besnie_b@epitech.net>
**
** Started on  Sun May  4 22:15:45 2014 besnie_b
** Last update Sun May  4 22:28:07 2014 besnie_b
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lem_in.h"

int     it_is_room(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[i] != 0)
    {
      if ((str[i] != ' ' && str[i] != '\t')
          && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == 0))
        n++;
      i++;
    }
  if (n == 3)
    return (1);
  return (0);
}

t_node  *my_node_tab(char **tab)
{
  t_node *tmp;
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '#')
        i++;
      else if (it_is_room(tab[i]) == 1)
        {
          i++;
          n++;
        }
      else
        i++;
    }
  if ((tmp = malloc(sizeof(*tmp) * (n + 1))) == NULL)
    return (NULL);
  return (tmp);
}

t_node  *my_info_in_node(char **tab, t_node *node)
{
  int   i;
  int   k;

  i = 0;
  k = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '#')
        {
          if (my_com(tab[i]) == 1)
            node[k].order = 1;
          else if (my_com(tab[i]) == 2)
            node[k].order = 2;
          i++;
        }
      else if (it_is_room(tab[i]) == 1)
        {
          node_become_room(tab[i], &node[k]);
          i++;
          k++;
        }
      else
        i++;
    }
  return (node);
}

t_node  *prepared_pipes(t_node *node)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (node[i++].nom != NULL)
    nb++;
  i = 0;
  while (node[i].nom != NULL)
    {
      if ((node[i].pipe = malloc(sizeof(*node[i].pipe) * (nb + 1))) == NULL)
        return (NULL);
      if ((node[i].dist = malloc(sizeof(*node[i].dist) * (nb + 1))) == NULL)
        return (NULL);
      init_str(node[i].pipe, nb);
      init_str(node[i].dist, nb);
      i++;
    }
  return (node);
}

void	my_pipe_conf(char **tab)
{
  int   i;

  i = 1;
  while (tab[i] != NULL && (it_is_room(tab[i]) == 1 || tab[i][0] == '#'))
    i++;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '#')
        i++;
      else
        {
          i++;
        }
    }
}
