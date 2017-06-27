/*
** main.c for minitalk in /home/daniel_d/rendu/PSU_2013_minitalk/src/client
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 10 10:38:45 2014 daniel_d
** Last update Mon Mar 10 15:21:38 2014 daniel_d
*/

#include "serveur.h"
#include "my.h"

int	main(int ac, char **av)
{
  if (ac != 1)
    {
      my_printf("Usage : %s\n", av[0]);
      return (0);
    }
  my_serv();
  return (0);
}
