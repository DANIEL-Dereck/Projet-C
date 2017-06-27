/*
** main.c for minitalk in /home/daniel_d/rendu/PSU_2013_minitalk/src/client
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 10 10:38:45 2014 daniel_d
** Last update Tue Mar 18 16:44:23 2014 daniel_d
*/

#include "client.h"
#include "my.h"

int	main(int ac, char **av)
{
  int	pid;

  if (ac != 3)
    {
      my_printf("Usage : %s [pid serveur] [str]\n", av[0]);
      return (0);
    }
  pid = my_getnbr(av[1]);
  client_tel(pid, av[2]);
  return (0);
}
