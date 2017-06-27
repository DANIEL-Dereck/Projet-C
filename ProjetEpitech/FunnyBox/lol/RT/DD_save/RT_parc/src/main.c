/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sat May 31 16:34:35 2014 daniel_d
*/

#include "rt_pars.h"
#include "my.h"

void	usage(char *str)
{
  my_printf("USAGE : %s [map.xml]\n", str);
}

int	main(int ac, char **av)
{
  if (ac <= 1)
    {
      usage(av[0]);
      return (0);
    }
  if (parsing(av[1]) == -1)
    return (-1);
  return (0);
}
