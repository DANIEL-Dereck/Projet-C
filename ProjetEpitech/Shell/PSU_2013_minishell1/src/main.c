/*
** main.c for get_ next_line_main_test in
**
** Made by tek assistant
** Login <astek@epitech.net> Programmation élémentaire get_next_line
**
** Started on Mon Nov 5 14:59:09 2001 tek assistant
** Last update Mon Jan  6 18:43:46 2014 daniel_d
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

int main(int ac, char **av, char **envp)
{
  if (envp[0] == NULL)
    {
      my_printf("ERROR : no environement\n");
      return (0);
    }
  if (ac != 1)
    {
      my_printf("ERROR : too many arguments\n");
      my_printf("Usage : %s\n", av[0]);
      return (0);
    }
  my_prompt(envp);
  return (0);
}
