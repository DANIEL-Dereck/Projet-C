/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sat Jan 11 10:49:20 2014 daniel_d
*/

#include "mlx.h"
#include "mlx_int.h"
#include "wolf.h"
#include "my.h"

int main(int ac, char **av)
{
  if (ac != 2)
    {
      my_printf("Usage : %s [map].wolf\n", av[0]);
      return (0);
    }
  my_wolf();
  return (0);
}
