/*
** fill_header.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 11:19:49 2014 cordon_b
** Last update Sun May 11 00:32:22 2014 cordon_b
*/

#include "rush.h"

int	fill_header(t_global *global, char *str)
{
  char	**tab;

  if ((tab = str_to_wordtab(str, ' ')) == NULL)
    return (EXIT_FAILURE);
  if (tab[1] && tab[3] && tab[5])
    {
      global->header->name = strdup(tab[1]);
      global->header->start = strdup(tab[3]);
      global->header->end = strdup(tab[5]);
    }
  else
    {
      fprintf(stderr, "Bad Param Header \n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
