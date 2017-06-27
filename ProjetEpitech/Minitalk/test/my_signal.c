/*
** my_signal.c for signal in /home/daniel_d/rendu/PSU_2013_minitalk/test
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Mar 20 14:35:02 2014 daniel_d
** Last update Thu Mar 20 14:37:34 2014 daniel_d
*/

#include <signal.h>
#include <stdio.h>

void	catch_signal()
{
  printf("ok\n");
}

int	main()
{
  printf("%d\n", getpid());
  while (42)
    signal(SIGUSR1, catch_signal);
}
