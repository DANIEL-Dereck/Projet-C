/*
** look_magic_number.c for rush in /home/cordon_b/rendu/rush2/Epic_js_fantasy/srcs/Parse_Map
** 
** Made by cordon_b
** Login   <cordon_b@epitech.net>
** 
** Started on  Sat May 10 11:12:33 2014 cordon_b
** Last update Sat May 10 11:18:06 2014 cordon_b
*/

#include "rush.h"

int	look_magic_number(t_global *global, char *str)
{
  int	nbr;

  nbr = atoi(str);
  if (nbr != 123)
    {
      fprintf(stderr, "MAGIC NUMBER WRONG \n");
      return (EXIT_FAILURE);
    }
  if ((global->header = malloc(sizeof(*global->header))) == NULL)
    {
      fprintf(stderr, "FAILURE MALLOC \n");
      return (EXIT_FAILURE);
    }
  global->header->magic_number = nbr;
  return (EXIT_SUCCESS);
}
