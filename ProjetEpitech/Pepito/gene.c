/*
** gene.c for gener in /home/daniel_d/rendu/Pepito
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Apr 17 13:56:49 2014 daniel_d
** Last update Thu Apr 17 14:00:37 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
  int	gen;
  char	c;
  char	a;

  c = '*';
  a = '\n';
  if (ac <= 1)
    return (0);
  gen = atoi(av[1]);
  while (gen >= 0)
    {
      write(1, &c, 1);
      gen--;
    }
  write(1, &a, 1);
  return (0);
}
