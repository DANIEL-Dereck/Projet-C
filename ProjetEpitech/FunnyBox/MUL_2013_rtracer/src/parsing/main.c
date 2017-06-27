/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sun Jun  8 21:11:51 2014 daniel_d
*/

#include "ray.h"

int	my_exec_rt(char **av)
{
  int	pid;
  int	i;

  i = 1;
  if (parsing(av[i]) == -1)
    return (-1);
  return (0);
  while (av[i] != NULL)
    {
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  if (parsing(av[i]) == -1)
	    return (-1);
	  exit(0);
	}
      i++;
    }
  return (0);
}

void	usage(char *str)
{
  my_printf("USAGE : %s [map.xml]\n", str, str);
}

int	main(int ac, char **av)
{
  if (ac <= 1)
    {
      usage(av[0]);
      return (0);
    }
  else
    return (my_exec_rt(av));
  return (0);
}
