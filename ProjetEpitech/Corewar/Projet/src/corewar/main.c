/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Wed Apr  2 11:55:39 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "corewar.h"

void	my_usage(char **av)
{
  my_printf("Usage : %s [Champion-1.cor] [...] [Champion-4.cor]\n", av[0]);
}

int main(int ac, char **av)
{
  int	i;

  i = 1;
  if (ac == 1)
    {
      my_usage(av);
      return (FAIL);
    }
  else if (ac > 5)
    {
      my_printf("Too many champion : Max is 4\n");
      return (FAIL);
    }
  while (av[i] != NULL)
    {
      if (verif_champion(av[i]) == FAIL)
	return (FAIL);
      i++;
    }
  vm_main(av);
  return (0);
}
