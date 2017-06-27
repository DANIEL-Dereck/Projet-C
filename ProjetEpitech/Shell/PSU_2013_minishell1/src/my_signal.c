/*
** my_signal.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jan  6 09:25:19 2014 daniel_d
** Last update Mon Jan  6 21:52:33 2014 daniel_d
*/

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include "../Lib/include/my.h"
#include "../Lib/include/my_minishell.h"

void	get_sigall()
{
  my_printf("Signal");
}

void	signal_set()
{
  signal(SIGQUIT, get_sigall);
  signal(SIGINT, get_sigall);
  signal(SIGTSTP, get_sigall);
  signal(SIGUSR1, get_sigall);
  signal(SIGUSR2, get_sigall);
}
