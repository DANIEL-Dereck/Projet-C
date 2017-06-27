/*
** my_serv.c for serv in /home/daniel_d/rendu/PSU_2013_minitalk/src/serveur
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 10 15:14:00 2014 daniel_d
** Last update Fri Mar 21 12:06:06 2014 daniel_d
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "serveur.h"
#include "my.h"

int	n;

void	my_putvalue(int c)
{
  write(1, &c, 1);
}

void  	catch_sigusr1()
{
  n++;
}

void  	catch_sigusr2()
{
  int	pid;

  pid = getpid();
  my_putvalue(n);
  if (n == 0)
    my_printf("\n\t -------------- pid = %d -----------------\n", pid);
  n = 0;
}

int	my_serv()
{
  int	pid;

  n = 0;
  pid = getpid();
  my_printf("\t| -- pid = %d -- |\n", pid);
  while (42)
    {
      if (signal(SIGUSR1, catch_sigusr1) == SIG_ERR)
	return (-1);
      usleep(WAITIMEOUT);
      if (signal(SIGUSR2, catch_sigusr2) == SIG_ERR)
	return (-1);
      usleep(WAITIMEOUT);
    }
  return (0);
}
