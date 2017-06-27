/*
** my_kill.c for kill in /home/daniel_d/rendu/PSU_2013_minitalk/test
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Mar 20 14:33:27 2014 daniel_d
** Last update Thu Mar 20 14:34:33 2014 daniel_d
*/

#include <sys/types.h>
#include <signal.h>

int	main(int ac, char **av)
{
  int	pid;

  pid = atoi(av[1]);
  kill(pid, SIGUSR1);
}
