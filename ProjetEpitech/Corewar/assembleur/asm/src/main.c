/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Wed Apr  2 11:27:51 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

int main(int ac, char **av)
{
  int	a;

  a = 1;
  if (ac <= 1)
    {
      my_printf("Usage : %s [name.s]\n", av[0]);
      return (0);
    }
  while (av[a] != NULL)
    if (assembleur_main(av[a++]) == ERROR1)
      {
	my_printf("ERROR : Bad file\n");
	return (ERROR1);
      }
  return (0);
}
