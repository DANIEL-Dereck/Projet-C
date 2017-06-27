/*
** my_signal.c for minishell in /home/daniel_d/rendu/PSU_2013_minishell1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jan  6 09:25:19 2014 daniel_d
** Last update Sun May 25 22:36:23 2014 daniel_d
*/

#include "../include/sh.h"

void	get_sigall()
{
}

int	signal_set()
{
  signal(SIGQUIT, get_sigall);
  signal(SIGINT, get_sigall);
  signal(SIGTSTP, get_sigall);
  signal(SIGUSR1, get_sigall);
  signal(SIGUSR2, get_sigall);
  signal(SIGKILL, get_sigall);
  return (0);
}
