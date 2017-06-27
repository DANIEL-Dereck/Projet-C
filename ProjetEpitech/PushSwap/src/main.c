/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Mon Jan  6 22:28:20 2014 daniel_d
*/

#include "../Lib/include/my.h"

int main(int ac, char **av)
{
  if (ac <= 1)
    {
      my_printf("usage : %s [number] ...\n", av[0]);
      return (0);
    }
  my_pushswap(av);
  return (0);
}
