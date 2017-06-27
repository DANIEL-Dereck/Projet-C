/*
** client.c for client in /home/daniel_d/rendu/PSU_2013_minitalk/src/client
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 10 10:47:39 2014 daniel_d
** Last update Wed Mar 19 13:42:32 2014 daniel_d
*/

#include <unistd.h>
#include <signal.h>
#include "client.h"
#include "my.h"

int	client_tel(int	pid, char *str)
{
  int	l;
  int	i;

  i = 0;
  l = 0;
  while (str[i] != '\0')
    {
      l = str[i];
      while (l > 0)
	{
	  kill(pid, SIGUSR1);
     	  l--;
	  usleep(WAITIME);
	}
      i++;
      kill(pid, SIGUSR2);
      usleep(WAITIME);
    }
  kill(pid, SIGUSR2);
  return (0);
}
