/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sat Jun  7 20:57:13 2014 daniel_d
*/

#include "ray.h"

void	usage(char *str)
{
  my_printf("USAGE : %s [map.xml]\n", str);
}

int	main(int ac, char **av)
{
  int	pid;
  int	i;

  i = 1;
  if (ac <= 1)
    {
      usage(av[0]);
      return (0);
    }
  while (av[i] != NULL)
    {
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  if (parsing(av[i]) == -1)
	    return (-1);
	}
      else
	kill(0);
      i++;
    }
  return (0);
}
