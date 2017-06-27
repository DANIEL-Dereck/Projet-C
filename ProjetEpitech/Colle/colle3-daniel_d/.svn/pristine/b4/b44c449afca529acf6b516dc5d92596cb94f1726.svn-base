/*
** main.c for test_count in /home/even_d/rendu/colle3-daniel_d/src
**
** Made by even_d
** Login   <even_d@epitech.net>
**
** Started on  Thu May 15 19:13:00 2014 even_d
** Last update Thu May 15 22:38:56 2014 even_d
*/

#include <stdlib.h>

#include "text.h"

int	main(int ac, char **av)
{
  t_core	core;

  if (ac == 2)
    part_one(av[1]);
  if (ac == 3)
    part_two(av[1], av[2]);
  if (ac == 4)
    {
      core = check_option(av, ac);
      if (core.av1 == NULL || core.av2 == NULL
	  || core.av1 == '\0' || core.av2[0] == '\0')
	return (EXIT_FAILURE);
      part_three(&core);
    }

  return (EXIT_SUCCESS);
}
